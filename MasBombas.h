
#include "stdafx.h"

using namespace std;
using namespace sf;

class MasBombas
{

private:
	Bombas* _nuevobombardeo;
	float deltaT;
	
	
public:
	MasBombas() {
		_nuevobombardeo = new Bombas;
		
		deltaT = 0.0f;

	}
	~MasBombas() { delete _nuevobombardeo;
	}
	void Reiniciar()
	{

		// Aplicar velocidad al objeto
		_nuevobombardeo->AddAcceleration(Vector2f(0.0f, 9.8f));

		//porcentaje gravedad 
		float aux = _nuevobombardeo->GetVelocity().y;
		aux = aux * (80.0f / 100.0f);

		// Chequea si el objeto ha salido de la ventana
		if (_nuevobombardeo->GetPosition().y > 500.0f)
		{
			_nuevobombardeo->SetVelocity(Vector2f(0.0f, -aux));
		}
		_nuevobombardeo->Update(deltaT);

	}
	void Draw(RenderWindow* pWnd)
	{
		_nuevobombardeo->Draw(pWnd);

	}
};
