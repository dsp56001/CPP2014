#pragma once
ref class GameObject sealed
{
public:
	GameObject();

internal:
	void Position(DirectX::XMFLOAT3 position);
	void Position(DirectX::XMVECTOR position);

protected private:
	virtual void UpdatePosition() {};

	DirectX::XMFLOAT3   m_position;
	DirectX::XMFLOAT4X4 m_modelMatrix;
};

