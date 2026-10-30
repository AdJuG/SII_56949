// Mundo.h: interface for the CMundo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MUNDO_H__9510340A_3D75_485F_93DC_302A43B8039A__INCLUDED_)
#define AFX_MUNDO_H__9510340A_3D75_485F_93DC_302A43B8039A__INCLUDED_

#include <vector>
#include "Plano.h"
#include "DatosMemsCompartida.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Esfera.h"
#include "Raqueta.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

struct MensajePunto {
    int idJugador;
    int puntos;
    bool finJuego;
};

class CMundo  
{
private:
        int fd_fifo; // Descriptor de archivo de la tubería FIFO
        int puntos1;
	int puntos2;
	DatosMemCompartida* pMemCompartida = nullptr;
public:
	void Init();
	CMundo();
	virtual ~CMundo();	
	
	void InitGL();	
	void OnKeyboardDown(unsigned char key, int x, int y);
	void OnTimer(int value);
	void OnDraw();	

	Esfera esfera;
	std::vector<Plano> paredes;
	Plano fondo_izq;
	Plano fondo_dcho;
	Raqueta jugador1;
	Raqueta jugador2;

	
};

#endif // !defined(AFX_MUNDO_H__9510340A_3D75_485F_93DC_302A43B8039A__INCLUDED_)
