CREATE DATABASE  IF NOT EXISTS `Lab5comblm258` /*!40100 DEFAULT CHARACTER SET utf8 */;
USE `Lab5comblm258`;
-- MySQL dump 10.13  Distrib 5.5.16, for Win32 (x86)
--
-- Host: localhost    Database: Lab5comblm258
-- ------------------------------------------------------
-- Server version	5.5.28

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `class`
--

DROP TABLE IF EXISTS `class`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `class` (
  `name` varchar(45) NOT NULL,
  `meetsat` varchar(45) NOT NULL,
  `room` varchar(15) DEFAULT NULL,
  `fid` int(11) DEFAULT NULL,
  PRIMARY KEY (`name`,`meetsat`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `class`
--

LOCK TABLES `class` WRITE;
/*!40000 ALTER TABLE `class` DISABLE KEYS */;
INSERT INTO `class` VALUES ('ENG205','Friday 10:30','R128',41),('ENG208','Monday 15:30','R345',46),('HIS105','Tuesday 10:30','R128',48),('HIS105','Wednesday 15:30','R345',48),('HIS207','Monday 15:30','R111',48),('MAT101','Wednesday 11:30','R345',45),('MAT107','Friday 14:30','R111',45),('MAT108','Thursday 13:30','R128',48);
/*!40000 ALTER TABLE `class` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `enrolled`
--

DROP TABLE IF EXISTS `enrolled`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `enrolled` (
  `snum` int(11) NOT NULL,
  `cname` varchar(45) NOT NULL,
  PRIMARY KEY (`snum`,`cname`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `enrolled`
--

LOCK TABLES `enrolled` WRITE;
/*!40000 ALTER TABLE `enrolled` DISABLE KEYS */;
INSERT INTO `enrolled` VALUES (1234,'ENG205'),(1234,'ENG208'),(1234,'HIS105'),(1234,'HIS207'),(1256,'ENG208'),(1256,'HIS105'),(1256,'HIS207'),(1256,'MAT101'),(2356,'MAT107'),(3345,'ENG208'),(3345,'MAT101'),(3456,'MAT101'),(3456,'MAT107'),(3456,'MAT108'),(5643,'ENG205'),(5643,'ENG208'),(5643,'MAT107'),(9874,'HIS105'),(9874,'HIS207'),(9874,'MAT108');
/*!40000 ALTER TABLE `enrolled` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `faculty`
--

DROP TABLE IF EXISTS `faculty`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `faculty` (
  `fid` int(11) NOT NULL,
  `fname` varchar(45) DEFAULT NULL,
  `deptid` int(11) DEFAULT NULL,
  PRIMARY KEY (`fid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `faculty`
--

LOCK TABLES `faculty` WRITE;
/*!40000 ALTER TABLE `faculty` DISABLE KEYS */;
INSERT INTO `faculty` VALUES (41,'Selin C.',2396),(45,'Bugra H.',1298),(46,'Demir R.',1317),(47,'Zeynep Z.',2453),(48,'Semih Z.',1405),(49,'Zafer K.',2198);
/*!40000 ALTER TABLE `faculty` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `student`
--

DROP TABLE IF EXISTS `student`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `student` (
  `snum` int(11) NOT NULL,
  `sname` varchar(45) DEFAULT NULL,
  `major` varchar(45) DEFAULT NULL,
  `level` varchar(45) DEFAULT NULL,
  `age` int(11) DEFAULT NULL,
  PRIMARY KEY (`snum`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `student`
--

LOCK TABLES `student` WRITE;
/*!40000 ALTER TABLE `student` DISABLE KEYS */;
INSERT INTO `student` VALUES (1234,'Ahmet Kartal','History','Senior',21),(1256,'Murat Baykus','History','Junior',20),(2356,'Hasan Dogan','Statistics','Freshmen',17),(3345,'Ali Serce','Comp. Eng.','Sophomore',18),(3456,'Mehmet Sahin','Math','Junior',18),(5643,'Emine Ceyhan','Comp. Eng.','Senior',19),(5649,'Gulay Sakarya','Comp. Eng.','Senior',20),(9874,'Fatma Seyhan','History','Junior',18);
/*!40000 ALTER TABLE `student` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2013-03-18 11:08:23
