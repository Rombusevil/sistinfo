-- phpMyAdmin SQL Dump
-- version 3.4.11.1deb2+deb7u1
-- http://www.phpmyadmin.net
--
-- Servidor: localhost
-- Tiempo de generación: 14-12-2015 a las 23:10:40
-- Versión del servidor: 5.5.41
-- Versión de PHP: 5.4.41-0+deb7u1

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
-- Estructura de tabla para la tabla `accessright`
--
-- Creación: 07-04-2015 a las 02:11:24
--

CREATE TABLE IF NOT EXISTS `accessright` (
  `node` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `action` varchar(25) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `role_id` int(10) NOT NULL,
  PRIMARY KEY (`node`,`action`,`role_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `accessright`
--

INSERT INTO `accessright` (`node`, `action`, `role_id`) VALUES
('basedatos.basedatos', 'view', 1),
('basedatos.basedatos', 'view', 3),
('clientes.clientes', 'add', 1),
('clientes.clientes', 'add', 3),
('clientes.clientes', 'add', 4),
('clientes.clientes', 'admin', 1),
('clientes.clientes', 'admin', 3),
('clientes.clientes', 'admin', 4),
('clientes.clientes', 'delete', 1),
('clientes.clientes', 'delete', 3),
('clientes.clientes', 'edit', 1),
('clientes.clientes', 'edit', 3),
('clientes.localidades', 'add', 1),
('clientes.localidades', 'add', 3),
('clientes.localidades', 'admin', 1),
('clientes.localidades', 'admin', 3),
('clientes.localidades', 'delete', 1),
('clientes.localidades', 'delete', 3),
('clientes.localidades', 'edit', 1),
('clientes.localidades', 'edit', 3),
('clientes.sociedades', 'add', 1),
('clientes.sociedades', 'add', 3),
('clientes.sociedades', 'admin', 1),
('clientes.sociedades', 'admin', 3),
('clientes.sociedades', 'delete', 1),
('clientes.sociedades', 'delete', 3),
('clientes.sociedades', 'edit', 1),
('clientes.sociedades', 'edit', 3),
('clientes.tiposCliente', 'add', 1),
('clientes.tiposCliente', 'add', 3),
('clientes.tiposCliente', 'admin', 1),
('clientes.tiposCliente', 'admin', 3),
('clientes.tiposCliente', 'delete', 1),
('clientes.tiposCliente', 'delete', 3),
('clientes.tiposCliente', 'edit', 1),
('clientes.tiposCliente', 'edit', 3),
('color.color', 'add', 1),
('color.color', 'add', 3),
('color.color', 'admin', 1),
('color.color', 'admin', 3),
('color.color', 'delete', 1),
('color.color', 'delete', 3),
('color.color', 'edit', 1),
('color.color', 'edit', 3),
('color.composicionColores', 'add', 1),
('color.composicionColores', 'add', 3),
('color.composicionColores', 'admin', 1),
('color.composicionColores', 'admin', 3),
('color.composicionColores', 'delete', 1),
('color.composicionColores', 'delete', 3),
('color.composicionColores', 'edit', 1),
('color.composicionColores', 'edit', 3),
('color.gama', 'add', 1),
('color.gama', 'add', 3),
('color.gama', 'admin', 1),
('color.gama', 'admin', 3),
('color.gama', 'delete', 1),
('color.gama', 'delete', 3),
('color.gama', 'edit', 1),
('color.gama', 'edit', 3),
('employee.department', 'add', 1),
('employee.department', 'add', 3),
('employee.department', 'admin', 1),
('employee.department', 'admin', 3),
('employee.department', 'delete', 1),
('employee.department', 'delete', 3),
('employee.department', 'edit', 1),
('employee.department', 'edit', 3),
('employee.employee', 'add', 1),
('employee.employee', 'add', 3),
('employee.employee', 'admin', 1),
('employee.employee', 'admin', 3),
('employee.employee', 'delete', 1),
('employee.employee', 'delete', 3),
('employee.employee', 'edit', 1),
('employee.employee', 'edit', 3),
('employee.employee', 'stats', 1),
('employee.employee', 'stats', 3),
('employee.employee', 'view_all', 1),
('employee.employee', 'view_all', 3),
('employee.functionlevel', 'add', 1),
('employee.functionlevel', 'add', 3),
('employee.functionlevel', 'admin', 1),
('employee.functionlevel', 'admin', 3),
('employee.functionlevel', 'delete', 1),
('employee.functionlevel', 'delete', 3),
('employee.functionlevel', 'edit', 1),
('employee.functionlevel', 'edit', 3),
('employee.profile', 'add', 1),
('employee.profile', 'add', 3),
('employee.profile', 'admin', 1),
('employee.profile', 'admin', 3),
('employee.profile', 'delete', 1),
('employee.profile', 'delete', 3),
('employee.profile', 'edit', 1),
('employee.profile', 'edit', 3),
('employee.profile', 'grantall', 1),
('employee.profile', 'grantall', 3),
('employee.usercontracts', 'add', 1),
('employee.usercontracts', 'add', 3),
('employee.usercontracts', 'admin', 1),
('employee.usercontracts', 'admin', 3),
('employee.usercontracts', 'delete', 1),
('employee.usercontracts', 'delete', 3),
('employee.usercontracts', 'edit', 1),
('employee.usercontracts', 'edit', 3),
('employee.userprefs', 'edit', 1),
('employee.userprefs', 'edit', 3),
('organization.contact', 'add', 3),
('organization.contact', 'admin', 3),
('organization.contact', 'delete', 3),
('organization.contact', 'edit', 3),
('organization.contracts', 'add', 3),
('organization.contracts', 'admin', 3),
('organization.contracts', 'delete', 3),
('organization.contracts', 'edit', 3),
('organization.contracttype', 'add', 3),
('organization.contracttype', 'admin', 3),
('organization.contracttype', 'delete', 3),
('organization.contracttype', 'edit', 3),
('organization.organization', 'add', 3),
('organization.organization', 'admin', 3),
('organization.organization', 'delete', 3),
('organization.organization', 'document', 3),
('organization.organization', 'edit', 3),
('productos.atributosDeProductos', 'add', 1),
('productos.atributosDeProductos', 'add', 3),
('productos.atributosDeProductos', 'admin', 1),
('productos.atributosDeProductos', 'admin', 3),
('productos.atributosDeProductos', 'delete', 1),
('productos.atributosDeProductos', 'delete', 3),
('productos.atributosDeProductos', 'edit', 1),
('productos.atributosDeProductos', 'edit', 3),
('productos.datosProductos', 'admin', 1),
('productos.datosProductos', 'admin', 3),
('productos.datosProductos', 'edit', 1),
('productos.datosProductos', 'edit', 3),
('productos.manejoStock', 'add', 1),
('productos.manejoStock', 'add', 3),
('productos.manejoStock', 'admin', 1),
('productos.manejoStock', 'admin', 3),
('productos.manejoStock', 'delete', 1),
('productos.manejoStock', 'delete', 3),
('productos.manejoStock', 'edit', 1),
('productos.manejoStock', 'edit', 3),
('productos.marca', 'add', 1),
('productos.marca', 'add', 3),
('productos.marca', 'admin', 1),
('productos.marca', 'admin', 3),
('productos.marca', 'delete', 1),
('productos.marca', 'delete', 3),
('productos.marca', 'edit', 1),
('productos.marca', 'edit', 3),
('productos.productos', 'add', 1),
('productos.productos', 'add', 3),
('productos.productos', 'admin', 1),
('productos.productos', 'admin', 3),
('productos.productos', 'delete', 1),
('productos.productos', 'delete', 3),
('productos.productos', 'edit', 1),
('productos.productos', 'edit', 3),
('productos.productos', 'mra_editar_precio', 1),
('productos.productos', 'mra_editar_precio', 3),
('productos.tipoMovimiento', 'add', 1),
('productos.tipoMovimiento', 'add', 3),
('productos.tipoMovimiento', 'admin', 1),
('productos.tipoMovimiento', 'admin', 3),
('productos.tipoMovimiento', 'delete', 1),
('productos.tipoMovimiento', 'delete', 3),
('productos.tipoMovimiento', 'edit', 1),
('productos.tipoMovimiento', 'edit', 3),
('productos.tiposAtributosDeProductos', 'add', 1),
('productos.tiposAtributosDeProductos', 'add', 3),
('productos.tiposAtributosDeProductos', 'admin', 1),
('productos.tiposAtributosDeProductos', 'admin', 3),
('productos.tiposAtributosDeProductos', 'delete', 1),
('productos.tiposAtributosDeProductos', 'delete', 3),
('productos.tiposAtributosDeProductos', 'edit', 1),
('productos.tiposAtributosDeProductos', 'edit', 3),
('productos.tiposProducto', 'add', 1),
('productos.tiposProducto', 'add', 3),
('productos.tiposProducto', 'admin', 1),
('productos.tiposProducto', 'admin', 3),
('productos.tiposProducto', 'delete', 1),
('productos.tiposProducto', 'delete', 3),
('productos.tiposProducto', 'edit', 1),
('productos.tiposProducto', 'edit', 3),
('scheduler.scheduler', 'add', 3),
('scheduler.scheduler', 'admin', 3),
('scheduler.scheduler', 'all_non_private', 3),
('scheduler.scheduler', 'delete', 3),
('scheduler.scheduler', 'edit', 3),
('scheduler.scheduler_category', 'add', 3),
('scheduler.scheduler_category', 'admin', 3),
('scheduler.scheduler_category', 'delete', 3),
('scheduler.scheduler_category', 'edit', 3),
('scheduler.scheduler_email_template', 'admin', 3),
('scheduler.scheduler_email_template', 'edit', 3),
('scheduler.scheduler_holidays', 'add', 3),
('scheduler.scheduler_holidays', 'admin', 3),
('scheduler.scheduler_holidays', 'delete', 3),
('scheduler.scheduler_holidays', 'edit', 3),
('ventas.detalle', 'add', 1),
('ventas.detalle', 'add', 3),
('ventas.detalle', 'add', 4),
('ventas.detalle', 'admin', 1),
('ventas.detalle', 'admin', 3),
('ventas.detalle', 'admin', 4),
('ventas.detalle', 'admin', 5),
('ventas.detalle', 'delete', 1),
('ventas.detalle', 'delete', 3),
('ventas.detalle', 'delete', 4),
('ventas.detalle', 'edit', 1),
('ventas.detalle', 'edit', 3),
('ventas.detalle', 'edit', 4),
('ventas.facturas', 'admin', 5),
('ventas.ivas', 'add', 1),
('ventas.ivas', 'add', 3),
('ventas.ivas', 'admin', 1),
('ventas.ivas', 'admin', 3),
('ventas.ivas', 'admin', 5),
('ventas.ivas', 'delete', 1),
('ventas.ivas', 'delete', 3),
('ventas.ivas', 'edit', 1),
('ventas.ivas', 'edit', 3),
('ventas.tiposFactura', 'add', 1),
('ventas.tiposFactura', 'add', 3),
('ventas.tiposFactura', 'admin', 1),
('ventas.tiposFactura', 'admin', 3),
('ventas.tiposFactura', 'admin', 5),
('ventas.tiposFactura', 'delete', 1),
('ventas.tiposFactura', 'delete', 3),
('ventas.tiposFactura', 'edit', 1),
('ventas.tiposFactura', 'edit', 3),
('ventas.tiposVenta', 'admin', 1),
('ventas.tiposVenta', 'admin', 3),
('ventas.tiposVenta', 'admin', 5),
('ventas.ventas', 'add', 1),
('ventas.ventas', 'add', 3),
('ventas.ventas', 'add', 4),
('ventas.ventas', 'admin', 1),
('ventas.ventas', 'admin', 3),
('ventas.ventas', 'admin', 4),
('ventas.ventas', 'admin', 5),
('ventas.ventas', 'cierraVenta', 1),
('ventas.ventas', 'delete', 1),
('ventas.ventas', 'delete', 3),
('ventas.ventas', 'delete', 4),
('ventas.ventas', 'edit', 1),
('ventas.ventas', 'edit', 3),
('ventas.ventas', 'edit', 4);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `atributosDeProductos`
--
-- Creación: 31-10-2015 a las 23:05:23
--

CREATE TABLE IF NOT EXISTS `atributosDeProductos` (
  `atributoId` int(11) NOT NULL DEFAULT '0',
  `nombreAtributo` varchar(30) DEFAULT NULL,
  `tipoAtributo` varchar(11) DEFAULT NULL,
  PRIMARY KEY (`atributoId`),
  KEY `tipoAtributo` (`tipoAtributo`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `atributosDeProductos`
--

INSERT INTO `atributosDeProductos` (`atributoId`, `nombreAtributo`, `tipoAtributo`) VALUES
(1, 'Largo', 'mm'),
(2, 'Capacidad', 'Lts'),
(3, 'Grano', 'grano'),
(4, 'Haz de pelo', 'haz'),
(5, 'Forma pincel', 'forma');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `clientes`
--
-- Creación: 31-10-2015 a las 23:05:23
--

CREATE TABLE IF NOT EXISTS `clientes` (
  `clienteId` int(11) NOT NULL DEFAULT '0',
  `cuitCuil` varchar(20) DEFAULT NULL,
  `razonSocial` varchar(50) DEFAULT NULL,
  `correoElectronico` varchar(80) DEFAULT NULL,
  `telefono` varchar(50) DEFAULT NULL,
  `direccion` varchar(50) DEFAULT NULL,
  `tipoClienteId` int(11) DEFAULT NULL,
  `sociedadId` int(11) DEFAULT NULL,
  `localidadId` int(11) DEFAULT NULL,
  PRIMARY KEY (`clienteId`),
  KEY `localidadId` (`localidadId`),
  KEY `tipoClienteId` (`tipoClienteId`),
  KEY `sociedadId` (`sociedadId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `color`
--
-- Creación: 31-10-2015 a las 23:05:24
--

CREATE TABLE IF NOT EXISTS `color` (
  `colorId` int(11) NOT NULL DEFAULT '0',
  `codigoColor` int(11) DEFAULT NULL,
  `imagen` varchar(90) DEFAULT NULL,
  `gamaId` int(11) DEFAULT NULL,
  `composicionId` int(11) DEFAULT NULL,
  PRIMARY KEY (`colorId`),
  KEY `gamaId` (`gamaId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `composicionColores`
--
-- Creación: 31-10-2015 a las 23:05:24
--

CREATE TABLE IF NOT EXISTS `composicionColores` (
  `id` int(11) NOT NULL DEFAULT '0',
  `colorPrimario` int(11) DEFAULT NULL,
  `colorSecundario` int(11) DEFAULT NULL,
  `porcentaje` float DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `colorPrimario` (`colorPrimario`),
  KEY `colorSecundario` (`colorSecundario`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `datosProductos`
--
-- Creación: 15-12-2015 a las 02:03:55
--

CREATE TABLE IF NOT EXISTS `datosProductos` (
  `datosProductosId` int(11) NOT NULL DEFAULT '0',
  `productoId` int(11) DEFAULT NULL,
  `nombreAtributo` varchar(30) DEFAULT NULL,
  `valorAtributo` int(11) DEFAULT NULL,
  `tipoAtributo` varchar(30) DEFAULT NULL,
  PRIMARY KEY (`datosProductosId`),
  KEY `productoId` (`productoId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `db_sequence`
--
-- Creación: 07-04-2015 a las 02:11:24
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
('atributosDeProductos', 5),
('gama', 4),
('ivas', 3),
('person', 1),
('profile', 1),
('tiposFactura', 4),
('userpimitems', 3);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `detalle`
--
-- Creación: 31-10-2015 a las 23:05:24
--

CREATE TABLE IF NOT EXISTS `detalle` (
  `detalleId` int(11) NOT NULL DEFAULT '0',
  `productoId` int(11) DEFAULT NULL,
  `cantidad` int(11) DEFAULT NULL,
  `ventaId` int(11) DEFAULT NULL,
  `precioIVA` decimal(5,2) DEFAULT NULL,
  `colorId` int(11) DEFAULT NULL,
  `precioSinIVA` decimal(5,2) DEFAULT NULL,
  PRIMARY KEY (`detalleId`),
  KEY `ventaId` (`ventaId`),
  KEY `productoId` (`productoId`),
  KEY `colorId` (`colorId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `empleados`
--
-- Creación: 31-10-2015 a las 23:05:24
--

CREATE TABLE IF NOT EXISTS `empleados` (
  `empleadoId` int(11) NOT NULL DEFAULT '0',
  `nombreEmpleado` varchar(30) DEFAULT NULL,
  `perfilId` int(11) DEFAULT NULL,
  PRIMARY KEY (`empleadoId`),
  KEY `perfilId` (`perfilId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `employeerole`
--
-- Creación: 07-04-2015 a las 02:11:24
--

CREATE TABLE IF NOT EXISTS `employeerole` (
  `employee_id` int(10) NOT NULL,
  `role_id` int(10) NOT NULL,
  PRIMARY KEY (`employee_id`,`role_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `employeerole`
--

INSERT INTO `employeerole` (`employee_id`, `role_id`) VALUES
(1, 1);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `employee_department`
--
-- Creación: 07-04-2015 a las 02:11:24
--

CREATE TABLE IF NOT EXISTS `employee_department` (
  `id` int(10) NOT NULL,
  `name` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `description` text,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `facturas`
--
-- Creación: 31-10-2015 a las 23:05:24
--

CREATE TABLE IF NOT EXISTS `facturas` (
  `facturaId` int(11) NOT NULL DEFAULT '0',
  `numeroFactura` int(11) DEFAULT NULL,
  `tipoFacturaId` int(11) DEFAULT NULL,
  PRIMARY KEY (`facturaId`),
  KEY `tipoFacturaId` (`tipoFacturaId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `functionlevel`
--
-- Creación: 07-04-2015 a las 02:11:25
--

CREATE TABLE IF NOT EXISTS `functionlevel` (
  `id` int(10) NOT NULL,
  `name` varchar(50) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `description` text,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `gama`
--
-- Creación: 31-10-2015 a las 23:05:25
--

CREATE TABLE IF NOT EXISTS `gama` (
  `gamaId` int(11) NOT NULL DEFAULT '0',
  `nombreGama` varchar(30) DEFAULT NULL,
  `imagen` varchar(90) DEFAULT NULL,
  PRIMARY KEY (`gamaId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `gama`
--

INSERT INTO `gama` (`gamaId`, `nombreGama`, `imagen`) VALUES
(1, 'Azul', '#0000FF'),
(2, 'Verde', '#00FF00'),
(3, 'Amarillo', '#FFFF00'),
(4, 'Rojo', '#FF0000');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `ivas`
--
-- Creación: 31-10-2015 a las 23:05:25
--

CREATE TABLE IF NOT EXISTS `ivas` (
  `id` int(11) DEFAULT NULL,
  `fechaVigencia` date DEFAULT NULL,
  `valorIva` decimal(5,2) DEFAULT NULL,
  `tipoFacturaId` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `ivas`
--

INSERT INTO `ivas` (`id`, `fechaVigencia`, `valorIva`, `tipoFacturaId`) VALUES
(1, '1995-04-03', 21.00, 1),
(2, '1995-04-03', 21.00, 2),
(3, '1995-04-03', 21.00, 3);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `localidades`
--
-- Creación: 31-10-2015 a las 23:05:25
--

CREATE TABLE IF NOT EXISTS `localidades` (
  `localidadId` int(11) NOT NULL DEFAULT '0',
  `codigoPostal` int(11) DEFAULT NULL,
  `nombreLocalidad` varchar(30) DEFAULT NULL,
  PRIMARY KEY (`localidadId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `manejoStock`
--
-- Creación: 31-10-2015 a las 23:05:26
--

CREATE TABLE IF NOT EXISTS `manejoStock` (
  `id` int(11) NOT NULL DEFAULT '0',
  `productoId` int(11) DEFAULT NULL,
  `fecha` timestamp NULL DEFAULT NULL,
  `cantidad` int(11) DEFAULT NULL,
  `tipoMovimientoId` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `productoId` (`productoId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `marca`
--
-- Creación: 31-10-2015 a las 23:05:26
--

CREATE TABLE IF NOT EXISTS `marca` (
  `marcaId` int(11) NOT NULL DEFAULT '0',
  `nombreMarca` varchar(30) DEFAULT NULL,
  PRIMARY KEY (`marcaId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `organization`
--
-- Creación: 07-04-2015 a las 02:11:25
--

CREATE TABLE IF NOT EXISTS `organization` (
  `id` int(10) NOT NULL,
  `organizationcode` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `name` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `type` varchar(8) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `visit_address` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `visit_address2` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `visit_zipcode` varchar(20) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `visit_city` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `visit_state` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `visit_country` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `mail_address` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `mail_address2` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `mail_zipcode` varchar(20) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `mail_city` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `mail_state` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `mail_country` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `invoice_address` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `invoice_address2` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `invoice_zipcode` varchar(20) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `invoice_city` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `invoice_state` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `invoice_country` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `phone` varchar(20) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `fax` varchar(20) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `email` varchar(50) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `website` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `bankaccount` varchar(30) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `bankaccount2` varchar(30) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `bankaccount3` varchar(30) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `bankaccount4` varchar(30) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `vatnumber` varchar(25) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `debtornumber` varchar(30) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `member_of` int(10) DEFAULT NULL,
  `status` int(10) DEFAULT NULL,
  `source` int(10) DEFAULT NULL,
  `industry` int(10) DEFAULT NULL,
  `employees` int(5) DEFAULT NULL,
  `revenue` varchar(5) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `rate` int(10) DEFAULT NULL,
  `assigned_to` int(10) DEFAULT NULL,
  `remark` text,
  `created_by` int(10) DEFAULT NULL,
  `created_on` datetime DEFAULT NULL,
  `last_modified_by` int(10) DEFAULT NULL,
  `last_modified_on` datetime DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `perfiles`
--
-- Creación: 31-10-2015 a las 23:05:26
--

CREATE TABLE IF NOT EXISTS `perfiles` (
  `perfilId` int(11) NOT NULL DEFAULT '0',
  `nombrePerfil` varchar(30) DEFAULT NULL,
  PRIMARY KEY (`perfilId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `person`
--
-- Creación: 07-04-2015 a las 02:11:25
--

CREATE TABLE IF NOT EXISTS `person` (
  `id` int(10) NOT NULL,
  `title_id` int(10) DEFAULT NULL,
  `userid` varchar(15) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `lastname` varchar(50) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `firstname` varchar(50) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `initials` varchar(50) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `address` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `zipcode` varchar(20) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `city` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `state` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `country` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `phone` varchar(20) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `cellular` varchar(20) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `fax` varchar(20) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `email` varchar(50) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `function` varchar(50) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `remark` text,
  `role` varchar(15) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `created_by` int(11) DEFAULT NULL,
  `created_on` datetime DEFAULT NULL,
  `last_modified_by` int(11) DEFAULT NULL,
  `last_modified_on` datetime DEFAULT NULL,
  `birthdate` date DEFAULT NULL,
  `bankaccount` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `socialsecuritynumber` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `employer_id` int(10) DEFAULT NULL,
  `department` int(10) DEFAULT NULL,
  `supervisor` int(10) DEFAULT NULL,
  `functionlevel` int(10) DEFAULT NULL,
  `status` varchar(9) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `lng` varchar(2) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `password` varchar(40) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `theme` varchar(14) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `company` int(10) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `person`
--

INSERT INTO `person` (`id`, `title_id`, `userid`, `lastname`, `firstname`, `initials`, `address`, `zipcode`, `city`, `state`, `country`, `phone`, `cellular`, `fax`, `email`, `function`, `remark`, `role`, `created_by`, `created_on`, `last_modified_by`, `last_modified_on`, `birthdate`, `bankaccount`, `socialsecuritynumber`, `employer_id`, `department`, `supervisor`, `functionlevel`, `status`, `lng`, `password`, `theme`, `company`) VALUES
(1, NULL, 'admin', 'Administrador', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, '', 'employee', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'active', 'es', '21232f297a57a5a743894a0e4a801fc3', NULL, NULL);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `productos`
--
-- Creación: 31-10-2015 a las 23:05:26
--

CREATE TABLE IF NOT EXISTS `productos` (
  `id` int(11) NOT NULL DEFAULT '0',
  `codigoProducto` int(11) DEFAULT NULL,
  `nombreProducto` varchar(30) DEFAULT NULL,
  `descripcion` varchar(120) DEFAULT NULL,
  `precio` decimal(5,2) DEFAULT NULL,
  `cantidad` int(11) DEFAULT NULL,
  `stockMinimo` int(11) DEFAULT NULL,
  `marcaId` int(11) DEFAULT NULL,
  `tipoProductoId` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `marcaId` (`marcaId`),
  KEY `tipoProductoId` (`tipoProductoId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `profile`
--
-- Creación: 07-04-2015 a las 02:11:25
--

CREATE TABLE IF NOT EXISTS `profile` (
  `id` int(10) NOT NULL,
  `name` varchar(50) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `profile`
--

INSERT INTO `profile` (`id`, `name`) VALUES
(1, 'Administrador');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `role`
--
-- Creación: 07-04-2015 a las 02:11:26
--

CREATE TABLE IF NOT EXISTS `role` (
  `id` int(10) NOT NULL,
  `name` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `description` text NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `scheduler_alarms`
--
-- Creación: 07-04-2015 a las 02:11:26
--

CREATE TABLE IF NOT EXISTS `scheduler_alarms` (
  `scheduler_id` int(10) NOT NULL,
  `startdate` int(10) NOT NULL,
  `duration` int(10) DEFAULT NULL,
  `senddate` int(10) DEFAULT NULL,
  `send` int(1) DEFAULT NULL,
  `type` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `userid` int(2) NOT NULL,
  `owner` int(10) DEFAULT NULL,
  PRIMARY KEY (`scheduler_id`,`startdate`,`userid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `scheduler_attendees`
--
-- Creación: 07-04-2015 a las 02:11:26
--

CREATE TABLE IF NOT EXISTS `scheduler_attendees` (
  `scheduler_id` int(10) NOT NULL,
  `person_id` int(10) NOT NULL,
  `status` varchar(11) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  PRIMARY KEY (`scheduler_id`,`person_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `scheduler_category`
--
-- Creación: 07-04-2015 a las 02:11:26
--

CREATE TABLE IF NOT EXISTS `scheduler_category` (
  `id` int(10) NOT NULL,
  `description` varchar(50) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `bgcolor` varchar(10) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `fgcolor` varchar(10) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `scheduler_cyclus`
--
-- Creación: 07-04-2015 a las 02:11:26
--

CREATE TABLE IF NOT EXISTS `scheduler_cyclus` (
  `scheduler_id` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `monthly_day` int(2) DEFAULT NULL,
  `yearly_day` int(2) DEFAULT NULL,
  `yearly_month` int(2) DEFAULT NULL,
  `yearly_month2` int(2) DEFAULT NULL,
  `daily_every` int(10) DEFAULT NULL,
  `weekly_every` int(10) DEFAULT NULL,
  `monthly_every` int(10) DEFAULT NULL,
  `monthly_every2` int(10) DEFAULT NULL,
  `monthly_month_time` int(2) DEFAULT NULL,
  `yearly_month_time` int(2) DEFAULT NULL,
  `weekly_weekday` int(17) DEFAULT NULL,
  `monthly_weekday_list` int(1) DEFAULT NULL,
  `yearly_weekday_list` int(1) DEFAULT NULL,
  `daily_choice` int(10) DEFAULT NULL,
  `monthly_choice` int(10) DEFAULT NULL,
  `yearly_choice` int(10) DEFAULT NULL,
  `end_choice` int(10) DEFAULT NULL,
  `cyclus_enddate` date DEFAULT NULL,
  `cyclus_times` int(10) DEFAULT NULL,
  PRIMARY KEY (`scheduler_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `scheduler_cyclus_not`
--
-- Creación: 07-04-2015 a las 02:11:26
--

CREATE TABLE IF NOT EXISTS `scheduler_cyclus_not` (
  `scheduler_id` int(10) NOT NULL,
  `date` int(10) NOT NULL,
  PRIMARY KEY (`scheduler_id`,`date`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `scheduler_dates`
--
-- Creación: 07-04-2015 a las 02:11:26
--

CREATE TABLE IF NOT EXISTS `scheduler_dates` (
  `scheduler_id` int(10) NOT NULL,
  `startdate` int(10) NOT NULL,
  `enddate` int(10) DEFAULT NULL,
  PRIMARY KEY (`scheduler_id`,`startdate`),
  KEY `enddate_idx` (`enddate`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `scheduler_group`
--
-- Creación: 07-04-2015 a las 02:11:26
--

CREATE TABLE IF NOT EXISTS `scheduler_group` (
  `id` int(10) NOT NULL,
  `userid` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `name` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `scheduler_group_member`
--
-- Creación: 07-04-2015 a las 02:11:26
--

CREATE TABLE IF NOT EXISTS `scheduler_group_member` (
  `groupid` int(10) NOT NULL,
  `userid` int(10) NOT NULL,
  PRIMARY KEY (`groupid`,`userid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `scheduler_holidays`
--
-- Creación: 07-04-2015 a las 02:11:27
--

CREATE TABLE IF NOT EXISTS `scheduler_holidays` (
  `id` int(10) NOT NULL,
  `name` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `type` varchar(7) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `day` int(2) DEFAULT NULL,
  `month` int(2) DEFAULT NULL,
  `special` varchar(6) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `day_offset` int(3) DEFAULT NULL,
  `length` int(2) DEFAULT NULL,
  `weekday` int(1) DEFAULT NULL,
  `moveto` int(1) DEFAULT NULL,
  `schedulecategory` int(10) NOT NULL,
  `country` varchar(2) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `scheduler_notes`
--
-- Creación: 07-04-2015 a las 02:11:27
--

CREATE TABLE IF NOT EXISTS `scheduler_notes` (
  `id` int(10) NOT NULL,
  `owner` int(10) NOT NULL,
  `scheduler_id` int(10) NOT NULL,
  `entrydate` date NOT NULL,
  `title` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `description` text NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `scheduler_scheduler`
--
-- Creación: 07-04-2015 a las 02:11:27
--

CREATE TABLE IF NOT EXISTS `scheduler_scheduler` (
  `id` int(10) NOT NULL,
  `title` varchar(50) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `location` varchar(50) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `description` text,
  `recur` varchar(7) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `startdate` date DEFAULT NULL,
  `enddate` date DEFAULT NULL,
  `allday` int(1) DEFAULT NULL,
  `starttime` time DEFAULT NULL,
  `endtime` time DEFAULT NULL,
  `category` int(10) NOT NULL,
  `all_users` int(1) DEFAULT NULL,
  `priority` int(1) DEFAULT NULL,
  `private` int(1) DEFAULT NULL,
  `nonblocking` int(1) DEFAULT NULL,
  `owner` int(10) NOT NULL,
  `owner_attendee` int(1) DEFAULT NULL,
  `lastdate` int(10) DEFAULT NULL,
  `times` int(10) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `scheduler_userassistants`
--
-- Creación: 07-04-2015 a las 02:11:27
--

CREATE TABLE IF NOT EXISTS `scheduler_userassistants` (
  `userid` int(10) NOT NULL,
  `employeeid` int(10) NOT NULL,
  PRIMARY KEY (`userid`,`employeeid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `scheduler_userpreferences`
--
-- Creación: 07-04-2015 a las 02:11:27
--

CREATE TABLE IF NOT EXISTS `scheduler_userpreferences` (
  `userid` int(10) NOT NULL,
  `timeschedule` int(2) NOT NULL,
  `showweeknumbers` int(1) DEFAULT NULL,
  `showtodo` int(1) DEFAULT NULL,
  `showemployeebirthdays` int(1) DEFAULT NULL,
  `showlunarphases` int(1) DEFAULT NULL,
  `autorefresh` int(1) DEFAULT NULL,
  `refresh_interval` int(10) DEFAULT NULL,
  `default_view` varchar(5) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `default_userview` varchar(25) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `default_eventtime` time DEFAULT NULL,
  `default_category` int(10) DEFAULT NULL,
  `scheduler_emptycolor` varchar(10) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `scheduler_emptyworkhourscolor` varchar(10) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  PRIMARY KEY (`userid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `scheduler_userpreferences`
--

INSERT INTO `scheduler_userpreferences` (`userid`, `timeschedule`, `showweeknumbers`, `showtodo`, `showemployeebirthdays`, `showlunarphases`, `autorefresh`, `refresh_interval`, `default_view`, `default_userview`, `default_eventtime`, `default_category`, `scheduler_emptycolor`, `scheduler_emptyworkhourscolor`) VALUES
(1, 30, 0, 0, 0, NULL, 0, 0, 'day', '1', '01:00:00', NULL, '#DDDDDD', '#FFFFFF'),
(5, 30, 0, 0, 0, 0, 0, 0, 'day', '5', '01:00:00', NULL, '#DDDDDD', '#FFFFFF'),
(6, 30, 0, 0, 0, NULL, 0, 0, 'day', '6', '01:00:00', NULL, '#DDDDDD', '#FFFFFF'),
(8, 30, 0, 0, 0, NULL, 0, 0, 'day', '8', '01:00:00', NULL, '#DDDDDD', '#FFFFFF');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `sociedades`
--
-- Creación: 31-10-2015 a las 23:05:26
--

CREATE TABLE IF NOT EXISTS `sociedades` (
  `sociedadId` int(11) NOT NULL DEFAULT '0',
  `nombreSociedad` varchar(30) DEFAULT NULL,
  PRIMARY KEY (`sociedadId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tipoMovimiento`
--
-- Creación: 31-10-2015 a las 23:05:27
--

CREATE TABLE IF NOT EXISTS `tipoMovimiento` (
  `tipoMovimientoId` int(11) DEFAULT NULL,
  `nombreMovimiento` varchar(30) DEFAULT NULL,
  `tipoOperacion` varchar(30) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tiposAtributosDeProductos`
--
-- Creación: 31-10-2015 a las 23:05:27
--

CREATE TABLE IF NOT EXISTS `tiposAtributosDeProductos` (
  `tiposAtributosDeProductosId` int(11) NOT NULL DEFAULT '0',
  `tipoProductoId` int(11) DEFAULT NULL,
  `atributoId` int(11) DEFAULT NULL,
  PRIMARY KEY (`tiposAtributosDeProductosId`),
  KEY `tipoProductoId` (`tipoProductoId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tiposCliente`
--
-- Creación: 31-10-2015 a las 23:05:27
--

CREATE TABLE IF NOT EXISTS `tiposCliente` (
  `tipoClienteId` int(11) NOT NULL DEFAULT '0',
  `nombreTipoCliente` varchar(30) DEFAULT NULL,
  `tipoFacturaId` int(11) DEFAULT NULL,
  PRIMARY KEY (`tipoClienteId`),
  KEY `tipoFacturaId` (`tipoFacturaId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tiposFactura`
--
-- Creación: 31-10-2015 a las 23:05:27
--

CREATE TABLE IF NOT EXISTS `tiposFactura` (
  `id` int(11) NOT NULL DEFAULT '0',
  `nombreTipoFactura` varchar(30) DEFAULT NULL,
  `ivaId` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `tiposFactura`
--

INSERT INTO `tiposFactura` (`id`, `nombreTipoFactura`, `ivaId`) VALUES
(1, 'Factura A', NULL),
(2, 'Factura B', NULL),
(3, 'Factura C', NULL),
(4, 'Factura E', NULL);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tiposProducto`
--
-- Creación: 31-10-2015 a las 23:05:27
--

CREATE TABLE IF NOT EXISTS `tiposProducto` (
  `id` int(11) NOT NULL DEFAULT '0',
  `tipoProducto` varchar(30) DEFAULT NULL,
  `esColoreable` tinyint(1) DEFAULT NULL,
  `stockMinimoPorDefecto` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tiposVenta`
--
-- Creación: 31-10-2015 a las 23:05:27
--

CREATE TABLE IF NOT EXISTS `tiposVenta` (
  `tipoVentaId` int(11) NOT NULL DEFAULT '0',
  `nombreTipoVenta` varchar(30) DEFAULT NULL,
  PRIMARY KEY (`tipoVentaId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `tiposVenta`
--

INSERT INTO `tiposVenta` (`tipoVentaId`, `nombreTipoVenta`) VALUES
(1, 'Venta'),
(2, 'Descarga en obra'),
(3, 'Fiada');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `title`
--
-- Creación: 07-04-2015 a las 02:11:27
--

CREATE TABLE IF NOT EXISTS `title` (
  `id` int(10) NOT NULL,
  `title` varchar(25) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `usercontract`
--
-- Creación: 07-04-2015 a las 02:11:28
--

CREATE TABLE IF NOT EXISTS `usercontract` (
  `id` int(10) NOT NULL,
  `userid` int(10) NOT NULL,
  `uc_hours` decimal(6,2) NOT NULL,
  `startdate` date NOT NULL,
  `enddate` date DEFAULT NULL,
  `description` text,
  `workingdays` text,
  `workstarttime` time DEFAULT NULL,
  `workendtime` time DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `userpimitems`
--
-- Creación: 07-04-2015 a las 02:11:28
--

CREATE TABLE IF NOT EXISTS `userpimitems` (
  `id` int(10) NOT NULL,
  `userid` int(10) DEFAULT NULL,
  `pimitem` varchar(255) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `orderby` int(10) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `userpimitems`
--

INSERT INTO `userpimitems` (`id`, `userid`, `pimitem`, `orderby`) VALUES
(1, 1, 'timereg_timeregistration', 10),
(2, 1, 'scheduler_schedule', 20),
(3, 1, 'todo_todos', 30);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `ventas`
--
-- Creación: 09-12-2015 a las 01:09:38
--

CREATE TABLE IF NOT EXISTS `ventas` (
  `id` int(11) NOT NULL DEFAULT '0',
  `nombreCliente` varchar(30) DEFAULT NULL,
  `fechaVenta` timestamp NULL DEFAULT NULL,
  `fechaVencimiento` timestamp NULL DEFAULT NULL,
  `tipoVentaId` int(11) DEFAULT NULL,
  `empleadoId` int(11) DEFAULT NULL,
  `clienteId` int(11) DEFAULT NULL,
  `precioTotalConIVA` decimal(5,2) DEFAULT NULL,
  `precioTotalSinIVA` decimal(5,2) DEFAULT NULL,
  `fechaCierre` datetime DEFAULT NULL,
  `numeroFactura` int(11) DEFAULT NULL,
  `tipoFactura` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `clienteId` (`clienteId`),
  KEY `tipoVentaId` (`tipoVentaId`),
  KEY `empleadoId` (`empleadoId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
