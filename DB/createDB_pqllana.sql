-- Se especifica el ENGINE=MyISAM DEFAULT CHARSET=latin1 porque sino 
-- mysql tiene problemas para crear las calves foráneas

CREATE DATABASE IF NOT EXISTS pqllana;
USE pqllana;

CREATE TABLE IF NOT EXISTS localidades (
	localidadId INT NOT NULL PRIMARY KEY, 
	codigoPostal INT NOT NULL, 
	nombreLocalidad VARCHAR(30)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

CREATE TABLE IF NOT EXISTS clientes (
	clienteId INT NOT NULL PRIMARY KEY, 
	cuitCuil INT, 
	razonSocial VARCHAR(50), 
	correoElectronico VARCHAR(80), 
	telefono VARCHAR(50), 
	direccion VARCHAR(50)  DEFAULT NULL, 
	tipoClienteId INT NOT NULL,
	sociedadId INT NOT NULL,
	localidadId INT NOT NULL,	
	
	FOREIGN KEY (localidadId) REFERENCES localidades(localidadId),
	FOREIGN KEY (tipoCLienteId) REFERENCES tiposCliente(tipoClienteId),
	FOREIGN KEY (sociedadId) REFERENCES sociedades(sociedadId)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

CREATE TABLE IF NOT EXISTS sociedades (
	sociedadId INT NOT NULL PRIMARY KEY,
	nombreSociedad VARCHAR(30) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

CREATE TABLE IF NOT EXISTS tiposCliente (
	tipoClienteId INT NOT NULL PRIMARY KEY,
	nombreTipoCliente VARCHAR(30),
	tipoFacturaId INT NOT NULL,

	FOREIGN KEY (tipoFacturaId) REFERENCES tiposFactura(tipoFacturaId)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

CREATE TABLE IF NOT EXISTS venta (
	ventaId INT NOT NULL PRIMARY KEY,
	nombreCliente VARCHAR(30),
	fechaVenta DATE NOT NULL,
	fechaVencimiento DATE,
	facturaId INT NOT NULL,
	tipoVentaId INT,
	empleadoId INT,
	clienteId INT NOT NULL,

	FOREIGN KEY (clienteId) REFERENCES clientes(clienteId),
	FOREIGN KEY (tipoVentaId) REFERENCES tiposVenta(tipoVentaId),
	FOREIGN KEY (empleadoId) REFERENCES empleados(empleadoId),
	FOREIGN KEY (facturaId) REFERENCES facturas(facturaId)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
 
CREATE TABLE IF NOT EXISTS tiposVenta (
	tipoVentaId INT NOT NULL PRIMARY KEY,
	nombreTipoVenta VARCHAR(30)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

CREATE TABLE IF NOT EXISTS tiposFactura(
	tipoFacturaId INT NOT NULL PRIMARY KEY,
	nombreTipoFactura VARCHAR(30),
	iva VARCHAR(10)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

CREATE TABLE IF NOT EXISTS empleados (
	empleadoId INT NOT NULL PRIMARY KEY,
	nombreEmpleado VARCHAR(30),
	perfilId INT,

	FOREIGN KEY (perfilId) REFERENCES perfiles(perfilId)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

CREATE TABLE IF NOT EXISTS perfiles (
	perfilId INT NOT NULL PRIMARY KEY,
	nombrePerfil VARCHAR(30)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

CREATE TABLE IF NOT EXISTS facturas (
	facturaId INT NOT NULL PRIMARY KEY,
	numeroFactura INT,
	tipoFacturaId INT NOT NULL,

	FOREIGN KEY (tipoFacturaId) REFERENCES tiposFactura(tipoFacturaId)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

CREATE TABLE IF NOT EXISTS detalle (
	detalleId INT NOT NULL PRIMARY KEY,
	productoId INT,
	cantidad INT,
	ventaId INT,
	precio DECIMAL(5,2),
	colorId INT,

	FOREIGN KEY (ventaId) REFERENCES venta(ventaId),
	FOREIGN KEY (productoId) REFERENCES productos(productoId),
	FOREIGN KEY (colorId) REFERENCES color(colorId)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

CREATE TABLE IF NOT EXISTS color (
	colorId INT NOT NULL PRIMARY KEY,
	codigoColor INT,
	imagen VARCHAR(90),
	gamaId INT,
	primario BOOLEAN,

	FOREIGN KEY (gamaId) REFERENCES gama(gamaId)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

CREATE TABLE IF NOT EXISTS gama (
	gamaId INT NOT NULL PRIMARY KEY,
	nombreGama VARCHAR(30),
	imagen VARCHAR(90)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

CREATE TABLE IF NOT EXISTS composicionColores (
	composicionId INT NOT NULL PRIMARY KEY,
	colorPrimario INT,
	colorSecundario INT,
	porcentaje DECIMAL(3,2),

	FOREIGN KEY (colorPrimario) REFERENCES color(colorId),
	FOREIGN KEY (colorSecundario) REFERENCES color(colorId)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

CREATE TABLE IF NOT EXISTS ingresos(
	ingresosId INT NOT NULL PRIMARY KEY,
	productoId INT,
	fecha DATE,
	cantidad INT,

	FOREIGN KEY (productoId) REFERENCES productos(productoId)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

CREATE TABLE IF NOT EXISTS productos (
	productoId INT NOT NULL PRIMARY KEY,
	codigoProducto INT,
	nombreProducto VARCHAR(30),
	descripcion VARCHAR(120),
	precio DECIMAL(5,2),
	cantidad INT,
	stockMinimo INT,
	marcaId INT,
	tipoProductoId INT,

	FOREIGN KEY (marcaId) REFERENCES marca(marcaId),
	FOREIGN KEY (tipoProductoId) REFERENCES tiposProducto(tipoProductoId)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

CREATE TABLE IF NOT EXISTS tiposProducto (
	tipoProductoId INT NOT NULL PRIMARY KEY,
	tipoProducto VARCHAR(30),
	esColoreable BOOLEAN,
	stockMinimoPorDefecto INT
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

CREATE TABLE IF NOT EXISTS marca (
	marcaId INT NOT NULL PRIMARY KEY,
	nombreMarca VARCHAR(30)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

CREATE TABLE IF NOT EXISTS datosProductos (
	datosProductosId INT NOT NULL PRIMARY KEY,
	productoId INT,
	nombreAtributo VARCHAR(30),
	valorAtributo INT,
	tipoAtributo INT,

	FOREIGN KEY (productoId) REFERENCES productos(productoId)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

CREATE TABLE IF NOT EXISTS tiposAtributosDeProductos (
	tiposAtributosDeProductosId INT NOT NULL PRIMARY KEY,
	tipoProductoId INT,
	atributoId INT,

	FOREIGN KEY (tipoProductoId) REFERENCES tiposProducto(tipoProductoId)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

CREATE TABLE IF NOT EXISTS atributosDeProductos (
	atributoId INT NOT NULL PRIMARY KEY,
	nombreAtributo VARCHAR(30),
	tipoAtributo INT,

	FOREIGN KEY (tipoAtributo) REFERENCES tiposAtributosDeProductos(atributoId)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
