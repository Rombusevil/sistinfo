-- phpMyAdmin SQL Dump
-- version 4.6.1deb1
-- http://www.phpmyadmin.net
--
-- Servidor: localhost
-- Tiempo de generación: 09-06-2016 a las 18:58:48
-- Versión del servidor: 5.6.30-1
-- Versión de PHP: 5.6.21-2

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

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `atributosDeProductos`
--

CREATE TABLE `atributosDeProductos` (
  `atributoId` int(11) NOT NULL DEFAULT '0',
  `nombreAtributo` varchar(30) DEFAULT NULL,
  `tipoAtributo` varchar(11) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

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

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `color`
--

CREATE TABLE `color` (
  `colorId` int(11) NOT NULL DEFAULT '0',
  `codigoColor` varchar(30) DEFAULT NULL,
  `imagen` varchar(90) DEFAULT NULL,
  `gamaId` int(11) DEFAULT NULL,
  `composicionId` int(11) DEFAULT NULL,
  `esCompuesto` tinyint(1) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

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

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `db_sequence`
--

CREATE TABLE `db_sequence` (
  `seq_name` varchar(50) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `nextid` int(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `detalle`
--

CREATE TABLE `detalle` (
  `detalleId` int(11) NOT NULL DEFAULT '0',
  `productoId` int(11) DEFAULT NULL,
  `cantidad` int(11) DEFAULT NULL,
  `ventaId` int(11) DEFAULT NULL,
  `precioIVA` decimal(10,2) DEFAULT NULL,
  `colorId` int(11) DEFAULT NULL,
  `precioSinIVA` decimal(10,2) DEFAULT NULL
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

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `localidades`
--

CREATE TABLE `localidades` (
  `localidadId` int(11) NOT NULL DEFAULT '0',
  `codigoPostal` int(11) DEFAULT NULL,
  `nombreLocalidad` varchar(30) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `manejoStock`
--

CREATE TABLE `manejoStock` (
  `id` int(11) NOT NULL DEFAULT '0',
  `productoId` int(11) DEFAULT NULL,
  `fecha` timestamp NULL DEFAULT NULL,
  `cantidad` int(11) DEFAULT NULL,
  `tipoMovimientoId` int(11) NOT NULL,
  `ventaId` int(11) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `marca`
--

CREATE TABLE `marca` (
  `marcaId` int(11) NOT NULL DEFAULT '0',
  `nombreMarca` varchar(30) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

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

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `profile`
--

CREATE TABLE `profile` (
  `id` int(10) NOT NULL,
  `name` varchar(50) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

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

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `sociedades`
--

CREATE TABLE `sociedades` (
  `sociedadId` int(11) NOT NULL DEFAULT '0',
  `nombreSociedad` varchar(30) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tipoMovimiento`
--

CREATE TABLE `tipoMovimiento` (
  `tipoMovimientoId` int(11) DEFAULT NULL,
  `nombreMovimiento` varchar(30) DEFAULT NULL,
  `tipoOperacion` varchar(30) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tiposAtributosDeProductos`
--

CREATE TABLE `tiposAtributosDeProductos` (
  `tiposAtributosDeProductosId` int(11) NOT NULL DEFAULT '0',
  `tipoProductoId` int(11) DEFAULT NULL,
  `atributoId` int(11) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tiposCliente`
--

CREATE TABLE `tiposCliente` (
  `tipoClienteId` int(11) NOT NULL DEFAULT '0',
  `nombreTipoCliente` varchar(30) DEFAULT NULL,
  `tipoFacturaId` int(11) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tiposFactura`
--

CREATE TABLE `tiposFactura` (
  `id` int(11) NOT NULL DEFAULT '0',
  `nombreTipoFactura` varchar(30) DEFAULT NULL,
  `ivaId` int(11) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

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

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tiposVenta`
--

CREATE TABLE `tiposVenta` (
  `tipoVentaId` int(11) NOT NULL DEFAULT '0',
  `nombreTipoVenta` varchar(30) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

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
  `precioTotalConIVA` decimal(10,2) DEFAULT NULL,
  `precioTotalSinIVA` decimal(10,2) DEFAULT NULL,
  `tipoFactura` int(11) DEFAULT NULL,
  `fechaCierre` datetime DEFAULT NULL,
  `numeroFactura` int(11) DEFAULT NULL,
  `anulada` tinyint(4) NOT NULL DEFAULT '0'
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
