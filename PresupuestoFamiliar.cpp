// Librerํas
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <math.h>

#include "Menus.cpp"

using namespace menus;

struct Fecha{
	int dia; int mes; int anho;
};

struct Persona{
	char persona[20];
	char ingreso_gasto[30];
	char categoria[20];
	char descripcion[100];
	float cantidad;
	Fecha f;
};


void ingresarDatos(FILE *F, Persona p);
void ingresarPersona(Persona *p);
void ingresarCategoria(Persona *p);
void ingresarCategoriaIngresos(Persona *p);
void ingresarCategoriaGastos(Persona *p);
void ingresarFecha(Persona *p);

void Ingreso_y_GastoTotal(FILE *F, Persona p);

void mostrarTodo(FILE *F, Persona p);

void mostrarPorPersona(FILE *F, Persona p);

void mostrarOrdenadosPorCantidad(FILE *F, Persona p);
void ordenar(Persona temp[], int cont);
void ordenarMenor_a_Mayor(Persona temp[], int cont);
void ordenarMayor_a_Menor(Persona temp[], int cont);

void mostrarFecha(FILE *F, Persona p);

void compararFechas(FILE *F, Persona p);
void barrasEstadisticas(float porcentaje1, float porcentaje2);
void estadisticasIngresos(Persona temp[], int cont);
void estadisticasGastos(Persona temp[], int cont);
float sumaTemp(Persona *temp, int cont);
void mes(char cad[], int m);

void mostrarPersona(Persona p);


string nombreDeArchivo = "DataPrueba.dat";

int main() {
	
	Persona p;
	FILE F;
	int opcionEscogida;
	int nOpciones = 8;
	
	do{
		menuPrincipal();

 		opcionEscogida = menuSeleccion(nOpciones);
		
		system("cls");
		
		switch(opcionEscogida){
			case 1: ingresarDatos(&F, p);
					break;
					
			case 2: Ingreso_y_GastoTotal(&F, p);
					break;
					
			case 3: mostrarTodo(&F, p);
					break;
					
			case 4: mostrarPorPersona(&F, p);
					break;
					
			case 5: mostrarOrdenadosPorCantidad(&F, p);
					break;
					
			case 6: mostrarFecha(&F, p);
					break;	
					
			case 7: compararFechas(&F, p);
					break;
					
			case 8: cout<<"GRACIAS POR USAR EL PROGRAMA :)"<<endl;
					break;
					
		}
		system("pause");
		system("cls");
		
	} while(opcionEscogida != nOpciones);
	
}

void ingresarDatos(FILE *F, Persona p) {

	F=fopen(nombreDeArchivo.c_str(), "a+");
	if(F == NULL){
		mensajeError();
	}
	fflush(stdin);
	
	ingresarPersona(&p);
	
	ingresarCategoria(&p);
	
	fflush(stdin);
	cout<<"\nDescripcion: "; cin.getline(p.descripcion, 100);
	fflush(stdin); 
	cout<<"\nCantidad: "; cin>>p.cantidad;
	fflush(stdin);
	cout<<"\nFecha"<<endl;
	
	ingresarFecha(&p);
	
	cout<<"\nDatos ingresados correctamente !!!\n"<<endl;
	fwrite(&p, sizeof(p), 1, F);
	fclose(F);

}

void ingresarPersona(Persona *p) {
	
	menuPersonas();
	
	int opcion = menuSeleccion(4);
	
	switch(opcion){
		case 1: strcpy(p->persona, PERSONA_01); break;
		case 2: strcpy(p->persona, PERSONA_02); break;
		case 3: strcpy(p->persona, PERSONA_03); break;
		case 4: strcpy(p->persona, PERSONA_04); break;
	}
	
}

void ingresarCategoriaIngresos(Persona *p) {
	
	menuCategoriaIngresos();

	int opcion = menuSeleccion(10);
	
	switch(opcion){
		case 1: strcpy(p->categoria, Cat_I_01); break;
		case 2: strcpy(p->categoria, Cat_I_02); break;
		case 3: strcpy(p->categoria, Cat_I_03); break;
		case 4: strcpy(p->categoria, Cat_I_04); break;
		case 5: strcpy(p->categoria, Cat_I_05); break;
		case 6: strcpy(p->categoria, Cat_I_06); break;
		case 7: strcpy(p->categoria, Cat_I_07); break;
		case 8: strcpy(p->categoria, Cat_I_08); break;
		case 9: strcpy(p->categoria, Cat_I_09); break;
		case 10: strcpy(p->categoria, Cat_Otros); break;
	}
	
}
void ingresarCategoriaGastos(Persona*p) {

	menuCategoriaGastos();
	
	int opcion = menuSeleccion(10);	
	
	switch(opcion){
		case 1: strcpy(p->categoria, Cat_G_01); break;
		case 2: strcpy(p->categoria, Cat_G_02); break;
		case 3: strcpy(p->categoria, Cat_G_03); break;
		case 4: strcpy(p->categoria, Cat_G_04); break;
		case 5: strcpy(p->categoria, Cat_G_05); break;
		case 6: strcpy(p->categoria, Cat_G_06); break;
		case 7: strcpy(p->categoria, Cat_G_07); break;
		case 8: strcpy(p->categoria, Cat_G_08); break;
		case 9: strcpy(p->categoria, Cat_G_09); break;
		case 10: strcpy(p->categoria, Cat_Otros); break;
	}
}

void ingresarCategoria(Persona *p) {
	int rpta;
	
	do{
		cout<<"\nIngreso o gasto (1/2): "; cin>>rpta;
	}while (rpta!=1 and rpta!=2);

 	switch(rpta){
		case 1:
			strcpy(p->ingreso_gasto,"Ingreso");
			ingresarCategoriaIngresos(p); break;
			
		case 2:
			strcpy(p->ingreso_gasto,"Gasto"); 
			ingresarCategoriaGastos(p); break;
	}

}

void mostrarTodo(FILE *F, Persona p) {
	cout.setf(ios_base::left);
	F = fopen(nombreDeArchivo.c_str(),"r");
	if(F == NULL){
		mensajeError();
	}
	
	menuMostrarInicio();
	
	fread(&p, sizeof(p), 1, F);
	while(!feof(F)){
		mostrarPersona(p);
		fread(&p ,sizeof(p), 1, F);
	}
	
	menuMostrarFinal();
	fclose(F);
}

void mostrarPorPersona(FILE *F, Persona p) {
	cout.setf(ios_base::left);
	F = fopen(nombreDeArchivo.c_str(), "r");
	
	if(F==NULL)
		mensajeError();
	
	menuPersonas();
	
	int opcion = menuSeleccion(4);
	
	char personaSeleccionada[20];
	
	switch(opcion){
		case 1: strcpy(personaSeleccionada, PERSONA_01); break;
		case 2: strcpy(personaSeleccionada, PERSONA_02); break;
		case 3: strcpy(personaSeleccionada, PERSONA_03); break;
		case 4: strcpy(personaSeleccionada, PERSONA_04); break;		
	}
	
	menuMostrarInicio();
	
	fread(&p, sizeof(p), 1, F);
	while(!feof(F)){
		
		if(strcmp(p.persona, personaSeleccionada)==0)
			mostrarPersona(p);
				
		fread(&p, sizeof(p), 1, F);
	}
	
	menuMostrarFinal();
	
	fclose(F);
}

void Ingreso_y_GastoTotal(FILE *F, Persona p) {
	
	F=fopen(nombreDeArchivo.c_str(),"r");
	if(F==NULL){
		mensajeError();
	}	
	float sumaIngresosP1, sumaIngresosP2, sumaIngresosP3, sumaIngresosP4;
	float sumaGastosP1, sumaGastosP2, sumaGastosP3, sumaGastosP4;
	
	sumaIngresosP1=sumaIngresosP2=sumaIngresosP3=sumaIngresosP4=sumaGastosP1=sumaGastosP2=
	sumaGastosP3=sumaGastosP4=0.0;

	fread(&p, sizeof(p), 1, F);
	while(!feof(F)){
		if(strcmp(p.persona, PERSONA_01)==0){
			if(strcmp(p.ingreso_gasto, "Ingreso")==0)
				sumaIngresosP1 += p.cantidad;
			else
				sumaGastosP1 += p.cantidad;	
		}
		
		if(strcmp(p.persona, PERSONA_02)==0){
			if(strcmp(p.ingreso_gasto, "Ingreso")==0)
				sumaIngresosP2 += p.cantidad;
			else
				sumaGastosP2 += p.cantidad;	
		}
		
		if(strcmp(p.persona, PERSONA_03)==0){
			if(strcmp(p.ingreso_gasto, "Ingreso")==0)
				sumaIngresosP3 += p.cantidad;
			else
				sumaGastosP3 += p.cantidad;	
		}		
		
		if(strcmp(p.persona, PERSONA_04)==0){
			if(strcmp(p.ingreso_gasto, "Ingreso")==0)
				sumaIngresosP4 += p.cantidad;
			else
				sumaGastosP4 += p.cantidad;	
		}

		fread(&p, sizeof(p), 1, F);
	}
	
	cout<<"PERSONA: "<<PERSONA_01<<endl;
	cout<<"Ingresos totales: "<<sumaIngresosP1<<endl;
	cout<<"Gastos totales: "<<sumaGastosP1<<endl;
	cout<<"------------------------"<<endl;
	cout<<"------------------------"<<endl;
	
	cout<<"PERSONA: "<<PERSONA_02<<endl;
	cout<<"Ingresos totales: "<<sumaIngresosP2<<endl;
	cout<<"Gastos totales: "<<sumaGastosP2<<endl;
	cout<<"------------------------"<<endl;
	cout<<"------------------------"<<endl;
	
	cout<<"PERSONA: "<<PERSONA_03<<endl;
	cout<<"Ingresos totales: "<<sumaIngresosP3<<endl;
	cout<<"Gastos totales: "<<sumaGastosP3<<endl;
	cout<<"------------------------"<<endl;
	cout<<"------------------------"<<endl;
	
	cout<<"PERSONA: "<<PERSONA_04<<endl;
	cout<<"Ingresos totales: "<<sumaIngresosP4<<endl;
	cout<<"Gastos totales: "<<sumaGastosP4<<endl;
	cout<<"------------------------"<<endl;
	cout<<"------------------------"<<endl;
	
	float sumaIngresosTotal = sumaIngresosP1 + sumaIngresosP2 + sumaIngresosP3 + sumaIngresosP4;
	float sumaGastosTotal = sumaGastosP1 + sumaGastosP2 + sumaGastosP3 + sumaGastosP4;
	float saldoNeto = sumaIngresosTotal - sumaGastosTotal;
	
	cout<<"\t\t"<<"Ingresos totales: "<<sumaIngresosTotal;
	cout<<"\n\t\t"<<"Gastos totales: "<<sumaGastosTotal;
	cout<<"\n\t\t"<<"Saldo neto: "<<saldoNeto;
	cout<<"\n\n";
	fclose(F);
}

void mostrarOrdenadosPorCantidad(FILE *F, Persona p) {
	cout.setf(ios_base::left);
	F = fopen(nombreDeArchivo.c_str(), "r");
	if(F==NULL){
		mensajeError();
	}
	
	Persona tempTotal[200], tempIngresos[200], tempGastos[200];
	int contTotal, contIngresos, contGastos;
	contTotal=contIngresos=contGastos=0;
	
	fread(&p, sizeof(p), 1, F);
	while(!feof(F)){
		
		tempTotal[contTotal]=p;
		contTotal++;
		if(strcmp(p.ingreso_gasto,"Ingreso")==0){
			tempIngresos[contIngresos]=p;
			contIngresos++;
		}
		else{
			tempGastos[contGastos]=p;
			contGastos++;
		}
		fread(&p, sizeof(p), 1, F);
	}
	
	cout<<"\n1.Ingresos"<<endl;
	cout<<"2.Gastos"<<endl;
	cout<<"3.Todo"<<endl;
	int opcion = menuSeleccion(3);
	
	switch(opcion){
		case 1: ordenar(tempIngresos, contIngresos); break;
		case 2: ordenar(tempGastos, contGastos); break;
		case 3: ordenar(tempTotal, contTotal); break;
	}
	
	fclose(F);
}

void mostrarPersona(Persona p) {
	cout<<" "<<setw(16)<<p.persona<<setw(13)<<p.ingreso_gasto<<setw(16)<<p.categoria<<setw(11)<<p.cantidad<<setw(23)<<p.descripcion<<setw(6)<<
    p.f.dia<<setw(6)<<p.f.mes<<setw(7)<<p.f.anho<<endl;
}

void ordenar(Persona temp[], int cont) {
	cout<<"\nSeleccione un orden:"<<endl;
	cout<<"1.Menor a mayor"<<endl;
	cout<<"2.Mayor a menor"<<endl;
	cout<<"3.Normal"<<endl;
	int opcion = menuSeleccion(3);
	
	switch(opcion){
		case 1: ordenarMenor_a_Mayor(temp, cont); break;
		case 2: ordenarMayor_a_Menor(temp, cont); break;									
	}
	
	menuMostrarInicio();
		
	for (int i = 0; i < cont; ++i)
		mostrarPersona(temp[i]);
			
	menuMostrarFinal();	
}

void ordenarMenor_a_Mayor(Persona temp[], int cont) {
	
	for (int i = 0; i < cont; ++i){
		for (int j = i+1; j < cont; ++j){
			if(temp[i].cantidad>temp[j].cantidad){
				Persona aux= temp[i];
				temp[i] = temp[j];
				temp[j] = aux;
			}
		}
	}
}


void ordenarMayor_a_Menor(Persona temp[], int cont) {
		
	for (int i = 0; i < cont; ++i){
		for (int j = i+1; j < cont; ++j){
			if(temp[i].cantidad<temp[j].cantidad){
				Persona aux= temp[i];
				temp[i] = temp[j];
				temp[j] = aux;
			}
		}
	}
}


void mostrarFecha(FILE *F, Persona p) {
	
	F = fopen(nombreDeArchivo.c_str(), "r");
	
	if(F==NULL){
		mensajeError();
	}
	
	Persona aux;
	ingresarFecha(&aux);
	
	menuMostrarInicio();
	
	fread(&p, sizeof(p), 1, F);
	while(!feof(F)){
		
		if(p.f.dia==aux.f.dia && p.f.mes==aux.f.mes && p.f.anho==aux.f.anho){
			mostrarPersona(p);
		}
		
		fread(&p, sizeof(p), 1, F);
	}
	
	menuMostrarFinal();
	
	fclose(F);
}


void compararFechas(FILE *F, Persona p) {
	cout.setf(ios_base::right);
	F = fopen(nombreDeArchivo.c_str(), "r");
	
	if(F==NULL)
		mensajeError();
	
	int a1, a2, m1, m2;
	
	cout<<"\tINGRESE 2 FECHAS"<<endl;
	
	do{
		cout<<"  FECHA 1"<<endl;
		cout<<"  Mes: "; cin>>m1;
		cout<<"  Anho: "; cin>>a1;
	} while( m1 < 1 || m1 >12 || a1 < 0);
	
	do{
		cout<<"  FECHA 2"<<endl;
		cout<<"  Mes: "; cin>>m2;
		cout<<"  Anho: "; cin>>a2;
	} while( m2 < 1 || m2 >12 || a2 < 0);	
	
	Persona tempIngresos1[200], tempGastos1[200], tempIngresos2[200], tempGastos2[200];	
	
	int contIngresos1, contGastos1, contIngresos2, contGastos2;
	contIngresos1=contGastos1=contIngresos2=contGastos2=0;
	
	fread(&p, sizeof(p), 1, F);
	while(!feof(F)){
		
		//FECHA 1
		if(p.f.anho == a1 && p.f.mes == m1){
			if(strcmp(p.ingreso_gasto, "Ingreso")==0){
				tempIngresos1[contIngresos1] = p;
				contIngresos1++;
			}
			else{
				tempGastos1[contGastos1] = p;
				contGastos1++;
			}
		}
		
		//FECHA 2
		if(p.f.anho == a2 && p.f.mes == m2){
			if(strcmp(p.ingreso_gasto, "Ingreso")==0){
				tempIngresos2[contIngresos2] = p;
				contIngresos2++;
			}
			else{
				tempGastos2[contGastos2] = p;
				contGastos2++;
			}
		}	
		fread(&p, sizeof(p), 1, F);
	}
	
	float sumaIngresos1 = sumaTemp(tempIngresos1, contIngresos1);
	float sumaGastos1 = sumaTemp(tempGastos1, contGastos1);
	float sumaIngresos2 = sumaTemp(tempIngresos2, contIngresos2);
	float sumaGastos2 = sumaTemp(tempGastos2, contGastos2);
	
	float porcentajeIngresos1 = sumaIngresos1 / (sumaIngresos1 + sumaIngresos2)*(100);
	float porcentajeIngresos2 = sumaIngresos2 / (sumaIngresos1 + sumaIngresos2)*(100);
	float porcentajeGastos1 = sumaGastos1 / (sumaGastos1 + sumaGastos2)*(100);
	float porcentajeGastos2 = sumaGastos2 / (sumaGastos1 + sumaGastos2)* (100);


	// BARRAS ESTADอSTICAS
	
	char mes1[11],mes2[11];
	mes(mes1, m1);
	mes(mes2, m2);
	system("color c");
	
	cout<<"\n\n";
	
	// INGRESOS
	
	//BARRA DE INGRESOS
	cout<<"\n\n\t\tINGRESOS"<<endl;
	cout<<"\n";
	barrasEstadisticas(porcentajeIngresos1, porcentajeIngresos2);
	cout.precision(3);
	cout<<setw(14)<<porcentajeIngresos1<<"%"<<setw(10)<<porcentajeIngresos2<<"%"<<endl;
	cout<<setw(16)<<mes1<<setw(11)<<mes2<<endl;
	cout<<setw(15)<<a1<<setw(11)<<a2<<endl;
	cout<<"\n\n";
	
	//ESTADอSTICAS INGRESOS FECHA 1
	cout<<"       ษอออออออออออออออออออออออออออออออป"<<endl;
	cout<<"       บ  INGRESOS -> "<<setw(11)<<mes1<<" "<<a1<<" บ"<<endl;
	estadisticasIngresos(tempIngresos1, contIngresos1);
	
	//ESTADอSTICAS INGRESOS FECHA 2
	cout<<"       ษอออออออออออออออออออออออออออออออป"<<endl;
	cout<<"       บ  INGRESOS -> "<<setw(11)<<mes2<<" "<<a2<<" บ"<<endl;
	estadisticasIngresos(tempIngresos2, contIngresos2);		


	// GASTOS

	//BARRA DE GASTOS
	cout<<"\n\n\t\tGASTOS"<<endl;
	cout<<"\n";
	barrasEstadisticas(porcentajeGastos1, porcentajeGastos2);
	cout.precision(3);
	cout<<setw(14)<<porcentajeGastos1<<"%"<<setw(10)<<porcentajeGastos2<<"%"<<endl;
	cout<<setw(16)<<mes1<<setw(11)<<mes2<<endl;
	cout<<setw(15)<<a1<<setw(11)<<a2<<endl;
	cout<<"\n\n";

	//ESTADอSTICAS GASTOS FECHA 1
	cout<<"       ษอออออออออออออออออออออออออออออออป"<<endl;
	cout<<"       บ  GASTOS   -> "<<setw(11)<<mes1<<" "<<a1<<" บ"<<endl;
	estadisticasGastos(tempGastos1, contGastos1);
	
	
	//ESTADอSTICAS GASTOS FECHA 2
	cout<<"       ษอออออออออออออออออออออออออออออออป"<<endl;
	cout<<"       บ  GASTOS   -> "<<setw(11)<<mes2<<" "<<a2<<" บ"<<endl;
	estadisticasGastos(tempGastos2, contGastos2);
}

float sumaTemp(Persona *temp, int cont) {
	float suma = 0.0;
	for(int i=0; i<cont; i++){
		suma+=(temp+i)->cantidad;
	}	
	return suma;
}

void mes(char cad[], int m) {
	switch(m){
		case 1: strcpy(cad, Mes_01);
		break;
		case 2: strcpy(cad, Mes_02);
		break;
		case 3: strcpy(cad, Mes_03);
		break;			
		case 4: strcpy(cad, Mes_04);
		break;
		case 5: strcpy(cad, Mes_05);
		break;
		case 6: strcpy(cad, Mes_06);
		break;
		case 7: strcpy(cad, Mes_07);
		break;
		case 8: strcpy(cad, Mes_08);
		break;
		case 9: strcpy(cad, Mes_09);
		break;
		case 10: strcpy(cad, Mes_10);
		break;
		case 11: strcpy(cad, Mes_11);
		break;
		case 12: strcpy(cad, Mes_12);
		break;															
	}
}

void barrasEstadisticas(float porcentaje1, float porcentaje2) {
	int c=-37;
	char i3 = c;

	for(int i=100; i>=10; i-=10){
		cout<<setw(5)<<i;
		
		if(porcentaje1 >= i){
			cout<<"\t  "<<i3<<i3<<i3<<i3<<i3;
		}
		else cout<<"\t  "<<"     ";
		if(porcentaje2 >= i){
			cout<<"\t     "<<i3<<i3<<i3<<i3<<i3;
		}
		else cout<<"\t     "<<"     ";
		cout<<"\n";
	}
}

void estadisticasIngresos(Persona temp[], int cont) {
	
	float c1,c2,c3,c4,c5,c6,c7,c8,c9,c10;
	c1=c2=c3=c4=c5=c6=c7=c8=c9=c10=0.0;
	
	for(int i=0; i<cont; i++){
		if(strcmp(temp[i].categoria,Cat_I_01)==0) c1+=temp[i].cantidad;
		if(strcmp(temp[i].categoria,Cat_I_02)==0) c2+=temp[i].cantidad;
		if(strcmp(temp[i].categoria,Cat_I_03)==0) c3+=temp[i].cantidad;
		if(strcmp(temp[i].categoria,Cat_I_04)==0) c4+=temp[i].cantidad;
		if(strcmp(temp[i].categoria,Cat_I_05)==0) c5+=temp[i].cantidad;
		if(strcmp(temp[i].categoria,Cat_I_06)==0) c6+=temp[i].cantidad;
		if(strcmp(temp[i].categoria,Cat_I_07)==0) c7+=temp[i].cantidad;
		if(strcmp(temp[i].categoria,Cat_I_08)==0) c8+=temp[i].cantidad;
		if(strcmp(temp[i].categoria,Cat_I_09)==0) c9+=temp[i].cantidad;
		if(strcmp(temp[i].categoria,Cat_Otros)==0) c10+=temp[i].cantidad;
	}
	
	float c_total = c1+c2+c3+c4+c5+c6+c7+c8+c9+c10;
	float porcentaje_c1= (c1/c_total)*(100.0);
	float porcentaje_c2= (c2/c_total)*(100.0);
	float porcentaje_c3= (c3/c_total)*(100.0);
	float porcentaje_c4= (c4/c_total)*(100.0);
	float porcentaje_c5= (c5/c_total)*(100.0);
	float porcentaje_c6= (c6/c_total)*(100.0);
	float porcentaje_c7= (c7/c_total)*(100.0);
	float porcentaje_c8= (c8/c_total)*(100.0);
	float porcentaje_c9= (c9/c_total)*(100.0);
	float porcentaje_c10= (c10/c_total)*(100.0);

	cout.precision(1);
	cout<<fixed;
	cout<<" ษอออออสอออออออออออออออออออออออออออออออสอออออป"<<endl;
	cout<<" บ  "<<setw(15)<<Cat_I_01<<":  "<<"S/."<<setw(6)<<c1<<"("<<setw(5)<<porcentaje_c1<<"%)"<<setw(7)<<"บ"<<endl;
	cout<<" บ  "<<setw(15)<<Cat_I_02<<":  "<<"S/."<<setw(6)<<c2<<"("<<setw(5)<<porcentaje_c2<<"%)"<<setw(7)<<"บ"<<endl;
	cout<<" บ  "<<setw(15)<<Cat_I_03<<":  "<<"S/."<<setw(6)<<c3<<"("<<setw(5)<<porcentaje_c3<<"%)"<<setw(7)<<"บ"<<endl;
	cout<<" บ  "<<setw(15)<<Cat_I_04<<":  "<<"S/."<<setw(6)<<c4<<"("<<setw(5)<<porcentaje_c4<<"%)"<<setw(7)<<"บ"<<endl;
	cout<<" บ  "<<setw(15)<<Cat_I_05<<":  "<<"S/."<<setw(6)<<c5<<"("<<setw(5)<<porcentaje_c5<<"%)"<<setw(7)<<"บ"<<endl;
	cout<<" บ  "<<setw(15)<<Cat_I_06<<":  "<<"S/."<<setw(6)<<c6<<"("<<setw(5)<<porcentaje_c6<<"%)"<<setw(7)<<"บ"<<endl;
	cout<<" บ  "<<setw(15)<<Cat_I_07<<":  "<<"S/."<<setw(6)<<c7<<"("<<setw(5)<<porcentaje_c7<<"%)"<<setw(7)<<"บ"<<endl;
	cout<<" บ  "<<setw(15)<<Cat_I_08<<":  "<<"S/."<<setw(6)<<c8<<"("<<setw(5)<<porcentaje_c8<<"%)"<<setw(7)<<"บ"<<endl;
	cout<<" บ  "<<setw(15)<<Cat_I_09<<":  "<<"S/."<<setw(6)<<c9<<"("<<setw(5)<<porcentaje_c9<<"%)"<<setw(7)<<"บ"<<endl;
	cout<<" บ  "<<setw(15)<<Cat_Otros<<":  "<<"S/."<<setw(6)<<c10<<"("<<setw(5)<<porcentaje_c10<<"%)"<<setw(7)<<"บ"<<endl;
	cout<<" ศอออออออออออออออออออออออออออออออออออออออออออผ"<<endl;
}

void estadisticasGastos(Persona temp[], int cont) {
	
	float c1,c2,c3,c4,c5,c6,c7,c8,c9,c10;
	c1=c2=c3=c4=c5=c6=c7=c8=c9=c10=0.0;
	
	for(int i=0; i<cont; i++){
		if(strcmp(temp[i].categoria,Cat_G_01)==0) c1+=temp[i].cantidad;
		if(strcmp(temp[i].categoria,Cat_G_02)==0) c2+=temp[i].cantidad;
		if(strcmp(temp[i].categoria,Cat_G_03)==0) c3+=temp[i].cantidad;
		if(strcmp(temp[i].categoria,Cat_G_04)==0) c4+=temp[i].cantidad;
		if(strcmp(temp[i].categoria,Cat_G_05)==0) c5+=temp[i].cantidad;
		if(strcmp(temp[i].categoria,Cat_G_06)==0) c6+=temp[i].cantidad;
		if(strcmp(temp[i].categoria,Cat_G_07)==0) c7+=temp[i].cantidad;
		if(strcmp(temp[i].categoria,Cat_G_08)==0) c8+=temp[i].cantidad;
		if(strcmp(temp[i].categoria,Cat_G_09)==0) c9+=temp[i].cantidad;
		if(strcmp(temp[i].categoria,Cat_Otros)==0) c10+=temp[i].cantidad;
	}
	
	float c_total = c1+c2+c3+c4+c5+c6+c7+c8+c9+c10;
	float porcentaje_c1= (c1/c_total)*(100.0);
	float porcentaje_c2= (c2/c_total)*(100.0);
	float porcentaje_c3= (c3/c_total)*(100.0);
	float porcentaje_c4= (c4/c_total)*(100.0);
	float porcentaje_c5= (c5/c_total)*(100.0);
	float porcentaje_c6= (c6/c_total)*(100.0);
	float porcentaje_c7= (c7/c_total)*(100.0);
	float porcentaje_c8= (c8/c_total)*(100.0);
	float porcentaje_c9= (c9/c_total)*(100.0);
	float porcentaje_c10= (c10/c_total)*(100.0);
	
	cout.precision(1);
	cout<<fixed;
	cout<<" ษอออออสอออออออออออออออออออออออออออออออสอออออป"<<endl;
	cout<<" บ  "<<setw(15)<<Cat_G_01<<":  "<<"S/."<<setw(6)<<c1<<"("<<setw(5)<<porcentaje_c1<<"%)"<<setw(7)<<"บ"<<endl;
	cout<<" บ  "<<setw(15)<<Cat_G_02<<":  "<<"S/."<<setw(6)<<c2<<"("<<setw(5)<<porcentaje_c2<<"%)"<<setw(7)<<"บ"<<endl;
	cout<<" บ  "<<setw(15)<<Cat_G_03<<":  "<<"S/."<<setw(6)<<c3<<"("<<setw(5)<<porcentaje_c3<<"%)"<<setw(7)<<"บ"<<endl;
	cout<<" บ  "<<setw(15)<<Cat_G_04<<":  "<<"S/."<<setw(6)<<c4<<"("<<setw(5)<<porcentaje_c4<<"%)"<<setw(7)<<"บ"<<endl;
	cout<<" บ  "<<setw(15)<<Cat_G_05<<":  "<<"S/."<<setw(6)<<c5<<"("<<setw(5)<<porcentaje_c5<<"%)"<<setw(7)<<"บ"<<endl;
	cout<<" บ  "<<setw(15)<<Cat_G_06<<":  "<<"S/."<<setw(6)<<c6<<"("<<setw(5)<<porcentaje_c6<<"%)"<<setw(7)<<"บ"<<endl;
	cout<<" บ  "<<setw(15)<<Cat_G_07<<":  "<<"S/."<<setw(6)<<c7<<"("<<setw(5)<<porcentaje_c7<<"%)"<<setw(7)<<"บ"<<endl;
	cout<<" บ  "<<setw(15)<<Cat_G_08<<":  "<<"S/."<<setw(6)<<c8<<"("<<setw(5)<<porcentaje_c8<<"%)"<<setw(7)<<"บ"<<endl;
	cout<<" บ  "<<setw(15)<<Cat_G_09<<":  "<<"S/."<<setw(6)<<c9<<"("<<setw(5)<<porcentaje_c9<<"%)"<<setw(7)<<"บ"<<endl;
	cout<<" บ  "<<setw(15)<<Cat_Otros<<":  "<<"S/."<<setw(6)<<c10<<"("<<setw(5)<<porcentaje_c10<<"%)"<<setw(7)<<"บ"<<endl;
	cout<<" ศอออออออออออออออออออออออออออออออออออออออออออผ"<<endl;
}

void ingresarFecha(Persona *p) {
	int dia, mes, anho;
	bool bisiesto;
	
	while(true){
	
	 	bisiesto = false;
	
	 	cout << "\nDia: "; cin >> dia;
	 	cout << "Mes: "; cin >> mes;
	 	cout << "Anho: "; cin >> anho;
		
		if(dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12 && anho >= 0){
			
			//Determinamos si el a๑o es bisiesto
			if(anho%4 == 0  &&  anho%100 != 100  ||  anho%400 == 0) // El a๑o debe ser m๚ltiplo de 4 y no m๚ltiplo de 100, 
				bisiesto = true;								  // o m๚ltiplo de 400
				
				
			//Meses con 31 dํas
			if( mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){ 
				if(dia >= 1 && dia <=31){
					break; // Fecha vแlida
				}
			}
			
			//Si el mes es febrero y el a๑o es bisiesto
			else if (mes == 2  && bisiesto == true){
				if(dia >= 1 && dia <=29){
					break; //Fecha vแlida
				}
			}
			
			//Si el mes es febrero y el a๑o no es bisiesto
			else if(mes == 2 && bisiesto == false){
				if(dia >=1 && dia <=28){
					break; //Fecha vแlida
				}
			}
			//Los meses que tienen 31 dํas
			else{
				if(dia >= 1 && dia<=30){
					break; //Fecha vแlida
				}
			}
		}
		cout<<"\n\t Fecha no valida";
		cout<<"\n\t Ingrese otra fecha";
	}
	
	//Copiamos los datos a la estructura
	p->f.dia = dia;
	p->f.mes = mes;
	p->f.anho = anho;
}

