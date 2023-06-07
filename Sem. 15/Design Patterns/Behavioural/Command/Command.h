#pragma once

// TODO: finish
//class Command
//{
//public:
//	virtual void execute() const = 0;
//	virtual ~Command() = default;
//};
//
//class Entity {};
//
//// Receiver
//class Database {
//public:
//	void save(const Entity& entity) {
//		//...
//	}
//};
//
//class SaveEntityToDatabaseCommand : public Command {
//	Database* db;
//	Entity* entity;
//public:
//	SaveEntityToDatabaseCommand(Database* db, Entity* entity)
//		: db(db), entity(entity) { }
//
//	void execute() const override {
//		db->save(*entity);
//	}
//};