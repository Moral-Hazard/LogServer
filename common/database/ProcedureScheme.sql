USE LogDB;

DELIMITER $$

-- LOGIN & REGISTER
DROP PROCEDURE IF EXISTS SP_SecuLog;
CREATE PROCEDURE SP_SecuLog(
	IN loginType INTEGER,
	IN uniqueId VARCHAR(36),
	IN ipAddress VARCHAR(16)
)
BEGIN
	DECLARE eventType VARCHAR(255);

	CASE loginType
		WHEN 0 THEN
			SET eventType = 'LOGIN';
		WHEN 1 THEN
			SET eventType = 'REGISTER';
		WHEN 2 THEN
			SET eventType = 'LOGOUT';
	END CASE;

	INSERT INTO LogDB.SecurityLogs(timestamp, eventType, sourceIp, userId)
	VALUES(NOW(), eventType, ipAddress, UUID_TO_BINARY(userId));
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