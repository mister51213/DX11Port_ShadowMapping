////////////////////////////////////////////////////////////////////////////////
// Filename: positionclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "positionclass.h"


PositionClass::PositionClass()
{
	m_positionX = 0.0f;
	m_positionY = 0.0f;
	m_positionZ = 0.0f;
	
	m_rotationX = 0.0f;
	m_rotationY = 0.0f;
	m_rotationZ = 0.0f;

	m_frameTime = 0.0f;

	m_forwardSpeed   = 0.0f;
	m_backwardSpeed  = 0.0f;
	m_upwardSpeed    = 0.0f;
	m_downwardSpeed  = 0.0f;
	m_leftTurnSpeed  = 0.0f;
	m_rightTurnSpeed = 0.0f;
	m_lookUpSpeed    = 0.0f;
	m_lookDownSpeed  = 0.0f;
}


PositionClass::PositionClass(const PositionClass& other)
{
}


PositionClass::~PositionClass()
{
}


void PositionClass::SetPosition(float x, float y, float z)
{
	m_positionX = x;
	m_positionY = y;
	m_positionZ = z;
	return;
}


void PositionClass::SetRotation(float x, float y, float z)
{
	m_rotationX = x;
	m_rotationY = y;
	m_rotationZ = z;
	return;
}


void PositionClass::GetPosition(float& x, float& y, float& z)
{
	x = m_positionX;
	y = m_positionY;
	z = m_positionZ;
	return;
}


void PositionClass::GetRotation(float& x, float& y, float& z)
{
	x = m_rotationX;
	y = m_rotationY;
	z = m_rotationZ;
	return;
}


void PositionClass::SetFrameTime(float time)
{
	m_frameTime = time;
	return;
}


void PositionClass::MoveForward(bool keydown)
{
	// MOVE FORWARD RELATIVE //
	if (keydown)
	{
		_fwdSpeed += _moveInc*m_frameTime;
	}
	else
	{
		_fwdSpeed -= _moveInc*m_frameTime;

		if (_fwdSpeed < 0)
		{
			_fwdSpeed = 0;
		}
	}

	// Get move direction
	XMFLOAT3 fwd(0.f, 0.f, 1.f);
	XMVECTOR directionRelative = XMLoadFloat3(&fwd);
	XMVECTOR directionWorld = XMVector3TransformCoord(
		directionRelative, 
		DirectX::XMMatrixRotationRollPitchYaw(	m_rotationZ*0.0174532925f,
												m_rotationX*0.0174532925f,
												m_rotationY*0.0174532925f));

	// Multiply to create move increment
	XMFLOAT3 worldDispFloat3;	
	XMStoreFloat3(&worldDispFloat3, directionWorld);
	worldDispFloat3.x *= _fwdSpeed;
	worldDispFloat3.y *= _fwdSpeed;
	worldDispFloat3.z *= _fwdSpeed;

	// Add increment to position
	m_positionX += worldDispFloat3.x;
	m_positionY += worldDispFloat3.y;
	m_positionZ += worldDispFloat3.z;

	return;
}


void PositionClass::MoveBackward(bool keydown)
{
		// MOVE FORWARD RELATIVE //
		if (keydown)
		{
			_fwdSpeed += _moveInc*m_frameTime;
		}
		else
		{
			_fwdSpeed -= _moveInc*m_frameTime;

			if (_fwdSpeed < 0)
			{
				_fwdSpeed = 0;
			}
		}

		// Get move direction
		XMFLOAT3 fwd(0.f, 0.f, 1.f);
		XMVECTOR directionRelative = XMLoadFloat3(&fwd);
		XMVECTOR directionWorld = XMVector3TransformCoord(
			directionRelative,
			DirectX::XMMatrixRotationRollPitchYaw(m_rotationZ*0.0174532925f,
				m_rotationX*0.0174532925f,
				m_rotationY*0.0174532925f));

		// Multiply to create move increment
		XMFLOAT3 worldDispFloat3;
		XMStoreFloat3(&worldDispFloat3, directionWorld);
		worldDispFloat3.x *= _fwdSpeed;
		worldDispFloat3.y *= _fwdSpeed;
		worldDispFloat3.z *= _fwdSpeed;

		// Add increment to position
		m_positionX -= worldDispFloat3.x;
		m_positionY -= worldDispFloat3.y;
		m_positionZ -= worldDispFloat3.z;

		return;
}


void PositionClass::MoveLeft(bool keydown)
{
	// MOVE FORWARD RELATIVE //
	if (keydown)
	{
		_fwdSpeed += _moveInc*m_frameTime;
	}
	else
	{
		_fwdSpeed -= _moveInc*m_frameTime;

		if (_fwdSpeed < 0)
		{
			_fwdSpeed = 0;
		}
	}

	// Get move direction
	XMFLOAT3 fwd(1.f, 0.f,0.f);
	XMVECTOR directionRelative = XMLoadFloat3(&fwd);
	XMVECTOR directionWorld = XMVector3TransformCoord(
		directionRelative,
		DirectX::XMMatrixRotationRollPitchYaw(m_rotationZ*0.0174532925f,
			m_rotationX*0.0174532925f,
			m_rotationY*0.0174532925f));

	// Multiply to create move increment
	XMFLOAT3 worldDispFloat3;
	XMStoreFloat3(&worldDispFloat3, directionWorld);
	worldDispFloat3.x *= _fwdSpeed;
	worldDispFloat3.y *= _fwdSpeed;
	worldDispFloat3.z *= _fwdSpeed;

	// Add increment to position
	m_positionX -= worldDispFloat3.x;
	m_positionY -= worldDispFloat3.y;
	m_positionZ -= worldDispFloat3.z;

	return;
}

void PositionClass::MoveRight(bool keydown)
{
	// MOVE FORWARD RELATIVE //
	if (keydown)
	{
		_fwdSpeed += _moveInc*m_frameTime;
	}
	else
	{
		_fwdSpeed -= _moveInc*m_frameTime;

		if (_fwdSpeed < 0)
		{
			_fwdSpeed = 0;
		}
	}

	// Get move direction
	XMFLOAT3 fwd(1.f, 0.f, 0.f);
	XMVECTOR directionRelative = XMLoadFloat3(&fwd);
	XMVECTOR directionWorld = XMVector3TransformCoord(
		directionRelative,
		DirectX::XMMatrixRotationRollPitchYaw(m_rotationZ*0.0174532925f,
			m_rotationX*0.0174532925f,
			m_rotationY*0.0174532925f));

	// Multiply to create move increment
	XMFLOAT3 worldDispFloat3;
	XMStoreFloat3(&worldDispFloat3, directionWorld);
	worldDispFloat3.x *= _fwdSpeed;
	worldDispFloat3.y *= _fwdSpeed;
	worldDispFloat3.z *= _fwdSpeed;

	// Add increment to position
	m_positionX += worldDispFloat3.x;
	m_positionY += worldDispFloat3.y;
	m_positionZ += worldDispFloat3.z;

	return;
}

void PositionClass::MoveUpward(bool keydown)
{
	// Update the upward speed movement based on the frame time and whether the user is holding the key down or not.
	if(keydown)
	{
		m_upwardSpeed += m_frameTime * 0.003f;

		if(m_upwardSpeed > (m_frameTime * 0.03f))
		{
			m_upwardSpeed = m_frameTime * 0.03f;
		}
	}
	else
	{
		m_upwardSpeed -= m_frameTime * 0.002f;

		if(m_upwardSpeed < 0.0f)
		{
			m_upwardSpeed = 0.0f;
		}
	}

	// Update the height position.
	m_positionY += m_upwardSpeed;

	return;
}


void PositionClass::MoveDownward(bool keydown)
{
	// Update the downward speed movement based on the frame time and whether the user is holding the key down or not.
	if(keydown)
	{
		m_downwardSpeed += m_frameTime * 0.003f;

		if(m_downwardSpeed > (m_frameTime * 0.03f))
		{
			m_downwardSpeed = m_frameTime * 0.03f;
		}
	}
	else
	{
		m_downwardSpeed -= m_frameTime * 0.002f;

		if(m_downwardSpeed < 0.0f)
		{
			m_downwardSpeed = 0.0f;
		}
	}

	// Update the height position.
	m_positionY -= m_downwardSpeed;

	return;
}


void PositionClass::TurnLeft(bool keydown)
{
	// Update the left turn speed movement based on the frame time and whether the user is holding the key down or not.
	if(keydown)
	{
		m_leftTurnSpeed += m_frameTime * 0.01f;

		if(m_leftTurnSpeed > (m_frameTime * 0.15f))
		{
			m_leftTurnSpeed = m_frameTime * 0.15f;
		}
	}
	else
	{
		m_leftTurnSpeed -= m_frameTime* 0.005f;

		if(m_leftTurnSpeed < 0.0f)
		{
			m_leftTurnSpeed = 0.0f;
		}
	}

	// Update the rotation.
	m_rotationY -= m_leftTurnSpeed;

	// Keep the rotation in the 0 to 360 range.
	if(m_rotationY < 0.0f)
	{
		m_rotationY += 360.0f;
	}

	return;
}


void PositionClass::TurnRight(bool keydown)
{
	// Update the right turn speed movement based on the frame time and whether the user is holding the key down or not.
	if(keydown)
	{
		m_rightTurnSpeed += m_frameTime * 0.01f;

		if(m_rightTurnSpeed > (m_frameTime * 0.15f))
		{
			m_rightTurnSpeed = m_frameTime * 0.15f;
		}
	}
	else
	{
		m_rightTurnSpeed -= m_frameTime* 0.005f;

		if(m_rightTurnSpeed < 0.0f)
		{
			m_rightTurnSpeed = 0.0f;
		}
	}

	// Update the rotation.
	m_rotationY += m_rightTurnSpeed;

	// Keep the rotation in the 0 to 360 range.
	if(m_rotationY > 360.0f)
	{
		m_rotationY -= 360.0f;
	}

	return;
}


void PositionClass::LookUpward(bool keydown)
{
	// Update the upward rotation speed movement based on the frame time and whether the user is holding the key down or not.
	if(keydown)
	{
		m_lookUpSpeed += m_frameTime * 0.01f;

		if(m_lookUpSpeed > (m_frameTime * 0.15f))
		{
			m_lookUpSpeed = m_frameTime * 0.15f;
		}
	}
	else
	{
		m_lookUpSpeed -= m_frameTime* 0.005f;

		if(m_lookUpSpeed < 0.0f)
		{
			m_lookUpSpeed = 0.0f;
		}
	}

	// Update the rotation.
	m_rotationX -= m_lookUpSpeed;

	// Keep the rotation maximum 90 degrees.
	if(m_rotationX > 90.0f)
	{
		m_rotationX = 90.0f;
	}

	return;
}


void PositionClass::LookDownward(bool keydown)
{
	// Update the downward rotation speed movement based on the frame time and whether the user is holding the key down or not.
	if(keydown)
	{
		m_lookDownSpeed += m_frameTime * 0.01f;

		if(m_lookDownSpeed > (m_frameTime * 0.15f))
		{
			m_lookDownSpeed = m_frameTime * 0.15f;
		}
	}
	else
	{
		m_lookDownSpeed -= m_frameTime* 0.005f;

		if(m_lookDownSpeed < 0.0f)
		{
			m_lookDownSpeed = 0.0f;
		}
	}

	// Update the rotation.
	m_rotationX += m_lookDownSpeed;

	// Keep the rotation maximum 90 degrees.
	if(m_rotationX < -90.0f)
	{
		m_rotationX = -90.0f;
	}

	return;
}