USE LogDB;

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
	
)
BEGIN
	
END $$

DELIMITER ;
commit;