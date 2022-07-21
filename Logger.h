#ifndef LOGGING_SYSTEM_LOGGER_H
#define LOGGING_SYSTEM_LOGGER_H

#include <QObject>
#include <QTimer>

namespace LoggingSystem
{
	class Logger : public QObject
	{
		Q_OBJECT

	public:
		Logger();

	public slots:
		void log();

	private:
		QTimer *timer;

		QString m_log_type;
		int m_file_count;
		int m_interval;

		std::list<QString> m_file_names;

		bool parse_config(const QString &path);
		void create_log_file(const QString &file_name, const QString &msg);
		void delete_log_file(const QString &file_name);
		int get_interval();
	};
}

#endif // !LOGGING_SYSTEM_H