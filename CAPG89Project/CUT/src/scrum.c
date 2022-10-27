
struct _feature_
{
	char featureName[FEATURE_NAME_LEN];
	int featureId ; // primary key;
	int completeStatus ;
} feature;

typedef struct _story_ 
{
	int storyid ;   // primary key;
	int featureId ; // foreign key;
    int userid ;  // user id of scrum master
	
	int sprintId;
	char storyName[STORY_NAME_LEN];
	char storyDesc [STORY_DESC_LEN];
	int completionStatus ;
	struct _story_ *next;

} userStory ;


typedef struct _task_
{
	int storyid ; // foreign key;
	int taskId ; // primary key
	int user_id; // user id of end user;

	char taskName [TASK_NAME_LEN];
	chr taskDesc [TASK_DESC_LEN];
	int completionStatus; // 0 intialised maximum 100 update after every daily standup.

	struct _task_ *next;
}

typedef struct _user_
{
	int userid ;
	char first_name[FIRST_NAME_LEN];
	char last_name[LAST_NAME_LEN];
    char password[PASSWORD_LEN];
	int isScrumMaster ; // y = 1 
} user ;

100|RAHUL|TARKUNDE|CHANGEME|1
101|ADITYA|AMBANI|CHANGED45|0


	
