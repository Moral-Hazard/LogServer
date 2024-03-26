USE logdb;

DELIMITER $$

-- LOGIN & REGISTER
DROP PROCEDURE IF EXISTS SP_LogLogin;
CREATE PROCEDURE SP_LogLogin(
	IN uniqueId VARCHAR(36),
	IN ipAddress VARCHAR(16)
)
BEGIN
	INSERT INTO LogDB.SecurityLogs(timestamp, eventType, sourceIp, userId)
	VALUES(NOW(), 'Login', ipAddress, uniqueId);
END $$

DROP PROCEDURE IF EXISTS SP_LogLogOut;
CREATE PROCEDURE SP_LogLogOut(
	IN uniqueId VARCHAR(36),
	IN ipAddress VARCHAR(16)
)
BEGIN
	INSERT INTO LogDB.SecurityLogs(timestamp, eventType, sourceIp, userId)
	VALUES(NOW(), 'Log out', ipAddress, uniqueId);
END $$

DROP PROCEDURE IF EXISTS SP_LogRegister;
CREATE PROCEDURE SP_LogRegister(
	IN uniqueId VARCHAR(36),
	IN ipAddress VARCHAR(16)
)
BEGIN
	INSERT INTO LogDB.SecurityLogs(timestamp, eventType, sourceIp, userId)
	VALUES(NOW(), 'Register', ipAddress, uniqueId);
END $$

-- INSERT LOG
DROP PROCEDURE IF EXISTS SP_SystemLog;
CREATE PROCEDURE SP_SystemLog(
	IN severity INTEGER,
	IN serverName VARCHAR(36),
	IN message TEXT
)
BEGIN
	DECLARE severityType ENUM('DEBUG', 'INFO', 'WARNING', 'ERROR', 'CRITICAL');
	CASE severity
		WHEN 0 THEN
			SET severityType = 'DEBUG';
		WHEN 1 THEN
			SET severityType = 'INFO';
		WHEN 2 THEN
			SET severityType = 'WARNING';
		WHEN 3 THEN
			SET severityType = 'ERROR';
		ELSE
			SET severityType = 'CRITICAL';
	END CASE;

	INSERT INTO LogDB.SystemLogs(timestamp, severity, serverName, message)
	VALUES(NOW(), severityType, serverName, message);
END $$

DELIMITER ;
commit;