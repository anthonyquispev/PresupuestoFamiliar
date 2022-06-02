// Librerํas
#include<iomanip>
#include<iostream>

// Personas
#define PERSONA_01 "Padre"
#define PERSONA_02 "Madre"
#define PERSONA_03 "Hermano Mayor"
#define PERSONA_04 "Yo"

// Categorํas de Ingresos
#define Cat_I_01 "Salario"
#define Cat_I_02 "Premios"
#define Cat_I_03 "Subsidios"
#define Cat_I_04 "Venta"
#define Cat_I_05 "Alquiler"
#define Cat_I_06 "Reembolsos"
#define Cat_I_07 "Inversiones"
#define Cat_I_08 "Loteria"
#define Cat_I_09 "Dividendos"
#define Cat_Otros "Otros"

// Categorํas de Gastos
#define Cat_G_01 "Vivienda"
#define Cat_G_02 "Servicios"
#define Cat_G_03 "Comida"
#define Cat_G_04 "Transporte"
#define Cat_G_05 "Salud"
#define Cat_G_06 "Vestimenta"
#define Cat_G_07 "Educacion"
#define Cat_G_08 "Entretenimiento"
#define Cat_G_09 "Deporte"

// Meses
#define Mes_01 "Enero"
#define Mes_02 "Febrero"
#define Mes_03 "Marzo"
#define Mes_04 "Abril"
#define Mes_05 "Mayo"
#define Mes_06 "Junio"
#define Mes_07 "Julio"
#define Mes_08 "Agosto"
#define Mes_09 "Septiembre"
#define Mes_10 "Octubre"
#define Mes_11 "Noviembre"
#define Mes_12 "Diciembre"

using namespace std;

namespace menus{
	
	void menuPrincipal() {
		system("color b");
		cout<<"                           ษอออออออออออออออออป"<<endl;
		cout<<"                           บ .:  M E N U  :. บ"<<endl;							
		cout<<"      ษออออออออออออออออออออสอออออออออออออออออสออออออออออออออออออออป"<<endl;
		cout<<"      บ       [1]. INGRESAR DATOS                                 บ"<<endl;				
		cout<<"      บอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออบ"<<endl;
		cout<<"      บ       [2]. MOSTRAR INGRESOS Y GASTOS TOTALES              บ"<<endl;				
		cout<<"      บอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออบ"<<endl;
		cout<<"      บ       [3]. MOSTRAR TABLA TOTAL                            บ"<<endl;				
		cout<<"      บอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออบ"<<endl;
		cout<<"      บ       [4]. MOSTRAR REGISTROS DE UNA PERSONA               บ"<<endl;				
		cout<<"      บอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออบ"<<endl;
		cout<<"      บ       [5]. MOSTRAR REGISTROS ORDENADOS POR CANTIDAD       บ"<<endl;				
		cout<<"      บอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออบ"<<endl;
		cout<<"      บ       [6]. MOSTRAR REGISTROS DE UNA FECHA                 บ"<<endl;				
		cout<<"      บอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออบ"<<endl;
		cout<<"      บ       [7]. COMPARAR FECHAS                                บ"<<endl;
		cout<<"      บอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออบ"<<endl;
		cout<<"      บ       [8]. SALIR                                          บ"<<endl;
		cout<<"      ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ"<<endl;
	}

	int menuSeleccion(int nOpciones) {
		int opcionEscogida;
		do{
			cout<<"Ingrese una opcion entre (1-"<<nOpciones<<"):"<<endl;
			cin>>opcionEscogida;
		} while (opcionEscogida<1 || opcionEscogida>nOpciones);
		
		return opcionEscogida;
	}

	void menuMostrarInicio() {
		cout<<"\n";
		cout<<setw(16)<<" Persona"<<setw(13)<<"Ingr_Gasto"<<setw(16)<<"Categoria"<<setw(11)<<"Cantidad"<<setw(23)<<"Descripcion"<<setw(6)<<"Dia"<<setw(6)<<
		"Mes"<<setw(7)<<"Anho"<<endl;
		cout<<"================================================================================================="<<endl;
		cout<<"================================================================================================="<<endl;
	}

	void menuMostrarFinal() {
		cout<<"================================================================================================="<<endl;
		cout<<"================================================================================================="<<endl;
		cout<<"\n";
	}
	
	void mensajeError() {
		cout<<"\n\n NO SE PUDO ABRIR EL ARCHIVO :'v \n\n";
		system("pause");
		exit(1);
	}
	
	void menuPersonas() {
		cout<<"Personas"<<endl;
		cout<<"1."<<PERSONA_01<<endl;
		cout<<"2."<<PERSONA_02<<endl;
		cout<<"3."<<PERSONA_03<<endl;
		cout<<"4."<<PERSONA_04<<endl;
	}
	
	void menuCategoriaIngresos() {
		cout<<"\nSeleccione una categoria: \n\n";
		cout<<"1."<<Cat_I_01<<endl;
		cout<<"2."<<Cat_I_02<<endl;
		cout<<"3."<<Cat_I_03<<endl;
		cout<<"4."<<Cat_I_04<<endl;
		cout<<"5."<<Cat_I_05<<endl;
		cout<<"6."<<Cat_I_06<<endl;
		cout<<"7."<<Cat_I_07<<endl;
		cout<<"8."<<Cat_I_08<<endl;
		cout<<"9."<<Cat_I_09<<endl;
		cout<<"10."<<Cat_Otros<<endl;
	}

	void menuCategoriaGastos() {
		cout<<"\nSeleccione una categoria: \n\n";
		cout<<"1."<<Cat_G_01<<endl;
		cout<<"2."<<Cat_G_02<<endl;
		cout<<"3."<<Cat_G_03<<endl;
		cout<<"4."<<Cat_G_04<<endl;
		cout<<"5."<<Cat_G_05<<endl;
		cout<<"6."<<Cat_G_06<<endl;
		cout<<"7."<<Cat_G_07<<endl;
		cout<<"8."<<Cat_G_08<<endl;
		cout<<"9."<<Cat_G_09<<endl;
		cout<<"10."<<Cat_Otros<<endl;
	}
	
}
