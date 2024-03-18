DELIMITER $$
DROP PROCEDURE IF EXISTS SP_LoginLog;
CREATE PROCEDURE SP_LoginLog(
	IN uniqueId BINARY(16)
)
BEGIN
	SET @NICKNAME = 0;

	SELECT nickname
	INTO @NICKNAME
	FROM UserAccount AS account
	WHERE account.uniqueId = uniqueId;

	INSERT INTO GameLog(logtime, category, logdata) VALUES(NOW(), 'INFO', CONCAT('`', @NICKNAME, '`', ' logined'));
END $$

DELIMITER ;