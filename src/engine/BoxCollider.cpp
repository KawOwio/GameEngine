#include "BoxCollider.h"
#include "StaticModelCollider.h"
#include "Transform.h"
#include "Entity.h"

namespace engine
{
	void BoxCollider::onInit()
	{
		size = rend::vec3(1.0f, 1.0f, 1.0f);
		lastPosition = getTransform()->getPosition();
	}

	void BoxCollider::onTick()
	{
		collideBox();
		collideStaticMesh();
	}

	void BoxCollider::setSize(rend::vec3 _size)
	{
		size = _size;
	}

	void BoxCollider::setOffset(rend::vec3 _offset)
	{
		offset = _offset;
	}

	void BoxCollider::collideBox()
	{
		//Box collider entity system
		std::vector<std::shared_ptr<Entity>> bces;

		std::vector<std::shared_ptr<Entity>> tempEntities = getCore()->getEntities();

		for (auto it = tempEntities.begin(); it != tempEntities.end(); it++)
		{
			if ((*it)->checkComponent<BoxCollider>() == true)
			{
				bces.push_back(*it);
				//std::shared_ptr<BoxCollider> bc = (*it)->getComponent<BoxCollider>();
				//bc->getEntity()->getComponent<BoxCollider>();
			}
		}

		rend::vec3 np = getTransform()->getPosition() + offset;

		for (auto it = bces.begin(); it != bces.end(); it++)
		{
			if (*it == getEntity())
			{
				continue;
			}

			std::shared_ptr<BoxCollider> bc = (*it)->getComponent<BoxCollider>();

			//if (!isTrigger)
			//{

			//}
			rend::vec3 sp = bc->getCollisionResponse(np, size);
			np = sp;
			np = np - offset;
			getTransform()->setPosition(np);
			lastPosition = np;
		}
	}

	void BoxCollider::collideStaticMesh()
	{
		////Static model colloder entity system
		//std::vector<std::shared_ptr<Entity>> smces;

		//getEntity()->getComponent<StaticModelCollider>(smces);

		//rend::vec3 np = getTransform()->getPosition() + offset;

		//for (auto it = smces.begin(); it != smces.end(); it++)
		//{
		//	std::shared_ptr<StaticModelCollider> smc = (*it)->getComponent<StaticModelCollider>();

		//	bool solved = false;
		//	rend::vec3 sp = smc->getCollisionResponse(np, size, solved);

		//	if (solved)
		//	{
		//		np = sp;
		//	}
		//	else
		//	{
		//		np = lastPosition + offset;
		//	}

		//	np = np - offset;
		//	getTransform()->setPosition(np);
		//	lastPosition = np;
		//}
	}

	bool BoxCollider::isColliding(rend::vec3 _position, rend::vec3 _size)
	{
		rend::vec3 a = getTransform()->getPosition() + offset;
		rend::vec3 &as = this->size;
		rend::vec3 &b = _position;
		rend::vec3 &bs = _size;

		if (a.x > b.x)	// a is right of b
		{
			if (a.x - as.x > b.x + bs.x)	//left edge of a is > that right edge of b (NC)
			{
				return false;
			}
		}
		else
		{
			if (b.x - bs.x > a.x + as.x)
			{
				return false;
			}
		}

		if (a.z > b.z) // a front of b
		{
			if (a.z - as.z > b.z + bs.z) // back edge of a > than front edge of b (NC)
			{
				return false;
			}
		}
		else
		{
			if (b.z - bs.z > a.z + as.z)
			{
				return false;
			}
		}

		if (a.y > b.y) // a above b
		{
			if (a.y - as.y > b.y + bs.y) // bottom edge of a > than top edge of b (NC)
			{
				return false;
			}
		}
		else
		{
			if (b.y - bs.y > a.y + as.y)
			{
				return false;
			}
		}

		return true;

		return 1;
	}

	rend::vec3 BoxCollider::getCollisionResponse(rend::vec3 _position, rend::vec3 _size)
	{
		float amount = 0.1f;
		float step = 0.1f;

		while (true)
		{
			if (!isColliding(_position, _size)) break;
			_position.x += amount;
			if (!isColliding(_position, _size)) break;
			_position.x -= amount; 
			_position.x -= amount;
			if (!isColliding(_position, _size)) break;
			_position.x += amount;
			_position.z += amount;
			if (!isColliding(_position, _size)) break;
			_position.z -= amount;
			_position.z -= amount;
			if (!isColliding(_position, _size)) break;
			_position.z += amount;
			_position.y += amount;
			if (!isColliding(_position, _size)) break;
			_position.y -= amount;
			_position.y -= amount;
			if (!isColliding(_position, _size)) break;
			_position.y += amount;
			amount += step;
		}

		return _position;
	}
}
