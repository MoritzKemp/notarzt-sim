-- phpMyAdmin SQL Dump
-- version 4.2.11
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Erstellungszeit: 01. Jun 2016 um 14:58
-- Server Version: 5.6.21
-- PHP-Version: 5.6.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Datenbank: `simulation`
--

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `notarzt`
--

CREATE TABLE IF NOT EXISTS `notarzt` (
  `idNotarzt` int(11) NOT NULL,
  `Zeitpunkt` int(11) NOT NULL,
  `Zustand` text NOT NULL,
  `Simulationszeit` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `notfall`
--

CREATE TABLE IF NOT EXISTS `notfall` (
  `idNotfall` int(11) NOT NULL,
  `ZeitAnruf` int(11) NOT NULL,
  `Prio` int(11) NOT NULL,
  `Dauer` int(11) NOT NULL,
  `Behandlung` int(11) NOT NULL, 
  `StartBehandlung` int(11) NOT NULL,
  `Simulationszeit` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

INSERT INTO notarzt VALUES(0, 0, 'dummy', -1);
INSERT INTO notfall VALUES(0, 0, 0, 0, 0, -1);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
