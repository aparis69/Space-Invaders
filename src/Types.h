#ifndef TYPES_H
#define TYPES_H

// Define the type of an enemy
typedef enum class EnemyType
{
	Easy,
	Medium,
	Hard,
	Insane
} EnemyType;

// Define the type of a missile
typedef enum class MissileTypes
{
	Small,
	Medium,
	Big,
} MissileTypes;

// Define the possible type of an object in the game scene
typedef enum class ObjectTypes
{
	Other,
	Player,
	Enemy,
	Missile,
} ObjectTypes;

// Define the possible actions return by a ReactToCollision
typedef enum class ReactionTypes
{
	Destroy,
	ChangeDirection,
	Nothing,
} ReactionTypes;

#endif