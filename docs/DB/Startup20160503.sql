-- phpMyAdmin SQL Dump
-- version 4.5.5.1deb2
-- http://www.phpmyadmin.net
--
-- Servidor: localhost
-- Tiempo de generación: 03-05-2016 a las 20:56:51
-- Versión del servidor: 5.6.30-1
-- Versión de PHP: 5.6.20-1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `pqllana`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `accessright`
--

CREATE TABLE `accessright` (
  `node` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `action` varchar(25) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `role_id` int(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `accessright`
--

INSERT INTO `accessright` (`node`, `action`, `role_id`) VALUES
('basedatos.basedatos', 'view', 1),
('clientes.clientes', 'add', 1),
('clientes.clientes', 'admin', 1),
('clientes.clientes', 'delete', 1),
('clientes.clientes', 'edit', 1),
('clientes.localidades', 'add', 1),
('clientes.localidades', 'admin', 1),
('clientes.localidades', 'delete', 1),
('clientes.localidades', 'edit', 1),
('clientes.sociedades', 'add', 1),
('clientes.sociedades', 'admin', 1),
('clientes.sociedades', 'delete', 1),
('clientes.sociedades', 'edit', 1),
('clientes.tiposCliente', 'add', 1),
('clientes.tiposCliente', 'admin', 1),
('clientes.tiposCliente', 'delete', 1),
('clientes.tiposCliente', 'edit', 1),
('color.color', 'add', 1),
('color.color', 'admin', 1),
('color.color', 'delete', 1),
('color.color', 'edit', 1),
('color.composicionColores', 'add', 1),
('color.composicionColores', 'admin', 1),
('color.composicionColores', 'delete', 1),
('color.composicionColores', 'edit', 1),
('color.gama', 'add', 1),
('color.gama', 'admin', 1),
('color.gama', 'delete', 1),
('color.gama', 'edit', 1),
('employee.department', 'add', 1),
('employee.department', 'admin', 1),
('employee.department', 'delete', 1),
('employee.department', 'edit', 1),
('employee.employee', 'add', 1),
('employee.employee', 'admin', 1),
('employee.employee', 'delete', 1),
('employee.employee', 'edit', 1),
('employee.employee', 'stats', 1),
('employee.employee', 'view_all', 1),
('employee.functionlevel', 'add', 1),
('employee.functionlevel', 'admin', 1),
('employee.functionlevel', 'delete', 1),
('employee.functionlevel', 'edit', 1),
('employee.profile', 'add', 1),
('employee.profile', 'admin', 1),
('employee.profile', 'delete', 1),
('employee.profile', 'edit', 1),
('employee.profile', 'grantall', 1),
('employee.usercontracts', 'add', 1),
('employee.usercontracts', 'admin', 1),
('employee.usercontracts', 'delete', 1),
('employee.usercontracts', 'edit', 1),
('employee.userprefs', 'edit', 1),
('organization.contact', 'add', 1),
('organization.contact', 'admin', 1),
('organization.contact', 'delete', 1),
('organization.contact', 'edit', 1),
('organization.contracts', 'add', 1),
('organization.contracts', 'admin', 1),
('organization.contracts', 'delete', 1),
('organization.contracts', 'edit', 1),
('organization.contracttype', 'add', 1),
('organization.contracttype', 'admin', 1),
('organization.contracttype', 'delete', 1),
('organization.contracttype', 'edit', 1),
('organization.organization', 'add', 1),
('organization.organization', 'admin', 1),
('organization.organization', 'delete', 1),
('organization.organization', 'document', 1),
('organization.organization', 'edit', 1),
('productos.atributosDeProductos', 'add', 1),
('productos.atributosDeProductos', 'admin', 1),
('productos.atributosDeProductos', 'delete', 1),
('productos.atributosDeProductos', 'edit', 1),
('productos.datosProductos', 'admin', 1),
('productos.datosProductos', 'edit', 1),
('productos.manejoStock', 'add', 1),
('productos.manejoStock', 'admin', 1),
('productos.manejoStock', 'delete', 1),
('productos.manejoStock', 'edit', 1),
('productos.marca', 'add', 1),
('productos.marca', 'admin', 1),
('productos.marca', 'delete', 1),
('productos.marca', 'edit', 1),
('productos.productos', 'add', 1),
('productos.productos', 'admin', 1),
('productos.productos', 'delete', 1),
('productos.productos', 'edit', 1),
('productos.productos', 'mra_editar_precio', 1),
('productos.tipoMovimiento', 'add', 1),
('productos.tipoMovimiento', 'admin', 1),
('productos.tipoMovimiento', 'delete', 1),
('productos.tipoMovimiento', 'edit', 1),
('productos.tiposAtributosDeProductos', 'add', 1),
('productos.tiposAtributosDeProductos', 'admin', 1),
('productos.tiposAtributosDeProductos', 'delete', 1),
('productos.tiposAtributosDeProductos', 'edit', 1),
('productos.tiposProducto', 'add', 1),
('productos.tiposProducto', 'admin', 1),
('productos.tiposProducto', 'delete', 1),
('productos.tiposProducto', 'edit', 1),
('scheduler.scheduler', 'add', 1),
('scheduler.scheduler', 'admin', 1),
('scheduler.scheduler', 'all_non_private', 1),
('scheduler.scheduler', 'delete', 1),
('scheduler.scheduler', 'edit', 1),
('scheduler.scheduler_category', 'add', 1),
('scheduler.scheduler_category', 'admin', 1),
('scheduler.scheduler_category', 'delete', 1),
('scheduler.scheduler_category', 'edit', 1),
('scheduler.scheduler_email_template', 'admin', 1),
('scheduler.scheduler_email_template', 'edit', 1),
('scheduler.scheduler_holidays', 'add', 1),
('scheduler.scheduler_holidays', 'admin', 1),
('scheduler.scheduler_holidays', 'delete', 1),
('scheduler.scheduler_holidays', 'edit', 1),
('ventas.detalle', 'add', 1),
('ventas.detalle', 'add', 2),
('ventas.detalle', 'admin', 1),
('ventas.detalle', 'admin', 2),
('ventas.detalle', 'delete', 1),
('ventas.detalle', 'edit', 1),
('ventas.detalle', 'edit', 2),
('ventas.ivas', 'add', 1),
('ventas.ivas', 'admin', 1),
('ventas.ivas', 'delete', 1),
('ventas.ivas', 'edit', 1),
('ventas.tiposFactura', 'add', 1),
('ventas.tiposFactura', 'admin', 1),
('ventas.tiposFactura', 'delete', 1),
('ventas.tiposFactura', 'edit', 1),
('ventas.tiposVenta', 'admin', 1),
('ventas.ventas', 'add', 1),
('ventas.ventas', 'add', 2),
('ventas.ventas', 'admin', 1),
('ventas.ventas', 'admin', 2),
('ventas.ventas', 'cierraVenta', 1),
('ventas.ventas', 'delete', 1),
('ventas.ventas', 'edit', 1),
('ventas.ventas', 'edit', 2);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `atributosDeProductos`
--

CREATE TABLE `atributosDeProductos` (
  `atributoId` int(11) NOT NULL DEFAULT '0',
  `nombreAtributo` varchar(30) DEFAULT NULL,
  `tipoAtributo` varchar(11) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `atributosDeProductos`
--

INSERT INTO `atributosDeProductos` (`atributoId`, `nombreAtributo`, `tipoAtributo`) VALUES
(1, 'Capacidad', 'Lts'),
(2, 'Material', NULL);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `clientes`
--

CREATE TABLE `clientes` (
  `clienteId` int(11) NOT NULL DEFAULT '0',
  `cuitCuil` varchar(20) DEFAULT NULL,
  `razonSocial` varchar(50) DEFAULT NULL,
  `correoElectronico` varchar(80) DEFAULT NULL,
  `telefono` varchar(50) DEFAULT NULL,
  `direccion` varchar(50) DEFAULT NULL,
  `tipoClienteId` int(11) DEFAULT NULL,
  `sociedadId` int(11) DEFAULT NULL,
  `localidadId` int(11) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `clientes`
--

INSERT INTO `clientes` (`clienteId`, `cuitCuil`, `razonSocial`, `correoElectronico`, `telefono`, `direccion`, `tipoClienteId`, `sociedadId`, `localidadId`) VALUES
(1, '27-33099231-5', 'Juan Perez', 'jperez@puelche.com', NULL, NULL, 1, 1, 1),
(2, '27-89876231-5', 'Hiper Tehuelche', NULL, NULL, NULL, 1, 2, 1),
(3, '27-12876546-5', 'Jorge Lopez', NULL, NULL, NULL, 2, NULL, 2);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `color`
--

CREATE TABLE `color` (
  `colorId` int(11) NOT NULL DEFAULT '0',
  `codigoColor` varchar(30) DEFAULT NULL,
  `imagen` varchar(90) DEFAULT NULL,
  `gamaId` int(11) DEFAULT NULL,
  `composicionId` int(11) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `color`
--

INSERT INTO `color` (`colorId`, `codigoColor`, `imagen`, `gamaId`, `composicionId`) VALUES
(1, '1000', NULL, 1, NULL),
(2, '2000', NULL, 2, NULL),
(3, '3000', NULL, 3, 1);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `composicionColores`
--

CREATE TABLE `composicionColores` (
  `id` int(11) NOT NULL DEFAULT '0',
  `colorPrimario` int(11) DEFAULT NULL,
  `colorSecundario` int(11) DEFAULT NULL,
  `porcentaje` float DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `composicionColores`
--

INSERT INTO `composicionColores` (`id`, `colorPrimario`, `colorSecundario`, `porcentaje`) VALUES
(1, 1, 2, 50);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `datosProductos`
--

CREATE TABLE `datosProductos` (
  `datosProductosId` int(11) NOT NULL DEFAULT '0',
  `productoId` int(11) DEFAULT NULL,
  `nombreAtributo` varchar(30) DEFAULT NULL,
  `valorAtributo` varchar(30) DEFAULT NULL,
  `tipoAtributo` varchar(30) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `datosProductos`
--

INSERT INTO `datosProductos` (`datosProductosId`, `productoId`, `nombreAtributo`, `valorAtributo`, `tipoAtributo`) VALUES
(1, 1, 'Capacidad', '50', 'Lts'),
(3, 2, 'Material', 'madera', '');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `db_sequence`
--

CREATE TABLE `db_sequence` (
  `seq_name` varchar(50) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `nextid` int(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `db_sequence`
--

INSERT INTO `db_sequence` (`seq_name`, `nextid`) VALUES
('atributosDeProductos', 2),
('clientes', 3),
('color', 3),
('composicionColores', 1),
('datosProductos', 3),
('gama', 3),
('ivas', 3),
('localidades', 2),
('manejoStock', 2),
('marca', 1),
('person', 1),
('productos', 2),
('profile', 2),
('sociedades', 2),
('tipoMovimiento', 2),
('tiposAtributosDeProductos', 2),
('tiposCliente', 2),
('tiposFactura', 2),
('tiposProducto', 2),
('userpimitems', 3);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `detalle`
--

CREATE TABLE `detalle` (
  `detalleId` int(11) NOT NULL DEFAULT '0',
  `productoId` int(11) DEFAULT NULL,
  `cantidad` int(11) DEFAULT NULL,
  `ventaId` int(11) DEFAULT NULL,
  `precioIVA` decimal(5,2) DEFAULT NULL,
  `colorId` int(11) DEFAULT NULL,
  `precioSinIVA` decimal(5,2) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `empleados`
--

CREATE TABLE `empleados` (
  `empleadoId` int(11) NOT NULL DEFAULT '0',
  `nombreEmpleado` varchar(30) DEFAULT NULL,
  `perfilId` int(11) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `employeerole`
--

CREATE TABLE `employeerole` (
  `employee_id` int(10) NOT NULL,
  `role_id` int(10) NOT NULL
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

CREATE TABLE `employee_department` (
  `id` int(10) NOT NULL,
  `name` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `description` text
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `functionlevel`
--

CREATE TABLE `functionlevel` (
  `id` int(10) NOT NULL,
  `name` varchar(50) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `description` text
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `gama`
--

CREATE TABLE `gama` (
  `gamaId` int(11) NOT NULL DEFAULT '0',
  `nombreGama` varchar(30) DEFAULT NULL,
  `imagen` varchar(90) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `gama`
--

INSERT INTO `gama` (`gamaId`, `nombreGama`, `imagen`) VALUES
(1, 'Azul', '#0000FF'),
(2, 'Amarillo', '#EEFF00'),
(3, 'Verde', '#00FF00');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `ivas`
--

CREATE TABLE `ivas` (
  `id` int(11) DEFAULT NULL,
  `fechaVigencia` date DEFAULT NULL,
  `valorIva` decimal(5,2) DEFAULT NULL,
  `tipoFacturaId` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `ivas`
--

INSERT INTO `ivas` (`id`, `fechaVigencia`, `valorIva`, `tipoFacturaId`) VALUES
(1, '2014-05-05', 14.00, 1),
(2, '2016-05-02', 21.00, 1),
(3, '2016-05-02', 25.00, 2);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `localidades`
--

CREATE TABLE `localidades` (
  `localidadId` int(11) NOT NULL DEFAULT '0',
  `codigoPostal` int(11) DEFAULT NULL,
  `nombreLocalidad` varchar(30) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `localidades`
--

INSERT INTO `localidades` (`localidadId`, `codigoPostal`, `nombreLocalidad`) VALUES
(1, 8400, 'Bariloche'),
(2, 8402, 'Dina Huapi');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `manejoStock`
--

CREATE TABLE `manejoStock` (
  `id` int(11) NOT NULL DEFAULT '0',
  `productoId` int(11) DEFAULT NULL,
  `fecha` timestamp NULL DEFAULT NULL,
  `cantidad` int(11) DEFAULT NULL,
  `tipoMovimientoId` int(11) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `manejoStock`
--

INSERT INTO `manejoStock` (`id`, `productoId`, `fecha`, `cantidad`, `tipoMovimientoId`) VALUES
(1, 1, '2016-05-03 23:42:00', 20, 2),
(2, 2, '2016-05-03 23:43:00', 20, 2);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `marca`
--

CREATE TABLE `marca` (
  `marcaId` int(11) NOT NULL DEFAULT '0',
  `nombreMarca` varchar(30) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `marca`
--

INSERT INTO `marca` (`marcaId`, `nombreMarca`) VALUES
(1, 'Alba');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `organization`
--

CREATE TABLE `organization` (
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
  `last_modified_on` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `perfiles`
--

CREATE TABLE `perfiles` (
  `perfilId` int(11) NOT NULL DEFAULT '0',
  `nombrePerfil` varchar(30) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `person`
--

CREATE TABLE `person` (
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
  `company` int(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `person`
--

INSERT INTO `person` (`id`, `title_id`, `userid`, `lastname`, `firstname`, `initials`, `address`, `zipcode`, `city`, `state`, `country`, `phone`, `cellular`, `fax`, `email`, `function`, `remark`, `role`, `created_by`, `created_on`, `last_modified_by`, `last_modified_on`, `birthdate`, `bankaccount`, `socialsecuritynumber`, `employer_id`, `department`, `supervisor`, `functionlevel`, `status`, `lng`, `password`, `theme`, `company`) VALUES
(1, NULL, 'admin', 'admin', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'employee', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'active', 'es', '21232f297a57a5a743894a0e4a801fc3', NULL, NULL);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `productos`
--

CREATE TABLE `productos` (
  `id` int(11) NOT NULL DEFAULT '0',
  `codigoProducto` int(11) DEFAULT NULL,
  `nombreProducto` varchar(30) DEFAULT NULL,
  `descripcion` varchar(120) DEFAULT NULL,
  `precio` decimal(5,2) DEFAULT NULL,
  `cantidad` int(11) DEFAULT NULL,
  `stockMinimo` int(11) DEFAULT NULL,
  `marcaId` int(11) DEFAULT NULL,
  `tipoProductoId` int(11) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `productos`
--

INSERT INTO `productos` (`id`, `codigoProducto`, `nombreProducto`, `descripcion`, `precio`, `cantidad`, `stockMinimo`, `marcaId`, `tipoProductoId`) VALUES
(1, 1, 'Lata de pintura Alba', NULL, 100.00, 20, 10, 1, 1),
(2, 2, 'Pincel de madera', NULL, 10.00, 20, 5, 1, 2);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `profile`
--

CREATE TABLE `profile` (
  `id` int(10) NOT NULL,
  `name` varchar(50) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `profile`
--

INSERT INTO `profile` (`id`, `name`) VALUES
(1, 'Administrador'),
(2, 'Vendedor');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `role`
--

CREATE TABLE `role` (
  `id` int(10) NOT NULL,
  `name` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `description` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `scheduler_alarms`
--

CREATE TABLE `scheduler_alarms` (
  `scheduler_id` int(10) NOT NULL,
  `startdate` int(10) NOT NULL,
  `duration` int(10) DEFAULT NULL,
  `senddate` int(10) DEFAULT NULL,
  `send` int(1) DEFAULT NULL,
  `type` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `userid` int(2) NOT NULL,
  `owner` int(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `scheduler_attendees`
--

CREATE TABLE `scheduler_attendees` (
  `scheduler_id` int(10) NOT NULL,
  `person_id` int(10) NOT NULL,
  `status` varchar(11) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `scheduler_category`
--

CREATE TABLE `scheduler_category` (
  `id` int(10) NOT NULL,
  `description` varchar(50) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `bgcolor` varchar(10) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `fgcolor` varchar(10) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `scheduler_cyclus`
--

CREATE TABLE `scheduler_cyclus` (
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
  `cyclus_times` int(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `scheduler_cyclus_not`
--

CREATE TABLE `scheduler_cyclus_not` (
  `scheduler_id` int(10) NOT NULL,
  `date` int(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `scheduler_dates`
--

CREATE TABLE `scheduler_dates` (
  `scheduler_id` int(10) NOT NULL,
  `startdate` int(10) NOT NULL,
  `enddate` int(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `scheduler_group`
--

CREATE TABLE `scheduler_group` (
  `id` int(10) NOT NULL,
  `userid` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  `name` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `scheduler_group_member`
--

CREATE TABLE `scheduler_group_member` (
  `groupid` int(10) NOT NULL,
  `userid` int(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `scheduler_holidays`
--

CREATE TABLE `scheduler_holidays` (
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
  `country` varchar(2) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `scheduler_notes`
--

CREATE TABLE `scheduler_notes` (
  `id` int(10) NOT NULL,
  `owner` int(10) NOT NULL,
  `scheduler_id` int(10) NOT NULL,
  `entrydate` date NOT NULL,
  `title` varchar(100) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `description` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `scheduler_scheduler`
--

CREATE TABLE `scheduler_scheduler` (
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
  `times` int(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `scheduler_userassistants`
--

CREATE TABLE `scheduler_userassistants` (
  `userid` int(10) NOT NULL,
  `employeeid` int(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `scheduler_userpreferences`
--

CREATE TABLE `scheduler_userpreferences` (
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
  `scheduler_emptyworkhourscolor` varchar(10) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `scheduler_userpreferences`
--

INSERT INTO `scheduler_userpreferences` (`userid`, `timeschedule`, `showweeknumbers`, `showtodo`, `showemployeebirthdays`, `showlunarphases`, `autorefresh`, `refresh_interval`, `default_view`, `default_userview`, `default_eventtime`, `default_category`, `scheduler_emptycolor`, `scheduler_emptyworkhourscolor`) VALUES
(1, 30, 0, 0, 0, NULL, 0, 0, 'day', '1', '01:00:00', NULL, '#DDDDDD', '#FFFFFF');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `sociedades`
--

CREATE TABLE `sociedades` (
  `sociedadId` int(11) NOT NULL DEFAULT '0',
  `nombreSociedad` varchar(30) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `sociedades`
--

INSERT INTO `sociedades` (`sociedadId`, `nombreSociedad`) VALUES
(1, 'Puelche'),
(2, 'Hiper Tehuelche');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tipoMovimiento`
--

CREATE TABLE `tipoMovimiento` (
  `tipoMovimientoId` int(11) DEFAULT NULL,
  `nombreMovimiento` varchar(30) DEFAULT NULL,
  `tipoOperacion` varchar(30) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `tipoMovimiento`
--

INSERT INTO `tipoMovimiento` (`tipoMovimientoId`, `nombreMovimiento`, `tipoOperacion`) VALUES
(1, 'Venta', 'Decremento'),
(2, 'Ingreso', 'Incremento');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tiposAtributosDeProductos`
--

CREATE TABLE `tiposAtributosDeProductos` (
  `tiposAtributosDeProductosId` int(11) NOT NULL DEFAULT '0',
  `tipoProductoId` int(11) DEFAULT NULL,
  `atributoId` int(11) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `tiposAtributosDeProductos`
--

INSERT INTO `tiposAtributosDeProductos` (`tiposAtributosDeProductosId`, `tipoProductoId`, `atributoId`) VALUES
(1, 1, 1),
(2, 2, 2);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tiposCliente`
--

CREATE TABLE `tiposCliente` (
  `tipoClienteId` int(11) NOT NULL DEFAULT '0',
  `nombreTipoCliente` varchar(30) DEFAULT NULL,
  `tipoFacturaId` int(11) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `tiposCliente`
--

INSERT INTO `tiposCliente` (`tipoClienteId`, `nombreTipoCliente`, `tipoFacturaId`) VALUES
(1, 'Responsable inscripto', 1),
(2, 'Consumidor final', 2);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tiposFactura`
--

CREATE TABLE `tiposFactura` (
  `id` int(11) NOT NULL DEFAULT '0',
  `nombreTipoFactura` varchar(30) DEFAULT NULL,
  `ivaId` int(11) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `tiposFactura`
--

INSERT INTO `tiposFactura` (`id`, `nombreTipoFactura`, `ivaId`) VALUES
(1, 'Factura A', NULL),
(2, 'Factura C', NULL);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tiposProducto`
--

CREATE TABLE `tiposProducto` (
  `id` int(11) NOT NULL DEFAULT '0',
  `tipoProducto` varchar(30) DEFAULT NULL,
  `esColoreable` tinyint(1) DEFAULT NULL,
  `stockMinimoPorDefecto` int(11) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `tiposProducto`
--

INSERT INTO `tiposProducto` (`id`, `tipoProducto`, `esColoreable`, `stockMinimoPorDefecto`) VALUES
(1, 'Lata de pintura', 1, 10),
(2, 'Pincel', 0, 5);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tiposVenta`
--

CREATE TABLE `tiposVenta` (
  `tipoVentaId` int(11) NOT NULL DEFAULT '0',
  `nombreTipoVenta` varchar(30) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

INSERT INTO `tiposVenta` (`tipoVentaId`, `nombreTipoVenta`) VALUES
(1, 'Venta'),
(2, 'Descarga en Obra'),
(3, 'Fiada');
-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `title`
--

CREATE TABLE `title` (
  `id` int(10) NOT NULL,
  `title` varchar(25) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `usercontract`
--

CREATE TABLE `usercontract` (
  `id` int(10) NOT NULL,
  `userid` int(10) NOT NULL,
  `uc_hours` decimal(6,2) NOT NULL,
  `startdate` date NOT NULL,
  `enddate` date DEFAULT NULL,
  `description` text,
  `workingdays` text,
  `workstarttime` time DEFAULT NULL,
  `workendtime` time DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `userpimitems`
--

CREATE TABLE `userpimitems` (
  `id` int(10) NOT NULL,
  `userid` int(10) DEFAULT NULL,
  `pimitem` varchar(255) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `orderby` int(10) DEFAULT NULL
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

CREATE TABLE `ventas` (
  `id` int(11) NOT NULL DEFAULT '0',
  `nombreCliente` varchar(30) DEFAULT NULL,
  `fechaVenta` timestamp NULL DEFAULT NULL,
  `fechaVencimiento` timestamp NULL DEFAULT NULL,
  `tipoVentaId` int(11) DEFAULT NULL,
  `empleadoId` int(11) DEFAULT NULL,
  `clienteId` int(11) DEFAULT NULL,
  `precioTotalConIVA` decimal(5,2) DEFAULT NULL,
  `precioTotalSinIVA` decimal(5,2) DEFAULT NULL,
  `tipoFactura` int(11) DEFAULT NULL,
  `fechaCierre` datetime DEFAULT NULL,
  `numeroFactura` int(11) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `accessright`
--
ALTER TABLE `accessright`
  ADD PRIMARY KEY (`node`,`action`,`role_id`);

--
-- Indices de la tabla `atributosDeProductos`
--
ALTER TABLE `atributosDeProductos`
  ADD PRIMARY KEY (`atributoId`),
  ADD KEY `tipoAtributo` (`tipoAtributo`);

--
-- Indices de la tabla `clientes`
--
ALTER TABLE `clientes`
  ADD PRIMARY KEY (`clienteId`),
  ADD KEY `localidadId` (`localidadId`),
  ADD KEY `tipoClienteId` (`tipoClienteId`),
  ADD KEY `sociedadId` (`sociedadId`);

--
-- Indices de la tabla `color`
--
ALTER TABLE `color`
  ADD PRIMARY KEY (`colorId`),
  ADD KEY `gamaId` (`gamaId`);

--
-- Indices de la tabla `composicionColores`
--
ALTER TABLE `composicionColores`
  ADD PRIMARY KEY (`id`),
  ADD KEY `colorPrimario` (`colorPrimario`),
  ADD KEY `colorSecundario` (`colorSecundario`);

--
-- Indices de la tabla `datosProductos`
--
ALTER TABLE `datosProductos`
  ADD PRIMARY KEY (`datosProductosId`),
  ADD KEY `productoId` (`productoId`);

--
-- Indices de la tabla `db_sequence`
--
ALTER TABLE `db_sequence`
  ADD PRIMARY KEY (`seq_name`);

--
-- Indices de la tabla `detalle`
--
ALTER TABLE `detalle`
  ADD PRIMARY KEY (`detalleId`),
  ADD KEY `ventaId` (`ventaId`),
  ADD KEY `productoId` (`productoId`),
  ADD KEY `colorId` (`colorId`);

--
-- Indices de la tabla `empleados`
--
ALTER TABLE `empleados`
  ADD PRIMARY KEY (`empleadoId`),
  ADD KEY `perfilId` (`perfilId`);

--
-- Indices de la tabla `employeerole`
--
ALTER TABLE `employeerole`
  ADD PRIMARY KEY (`employee_id`,`role_id`);

--
-- Indices de la tabla `employee_department`
--
ALTER TABLE `employee_department`
  ADD PRIMARY KEY (`id`);

--
-- Indices de la tabla `functionlevel`
--
ALTER TABLE `functionlevel`
  ADD PRIMARY KEY (`id`);

--
-- Indices de la tabla `gama`
--
ALTER TABLE `gama`
  ADD PRIMARY KEY (`gamaId`);

--
-- Indices de la tabla `localidades`
--
ALTER TABLE `localidades`
  ADD PRIMARY KEY (`localidadId`);

--
-- Indices de la tabla `manejoStock`
--
ALTER TABLE `manejoStock`
  ADD PRIMARY KEY (`id`),
  ADD KEY `productoId` (`productoId`);

--
-- Indices de la tabla `marca`
--
ALTER TABLE `marca`
  ADD PRIMARY KEY (`marcaId`);

--
-- Indices de la tabla `organization`
--
ALTER TABLE `organization`
  ADD PRIMARY KEY (`id`);

--
-- Indices de la tabla `perfiles`
--
ALTER TABLE `perfiles`
  ADD PRIMARY KEY (`perfilId`);

--
-- Indices de la tabla `person`
--
ALTER TABLE `person`
  ADD PRIMARY KEY (`id`);

--
-- Indices de la tabla `productos`
--
ALTER TABLE `productos`
  ADD PRIMARY KEY (`id`),
  ADD KEY `marcaId` (`marcaId`),
  ADD KEY `tipoProductoId` (`tipoProductoId`);

--
-- Indices de la tabla `profile`
--
ALTER TABLE `profile`
  ADD PRIMARY KEY (`id`);

--
-- Indices de la tabla `role`
--
ALTER TABLE `role`
  ADD PRIMARY KEY (`id`);

--
-- Indices de la tabla `scheduler_alarms`
--
ALTER TABLE `scheduler_alarms`
  ADD PRIMARY KEY (`scheduler_id`,`startdate`,`userid`);

--
-- Indices de la tabla `scheduler_attendees`
--
ALTER TABLE `scheduler_attendees`
  ADD PRIMARY KEY (`scheduler_id`,`person_id`);

--
-- Indices de la tabla `scheduler_category`
--
ALTER TABLE `scheduler_category`
  ADD PRIMARY KEY (`id`);

--
-- Indices de la tabla `scheduler_cyclus`
--
ALTER TABLE `scheduler_cyclus`
  ADD PRIMARY KEY (`scheduler_id`);

--
-- Indices de la tabla `scheduler_cyclus_not`
--
ALTER TABLE `scheduler_cyclus_not`
  ADD PRIMARY KEY (`scheduler_id`,`date`);

--
-- Indices de la tabla `scheduler_dates`
--
ALTER TABLE `scheduler_dates`
  ADD PRIMARY KEY (`scheduler_id`,`startdate`),
  ADD KEY `enddate_idx` (`enddate`);

--
-- Indices de la tabla `scheduler_group`
--
ALTER TABLE `scheduler_group`
  ADD PRIMARY KEY (`id`);

--
-- Indices de la tabla `scheduler_group_member`
--
ALTER TABLE `scheduler_group_member`
  ADD PRIMARY KEY (`groupid`,`userid`);

--
-- Indices de la tabla `scheduler_holidays`
--
ALTER TABLE `scheduler_holidays`
  ADD PRIMARY KEY (`id`);

--
-- Indices de la tabla `scheduler_notes`
--
ALTER TABLE `scheduler_notes`
  ADD PRIMARY KEY (`id`);

--
-- Indices de la tabla `scheduler_scheduler`
--
ALTER TABLE `scheduler_scheduler`
  ADD PRIMARY KEY (`id`);

--
-- Indices de la tabla `scheduler_userassistants`
--
ALTER TABLE `scheduler_userassistants`
  ADD PRIMARY KEY (`userid`,`employeeid`);

--
-- Indices de la tabla `scheduler_userpreferences`
--
ALTER TABLE `scheduler_userpreferences`
  ADD PRIMARY KEY (`userid`);

--
-- Indices de la tabla `sociedades`
--
ALTER TABLE `sociedades`
  ADD PRIMARY KEY (`sociedadId`);

--
-- Indices de la tabla `tiposAtributosDeProductos`
--
ALTER TABLE `tiposAtributosDeProductos`
  ADD PRIMARY KEY (`tiposAtributosDeProductosId`),
  ADD KEY `tipoProductoId` (`tipoProductoId`);

--
-- Indices de la tabla `tiposCliente`
--
ALTER TABLE `tiposCliente`
  ADD PRIMARY KEY (`tipoClienteId`),
  ADD KEY `tipoFacturaId` (`tipoFacturaId`);

--
-- Indices de la tabla `tiposFactura`
--
ALTER TABLE `tiposFactura`
  ADD PRIMARY KEY (`id`);

--
-- Indices de la tabla `tiposProducto`
--
ALTER TABLE `tiposProducto`
  ADD PRIMARY KEY (`id`);

--
-- Indices de la tabla `tiposVenta`
--
ALTER TABLE `tiposVenta`
  ADD PRIMARY KEY (`tipoVentaId`);

--
-- Indices de la tabla `title`
--
ALTER TABLE `title`
  ADD PRIMARY KEY (`id`);

--
-- Indices de la tabla `usercontract`
--
ALTER TABLE `usercontract`
  ADD PRIMARY KEY (`id`);

--
-- Indices de la tabla `userpimitems`
--
ALTER TABLE `userpimitems`
  ADD PRIMARY KEY (`id`);

--
-- Indices de la tabla `ventas`
--
ALTER TABLE `ventas`
  ADD PRIMARY KEY (`id`),
  ADD KEY `clienteId` (`clienteId`),
  ADD KEY `tipoVentaId` (`tipoVentaId`),
  ADD KEY `empleadoId` (`empleadoId`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
