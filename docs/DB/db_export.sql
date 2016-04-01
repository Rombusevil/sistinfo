-- phpMyAdmin SQL Dump
-- version 3.4.11.1deb2
-- http://www.phpmyadmin.net
--
-- Servidor: localhost
-- Tiempo de generación: 29-12-2014 a las 00:00:32
-- Versión del servidor: 5.5.31
-- Versión de PHP: 5.4.4-14+deb7u5

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Base de datos: `pqllana`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `atributosDeProductos`
--

CREATE TABLE IF NOT EXISTS `atributosDeProductos` (
  `atributoId` int(11) NOT NULL,
  `nombreAtributo` varchar(30) DEFAULT NULL,
  `tipoAtributo` int(11) DEFAULT NULL,
  PRIMARY KEY (`atributoId`),
  KEY `tipoAtributo` (`tipoAtributo`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `clientes`
--

CREATE TABLE IF NOT EXISTS `clientes` (
  `clienteId` int(11) NOT NULL,
  `cuitCuil` int(11) DEFAULT NULL,
  `razonSocial` varchar(50) DEFAULT NULL,
  `correoElectronico` varchar(80) DEFAULT NULL,
  `telefono` varchar(50) DEFAULT NULL,
  `direccion` varchar(50) DEFAULT NULL,
  `tipoClienteId` int(11) NOT NULL,
  `sociedadId` int(11) NOT NULL,
  `localidadId` int(11) NOT NULL,
  PRIMARY KEY (`clienteId`),
  KEY `localidadId` (`localidadId`),
  KEY `tipoClienteId` (`tipoClienteId`),
  KEY `sociedadId` (`sociedadId`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `clientes`
--

INSERT INTO `clientes` (`clienteId`, `cuitCuil`, `razonSocial`, `correoElectronico`, `telefono`, `direccion`, `tipoClienteId`, `sociedadId`, `localidadId`) VALUES
(1, 1234, 'LOL', 'lol@lolol.com.ar', '1234 4432', 'Lol calle street 1234', 1, 1, 1);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `color`
--

CREATE TABLE IF NOT EXISTS `color` (
  `colorId` int(11) NOT NULL,
  `codigoColor` int(11) DEFAULT NULL,
  `imagen` varchar(90) DEFAULT NULL,
  `gamaId` int(11) DEFAULT NULL,
  `primario` tinyint(1) DEFAULT NULL,
  PRIMARY KEY (`colorId`),
  KEY `gamaId` (`gamaId`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `color`
--

INSERT INTO `color` (`colorId`, `codigoColor`, `imagen`, `gamaId`, `primario`) VALUES
(1, 0, NULL, 12, 1);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `composicionColores`
--

CREATE TABLE IF NOT EXISTS `composicionColores` (
  `composicionId` int(11) NOT NULL,
  `colorPrimario` int(11) DEFAULT NULL,
  `colorSecundario` int(11) DEFAULT NULL,
  `porcentaje` decimal(3,2) DEFAULT NULL,
  PRIMARY KEY (`composicionId`),
  KEY `colorPrimario` (`colorPrimario`),
  KEY `colorSecundario` (`colorSecundario`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `datosProductos`
--

CREATE TABLE IF NOT EXISTS `datosProductos` (
  `datosProductosId` int(11) NOT NULL,
  `productoId` int(11) DEFAULT NULL,
  `nombreAtributo` varchar(30) DEFAULT NULL,
  `valorAtributo` int(11) DEFAULT NULL,
  `tipoAtributo` int(11) DEFAULT NULL,
  PRIMARY KEY (`datosProductosId`),
  KEY `productoId` (`productoId`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `db_sequence`
--

CREATE TABLE IF NOT EXISTS `db_sequence` (
  `seq_name` varchar(50) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `nextid` int(10) NOT NULL,
  PRIMARY KEY (`seq_name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `db_sequence`
--

INSERT INTO `db_sequence` (`seq_name`, `nextid`) VALUES
('empleados', 3),
('perfiles', 1);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `detalle`
--

CREATE TABLE IF NOT EXISTS `detalle` (
  `detalleId` int(11) NOT NULL,
  `productoId` int(11) DEFAULT NULL,
  `cantidad` int(11) DEFAULT NULL,
  `ventaId` int(11) DEFAULT NULL,
  `precio` decimal(5,2) DEFAULT NULL,
  `colorId` int(11) DEFAULT NULL,
  PRIMARY KEY (`detalleId`),
  KEY `ventaId` (`ventaId`),
  KEY `productoId` (`productoId`),
  KEY `colorId` (`colorId`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `empleados`
--

CREATE TABLE IF NOT EXISTS `empleados` (
  `empleadoId` int(11) NOT NULL,
  `nombreEmpleado` varchar(30) DEFAULT NULL,
  `perfilId` int(11) DEFAULT NULL,
  PRIMARY KEY (`empleadoId`),
  KEY `perfilId` (`perfilId`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `empleados`
--

INSERT INTO `empleados` (`empleadoId`, `nombreEmpleado`, `perfilId`) VALUES
(10, 'rafa nadal', 10),
(33067198, 'segundo emple', NULL),
(1, 'hola mundo', 11),
(2, 'chau mundo', 10);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `facturas`
--

CREATE TABLE IF NOT EXISTS `facturas` (
  `facturaId` int(11) NOT NULL,
  `numeroFactura` int(11) DEFAULT NULL,
  `tipoFacturaId` int(11) NOT NULL,
  PRIMARY KEY (`facturaId`),
  KEY `tipoFacturaId` (`tipoFacturaId`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `gama`
--

CREATE TABLE IF NOT EXISTS `gama` (
  `gamaId` int(11) NOT NULL,
  `nombreGama` varchar(30) DEFAULT NULL,
  `imagen` varchar(90) DEFAULT NULL,
  PRIMARY KEY (`gamaId`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `ingresos`
--

CREATE TABLE IF NOT EXISTS `ingresos` (
  `ingresosId` int(11) NOT NULL,
  `productoId` int(11) DEFAULT NULL,
  `fecha` date DEFAULT NULL,
  `cantidad` int(11) DEFAULT NULL,
  PRIMARY KEY (`ingresosId`),
  KEY `productoId` (`productoId`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `localidades`
--

CREATE TABLE IF NOT EXISTS `localidades` (
  `localidadId` int(11) NOT NULL,
  `codigoPostal` int(11) NOT NULL,
  `nombreLocalidad` varchar(30) DEFAULT NULL,
  PRIMARY KEY (`localidadId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `marca`
--

CREATE TABLE IF NOT EXISTS `marca` (
  `marcaId` int(11) NOT NULL,
  `nombreMarca` varchar(30) DEFAULT NULL,
  PRIMARY KEY (`marcaId`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `perfiles`
--

CREATE TABLE IF NOT EXISTS `perfiles` (
  `perfilId` int(11) NOT NULL,
  `nombrePerfil` varchar(30) DEFAULT NULL,
  PRIMARY KEY (`perfilId`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `perfiles`
--

INSERT INTO `perfiles` (`perfilId`, `nombrePerfil`) VALUES
(10, 'Administrador'),
(11, 'Vendedor'),
(12, 'Inspector'),
(1, 'raso');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `productos`
--

CREATE TABLE IF NOT EXISTS `productos` (
  `productoId` int(11) NOT NULL,
  `codigoProducto` int(11) DEFAULT NULL,
  `nombreProducto` varchar(30) DEFAULT NULL,
  `descripcion` varchar(120) DEFAULT NULL,
  `precio` decimal(5,2) DEFAULT NULL,
  `cantidad` int(11) DEFAULT NULL,
  `stockMinimo` int(11) DEFAULT NULL,
  `marcaId` int(11) DEFAULT NULL,
  `tipoProductoId` int(11) DEFAULT NULL,
  PRIMARY KEY (`productoId`),
  KEY `marcaId` (`marcaId`),
  KEY `tipoProductoId` (`tipoProductoId`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `sociedades`
--

CREATE TABLE IF NOT EXISTS `sociedades` (
  `sociedadId` int(11) NOT NULL,
  `nombreSociedad` varchar(30) NOT NULL,
  PRIMARY KEY (`sociedadId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tiposAtributosDeProductos`
--

CREATE TABLE IF NOT EXISTS `tiposAtributosDeProductos` (
  `tiposAtributosDeProductosId` int(11) NOT NULL,
  `tipoProductoId` int(11) DEFAULT NULL,
  `atributoId` int(11) DEFAULT NULL,
  PRIMARY KEY (`tiposAtributosDeProductosId`),
  KEY `tipoProductoId` (`tipoProductoId`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tiposCliente`
--

CREATE TABLE IF NOT EXISTS `tiposCliente` (
  `tipoClienteId` int(11) NOT NULL,
  `nombreTipoCliente` varchar(30) DEFAULT NULL,
  `tipoFacturaId` int(11) NOT NULL,
  PRIMARY KEY (`tipoClienteId`),
  KEY `tipoFacturaId` (`tipoFacturaId`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tiposFactura`
--

CREATE TABLE IF NOT EXISTS `tiposFactura` (
  `tipoFacturaId` int(11) NOT NULL,
  `nombreTipoFactura` varchar(30) DEFAULT NULL,
  `iva` varchar(10) DEFAULT NULL,
  PRIMARY KEY (`tipoFacturaId`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tiposProducto`
--

CREATE TABLE IF NOT EXISTS `tiposProducto` (
  `tipoProductoId` int(11) NOT NULL,
  `tipoProducto` varchar(30) DEFAULT NULL,
  `esColoreable` tinyint(1) DEFAULT NULL,
  `stockMinimoPorDefecto` int(11) DEFAULT NULL,
  PRIMARY KEY (`tipoProductoId`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tiposVenta`
--

CREATE TABLE IF NOT EXISTS `tiposVenta` (
  `tipoVentaId` int(11) NOT NULL,
  `nombreTipoVenta` varchar(30) DEFAULT NULL,
  PRIMARY KEY (`tipoVentaId`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `venta`
--

CREATE TABLE IF NOT EXISTS `venta` (
  `ventaId` int(11) NOT NULL,
  `nombreCliente` varchar(30) DEFAULT NULL,
  `fechaVenta` date NOT NULL,
  `fechaVencimiento` date DEFAULT NULL,
  `facturaId` int(11) NOT NULL,
  `tipoVentaId` int(11) DEFAULT NULL,
  `empleadoId` int(11) DEFAULT NULL,
  `clienteId` int(11) NOT NULL,
  PRIMARY KEY (`ventaId`),
  KEY `clienteId` (`clienteId`),
  KEY `tipoVentaId` (`tipoVentaId`),
  KEY `empleadoId` (`empleadoId`),
  KEY `facturaId` (`facturaId`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
