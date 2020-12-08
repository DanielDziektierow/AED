<!--HEAD -->
# Funciones
# Etapa # 1: Analisis del problema

- **Transcripcion del problema:** Desarrollar el tipo de dato Polígono que representa polígonos con color en el
plano. Las operaciones son: AddVértice, GetVértice, SetVértice, RemoveVértice,
GetCantidadLados, y Get_GetPerímetro.
Desarrollar la estructura Color para usarla en el Poligono. Las operaciones son: Mezclar, GetHtmlRGB, GetHtmlHex, Sumar, Restar, GetComplementario, DecaHex, isIgual, CrearSVG.
Además, que contenga un dato de tipo punto donde se van a guardar los puntoss del poligono.
Tambien, se debera extraer una cantidad ilimitada de poligonos de un flujo de datos y enviarlos en otro.
Este poligono debe estar dividido en 2 partes, la primera tener un poligono que se pueda agregar puntos ilimitados, con un máximo. La segunda tener un poligono que agregue puntos ilimitadamente, pero en una lista enlazada.

- **Restriccion del problema**
Las pruebas deben realizarse con assert, sin usar cin ni cout.

- **Hipotesis del problema**
Para armar la estructura de Poligono previamente voy a armar una estructura llamada punto que contenga 2 float(modificable) para el punto en x e y.
Para crear poligono con sus vertices y un  color, voy a tener en cuenta de agregar una variable que me diga la cantidad de vertices del poligono y agregar un array de los puntos del poligono. Ademas, voy añadir el header Color.h para tener habilitado el tipo de varible Color que habimos creado en la antigua carpeta. 

<!-- - **Modelo IPO**
![Imagen de modelo IPO](https://user-images.githubusercontent.com/48501354/87234896-dfd00f80-c3ab-11ea-8d90-c0f7b918c764.jpg "Modelo IPO")
-->

# Etapa # 2 Diseño de la Solución
* **Léxico del Algoritmo:** 
    * SetVertice: [Poligono]* X unsigned --> Ø
    * GetVertice: [Poligono *]* --> Punto
    * AddVertice: [Poligono ]* --> Ø
    * RemoveVertice: Poligono --> Ø
    * GetCantidadLados: [Poligono *]* --> unsigned
    * GetPerimetro: [Poligono *]* --> int
    * AgregarColorpol: [Poligono ]* --> Ø
    * MostrarColorpol: [Poligono *]* -->Ø
      
----------------------------------
* **Prototipos**
    * void SetVertice(Poligono &, unsigned);
    * Punto GetVertice(const Poligono &, unsigned);
    * void AddVertice(Poligono &, Punto);
    * void RemoveVertice(Poligono);
    * unsigned GetCantidadLados(const Poligono &); 
    * int GetPerimetro(const Poligono &);
    * void AgregarColorpol(Poligono &);
    * void MostrarColorPol(const Poligono &);
* **Definiciones**
    *  void SetVertice(Poligono &p, unsigned cant){
	unsigned i=0;
	double x,y;
	cout<<"Poligono:"<<endl;
	if(cant > 3){
		while(i< cant){
		cout<<"px "<<i<<endl;
		cin>>x;						
		cout<<"py "<<i<<endl;
		cin>>y;
		p.npto.at(i)={x,y};
		i++;	
		}
	}
}

    * Punto GetVertice(const Poligono &p, unsigned v){
	return p.npto.at(v);
}

    * void AddVertice(Poligono &pol, Punto p){
	if(pol.nvertices < MAX_PTOS){
		pol.nvertices=pol.nvertices +1;
		pol.npto.at(pol.nvertices)=p;
	}
}
   
    * void RemoveVertice(Poligono p){
	p.nvertices= p.nvertices -1;
}

    * int GetPerimetro(const Poligono &p){
	unsigned i=0, j=i+1;
	int per=0;
	while(i < p.nvertices){
		per=GetHip(p.npto.at(i),p.npto.at(j));
		i++;
	}
	if(i == p.nvertices){
		per= per+ GetHip(p.npto.at(i), p.npto.at(0));
	}
	return per;
}


    * void AgregarColorpol(Poligono &p, Color c){
	p.colr.col=c.col;
}
    
	* void MostrarColorPol(const Poligono &p){
	cout<<GetHtmlRGB(p.colr);
}


<!--* **Arbol**
![Imagen de Arbol](https://user-images.githubusercontent.com/48501354/87235248-81f1f680-c3b0-11ea-9f74-48d16670bd1d.jpg "Arbol")-->
