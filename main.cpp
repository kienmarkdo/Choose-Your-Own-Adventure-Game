#include <iostream>
#include <time.h>
using namespace std;

// --------------------------- structures section --------------------------------
// =================== structures =======================
struct Skills // the skills Marius has unlocked
{
    int lockPicking; // new options, reduces noise
    int fighting; // damage++
    int climbing; // new options
    int aim; // hit chance++
    int endurance; // new options, reduces aim
};

struct MyCharacter // the properties of characters
{
    float damage;
    float health;
    float hitChance;
    Skills mySkills; // skills affect properties
};

struct Characters // other character properties
{
    float damage;
    float health;
    float hitChance;
    float awareness;
};

// ==================== initialize structures ==========================
Skills initialize (Skills, int, int, int, int, int); // skills
MyCharacter initialize (MyCharacter, float, float, float, Skills); // my character properties and skills
Characters initialize (Characters, float, float, float, float); // other character properties

Skills initialize (Skills _skill, int _lockPicking, int _fighting, int _climbing, int _aim, int _endurance)
{
    _skill.lockPicking = _lockPicking;
    _skill.fighting = _fighting;
    _skill.climbing = _climbing;
    _skill.aim = _aim;
    _skill.endurance = _endurance;
    return _skill;
}

MyCharacter initialize (MyCharacter _myCharacter, float _damage, float _health, float _hitChance, Skills _mySkills)
{
    _myCharacter.damage = _damage;
    _myCharacter.health = _health;
    _myCharacter.hitChance = _hitChance;
    _myCharacter.mySkills = initialize(_myCharacter.mySkills, 0, 0, 0, 0, 0);
    return _myCharacter;
}

Characters initialize (Characters _character, float _damage, float _health, float _hitChance, float _awareness)
{
    _character.damage = _damage;
    _character.health = _health;
    _character.hitChance = _hitChance;
    _character.awareness = _awareness;
    return _character;
}

//------------------------------ function prototype -------------------------------------------
// ================ actual functions ==================
int mainMenu(int);
int unlockSkill(MyCharacter&, int&, int);
int chapterOne(int);
int chapterTwo(MyCharacter, Characters, Characters, Characters, int);
int chapterThree (MyCharacter, Characters, Characters, Characters, Characters, int);

// ================ display functions ==================

void displayMarius(MyCharacter);
void displayCharacter(Characters);

int mainMenu(int x) // main menu
{
    cout << "                   The Path of a Lost Engineer                 " << endl << endl;
    do
    {
        cout << "1. Play \n2. Instructions \n3. Credits \n4. Quit" << endl;
        cin >> x;
        switch (x)
        {
        case 1:                             // play
            cout << "Loading..." << endl;
            break;
        case 2:                             // instructions
            cout << "This game revolves around the life of Marius Streicher, a German engineer and part-time officer.\n";
            cout << "   You will play as Marius Streicher and make decisions that will impact the story.\n";
            cout << "   Note that the choices will reflect Marius' future either POSITIVELY, OR NEGATIVELY.\n\n";

            cout << "How the game works:\n";
            cout << "   - All BULLETS in this game deal 100 damage. The average health is 100 health without any armour.\n";
            cout << "   - There are teammates in this game, each serve a different purpose.\n";
            cout << "   - Character properties include HAND TO HAND COMBAT DAMAGE(shortened to Damage),\n";
            cout << "     HEALTH, HIT CHANCE(chance of your shots hitting the enemy), and AWARENESS**.\n";
            cout << "   - Dying will cause you to restart the Chapter.\n";
            cout << "**Awareness is a property that all characters have EXCEPT Marius. It measures the\n";
            cout << "the enemy's or teammate's awareness when they are not engaging in combat.\n\n";

            cout << "At the end of each chapter, the possible outcomes that your choices will give you include:\n";
            cout << "   - Information gained (knowledge gained on characters or on the story)\n";
            cout << "   - Character performance/statistic change (affects physical)\n";
            cout << "   - Skill gained/skill unlock prevention(you may earn a skill or be prohibited from unlocking a skill\n";
            cout << "   - Story change (affects the ending)\n" << endl << endl;
            break;
        case 3:                             // credit
            cout << "This game was made by Kien Do. The story was inspired by the game Rainbow Six Siege\n";
            cout << "Some story line ideas were suggested by Sarp and many of Kien's friends." << endl << endl;
            break;
        case 4:                             // quit
            cout << "We will return when you are ready." << endl << endl;
            break;
        default:
            cout << "Invalid. Please enter 1, 2, 3 or 4." << endl << endl;
            break;
        }
    }
    while (x != 1 && x != 4);
    system("PAUSE");
    system("CLS");
    return x;
}

// --------------------------------     chapters     ---------------------------------------

int chapterOne(int input1) // Chapter One
{
    cout << "                      CHAPTER ONE            " << endl << endl;
    cout << "Location: Saint Petersburg, Russia, abandoned building." << endl << endl;
    cin.get();
    cout << endl;
    cout << "Marius: Dominic, Dominic we're here! Where are you? Dominic!" << endl << endl;
    cin.get();
    cout << endl;
    cout << "Gun man 1: kto tbi? Noyemy tbi enecb?" << endl << endl;
    cin.get();
    cout << endl;
    cout << "Marius: What? I don't underst - WHOA! Put the gun down! I'm looking for my brother, Dominic Streicher!" << endl << endl;
    cin.get();
    cout << endl;
    cout << "Gun man 2: Who are you? Talk or I shoot you." << endl << endl;
    cout << "1. \"I'm Dominic's brother! Please stop, he has kids!\"           2. Stall the shooter as help arrives." << endl;
    cout << "3. \"Please, don't shoot me. I'm harmless!\"                      4. Shoot with your own gun." << endl;
    cin >> input1; // input 1

    while (input1 != 1 && input1 != 2 && input1 != 3 && input1 != 4)
    {
        cout << "Invalid option. Please enter 1, 2, 3 or 4." << endl;
        cin >> input1;
    }

    switch (input1) //1. Knows Dom has kids 2. Knows Dom works for GSG 9 3. Sledge appearance 4. Gets injured
    {
    case 1:
        cout << "Marius: My name is Marius Streicher. I just want my brother back, PLEASE!" << endl;
        cout << "Marius: He- he has a wife, and two boys. Please if you have kids you would know." << endl << endl;
        cin.get();
        cout << "Gun man 2: When you entered, you said we are here, not I am here." << endl;
        cout << "           WHO ELSE IS OUT THERE? YOU CALLED THE COPS? WHERE IS OUR MONEY?" << endl << endl;
        break;
    case 2:
        cout << "Marius: Have you seen my brother? I just want to get him back!" << endl;
        cout << "        I am exhausted, please, I just want him back, that's all!!" << endl << endl;
        cin.get();
        cout << endl;
        cout << "Both gun men: ... *staring at each other." << endl << endl;
        cin.get();
        cout << endl << endl;
        cout << "Marius: PLEASE! I'll come with you. What ever you need, I'll DO IT for you. I just want my brother back." << endl << endl;
        cout << "Gun man 2: Your brother is a RAT for the Grenzschutzgruppe 9!" << endl;
        cout << "       You? You're probably just another rat!" << endl;
        cin.get();
        cout << endl << "Marius: What? My brother is an Accountant for the government... He isn't a spy!? He works in an office!" << endl;
        cout << "Gun man 2: Listen here you littl-" << endl << endl;
        break;
    case 3:
        cout << "Marius: Please, please don't shoot me, I mean no harm!" << endl << endl;
        cin.get();
        cout << endl;
        cout << "Gun man 2: How can we be sure, huh? What if you shoot us?" << endl;
        cout << "**both gun men still pointing the gun at you" << endl;
        cout << "Earlier you said WE are here, not I am here. Who else is here huh? WHO? COPS?" << endl << endl;
        break;
    case 4:
        cout << "**Pulls gun out, shoots." << endl << endl;
        cin.get();
        cout << endl;
        cout << "Gun man 1: Whoa, he's got a gun! Run! Get the hostage! **shoots you as they run" << endl << endl;
        cin.get();
        cout << endl;
        cout << "Marius: Ah, my arm! I'm hit!" << endl << endl;
        cin.get();
        cout << endl;
        break;
    }
    cin.get();
    cout << "**A GROUP OF MEN ENTERS THE BUILDING. BACK UP HAS ARRIVED." << endl << endl;
    if (input1 == 1)
    {
        cout << "Commander Wolfe: Don't worry Marius, everything'll be fine. We'll catch 'em." << endl;
        cout << "Marius: Fine... FINE!? YOU DON'T HAVE TO TELL THE WIFE AND KIDS THEIR FATHER IS" << endl;
        cout << "       TAKEN BY TERRORISTS!" << endl;
        cout << "Wolfe: I... Marius..." << endl << endl;
    }
    else if (input1 == 2)
    {
        cout << "Commander Wolfe: Don't worry Marius. We'll get them." << endl;
        cout << "Marius: My brother. He isn't an Accountant, isn't he? You lied." << endl;
        cin.get();
        cout << "Wolfe: Marius... I..." << endl;
        cout << "Marius: Don't ever talk to me again." << endl << endl;
    }
    else if (input1 == 3)
    {
        cout << "Commander Wolfe: Don't worry Marius, go home. We'll take care of the rest." << endl;
        cout << "        Hey Sledge, let's get out boy home ja!" << endl;
        cout << "Seamus Cowden: Hey buddy, chopper's here! Let's go." << endl;
        cout << "*Dom - Dominic. I- I'm sor-. I'm sorry." << endl << endl;
    }
    else if (input1 == 4)
    {
        cout << "Commander Wolfe: Don't worry, Marius. I got you. Let's get you patched up and we will go get your brother." << endl;
        cout << "*Dom - Dominic. I- I'm sor-. I'm sorry." << endl;
    }
    cin.get();
    system("CLS");
    //-------------------------------------------------------------------------------------

    if (input1 == 1)
    {
        cout << "That's how it all started. I am now a member of the GSG 9, a German anti-terrorism force." << endl;
    }
    else if (input1 == 2)
    {
        cout << "That's how it all started. I am now a member of the GSG 9, the same force that MY BROTHER served." << endl;
    }
    else if (input1 == 3)
    {
        cout << "That's how it all started... I was weak... scared back then. I felt powerless." << endl;
        cout << "Now I am a member of the GSG 9, a German anti-terrorism force. Ready to face anything." << endl;
    }
    else
    {
        cout << "That's how it all started. Every day the scar on my arm continues to remind me of this day." << endl;
        cout << "But my injury wasn't in vain. I am now a member of the GSG 9, a German anti-terrorism force." << endl;
    }
    cout << "I don't just work for the German people, I work for those who cannot protect themselves." << endl;
    cout << "I work to prevent terrorists and to save hostages so that my situation will never be repeated." << endl;
    cout << "To this day, I am still searching for my brother because I know... I KNOW he's still alive." << endl << endl;
    cin.get();
    system("CLS");
    return input1;
}

int chapterTwo(MyCharacter marius, Characters john, Characters samuel, Characters basicEnemy, int resultChapterOne)
{
    float myShot, enemyShot, spot;
    float healthEnemy1 = basicEnemy.health;
    float healthEnemy2 = basicEnemy.health;
    int bulletsLeft = 4;
    int died;
    int result = 1;
    int input1 = 1; // Sam: permission to shoot hostile section
    int input2 = 1, input2b = 1, input2c = 1, input2d; // check out noise or ignore section
    int input3 = 1, input3b = 1; // if ignore noise. left door or right door

    do
    {
        result = 1; // state of Marius. 1 = alive, 2 = dead
        marius.health = 100;
        cout << "                      CHAPTER TWO            " << endl << endl;
        cout << "Location: Hannover, Germany." << endl;
        cout << "Briefing: Bank robbery in progress since yesterday night, a hostage is captured by unknown threats." << endl;
        cout << "       You and your team just arrived outside of the bank. Hostiles are alert but are unaware " << endl;
        cout << "       of your presence. Use this to your advantage." << endl;
        cout << "       You are to eliminate all hostiles and secure the hostage." << endl << endl;
        cin.get();
        cout << "Marius statistics" << endl;
        cout << "Fighting damage: " << marius.damage << "." << endl;
        cout << "Health         : " << marius.health << "." << endl;
        cout << "Hit chance     : " << marius.hitChance << "/10." << endl;
        cout << "**Remember, all bullets deal 100 damage when hit." << endl << endl;
        cin.get();
        cout << "Team members: Samuel Krieg. A retired German marksman with over 147 confirmed kills." << endl;
        cout << "              Sam seems tough in training but is softer than a teddy bear. He has a daughter and a wife." << endl;
        cout << "              Sam is stationed on top of a building beside the bank." << endl;
        cout << "              His sniper is equipped with a thermal scope allowing him to see through smoke, low-visible areas " << endl;
        cout << "              as well as scanning ahead for threats, and possibly eliminate them." << endl;
        cout << "              He is your eye and will make crucial call-outs. Sam has a suppressor for stealth kills." << endl << endl;

        cout << "              Stats: Hand to hand combat: " << samuel.damage << " damage (very weak)" << endl; // 10
        cout << "                     Health: 100" << endl;
        cout << "                     Hit chance: " << samuel.hitChance << " out of 10" << endl << endl; // 10 / 10

        cout << "              John Marx. A Canadian-German ground operator for the JTF2, frequent missions with the GSG 9." << endl;
        cout << "              John loves to tell stories and make jokes during serious times and has very dark humour due to" << endl;
        cout << "              his childhood and military scars. However, his teammates' testimonies all" << endl;
        cout << "              describe him to be the most resilient, trustworthy and reliable operator." << endl;
        cout << "              His background in Canada allows him to stay strong in tough weather conditions." << endl;
        cout << "              John loves to ski and often join Judo tournaments, however, he has a hard time with the" << endl;
        cout << "              ladies and is STILL single." << endl;
        cout << "              With his quick reflexes and strong skills, John will be entering the hot zone with you." << endl << endl;

        cout << "              Stats: Hand to hand combat: " << john.damage << " damage(strong)" << endl;
        cout << "                     Health: " << john.health << endl;
        cout << "                     Hit chance: " << john.hitChance << " out of 10" << endl << endl;
        cin.get();
        cout << "Remember your teammates' statistics for the mission. Good luck, Marius!" << endl;
        system("PAUSE");
        system("CLS");

        cout << "Marius: The building is in sight boys! Samuel, did you get that sniper working yet?" << endl << endl;
        cin.get();
        cout << "Samuel: Already done, Marius. In the nest and ready." << endl << endl;
        cin.get();
        cout << "Marius: John, with me." << endl << endl;
        cin.get();
        cout << "John: Right behind you, eh." << endl << endl;
        cin.get();
        cout << "Samuel: It's cozy up here guys, nice view and everything!" << endl;
        cout << "Marius: Let's focus here Sam." << endl << endl;
        cin.get();
        cout << "Samuel: Hostile in sight around your corner, he's armed and unaware. Permission to use deadly forces?" << endl << endl;
        cout << "NOTE: You've encountered a Basic Enemy. Intel from HQ states the characteristics of this threat is as follows:" << endl;
        cout << "Damage: " << basicEnemy.damage << endl;
        cout << "Health: " << basicEnemy.health << endl;
        cout << "Hit Chance: " << basicEnemy.hitChance << " out of 10." << endl;
        cout << "Awareness: " << basicEnemy.awareness << " out of 10." << endl << endl;
        cin.get();
        cout << "Samuel: Marius? Permission to eliminate the hostile?" << endl;
        cout << "1. When you're ready, Sam!                     2. No, we got it." << endl << endl;

        cin >> input1;
        while (input1 != 1 && input1 != 2)
        {
            cout << "Invalid input. Please enter 1 or 2." << endl;
            cin >> input1;
        }
        switch (input1)
        {
        case 1: // Samuel will shoot and hit
            cout << "HIT!!!" << endl;
            break;
        case 2: // You and John will shoot
            myShot = rand()%10 + 1; // generate random number for myShot
            if (myShot <= marius.hitChance) // if that number is smaller or equal to marius.HitChance, it is a hit
            {
                cout << "HIT!!!" << endl;
            }
            else // else, Marius doesn't hit
            {
                spot = rand()%10 + 1; // check to see if the enemy was aware of that missed shot or not
                cout << "MISSED." << endl;
                if (spot <= basicEnemy.awareness) // spotted. combat sequence
                {
                    cout << "Marius: He's spotted us! Hide behind the car!" << endl;
                    cout << "Samuel: Target is moving, I can't get proper aim on him, it's up to you guys." << endl;
                    cin.get();
                    do
                    {
                        cout << "Marius and John shoot: ";
                        if (myShot <= marius.hitChance || myShot <= john.hitChance)
                        {
                            cout << "HIT!" << endl;
                            healthEnemy1 -= 100;
                        }
                        else
                        {
                            cout << "MISS!" << endl;
                            cin.get();
                            cout << "Enemy shoots: MISS!" << endl;
                            myShot = rand()%10 + 1;
                        }
                        cin.get();
                    }
                    while (healthEnemy1 > 0);   // do while
                }
                else // not spotted. Samuel will kill the hostile
                {
                    cout << "John: He hasn't spotted us yet." << endl;
                    cout << "Samuel: Let me take him out." << endl;
                    cin.get();
                    cout << "HIT!!" << endl;
                } // else
            } // if player misses and enemy spotted player
        } // switch

        cout << "Samuel: The path is clear. Proceed to entrance." << endl;
        cin.get();
        cout << "John: Let's go." << endl;
        cin.get();
        cout << "John: Hold on, do you hear that Marius? It sounds like someone is screaming for help." << endl;
        cin.get();
        cout << "Marius: Yeah, I hear that too." << endl;
        cout << "1. Let's check it out.            2. Focus on the mission, we might lose the hostage AND the culprits." << endl;

        cin >> input2;
        // if choice == 1. Marius' brother dies but he becomes a hero
        // if choice == 2. Marius' brother lives, but he becomes a vigilante and he is the most wanted in the world

        while (input2 != 1 && input2 != 2)
        {
            cout << "Invalid input. Enter 1 or 2." << endl;
            cin >> input2;
        }
        if (input2 == 1) // -------------------------- ignore / check things out
        {
            cout << "Marius: Over there, to the right." << endl;
            cin.get();
            cout << "John: Do you think we'll find something, someone here?" << endl;
            cin.get();
            cout << "Marius: I don't know, but let's hope we do, or else the Commander won't be happy." << endl;
            cin.get();
            cout << "John: You know, one of our operations back in Canada was to scout out the mountains up in BC." << endl;
            cout << "      We suspected that there were terrorists hiding up in the mountains and keeping Aboriginal people hostage." << endl;
            cout << "      We were a four man team with this new kid and he spotted something moving in the snow." << endl;
            cin.get();
            cout << "John: I'll be honest, we all thought he was hallucinating from walking too much, but we agreed to check it out." << endl;
            cin.get();
            cout << "Marius: And? What was in the snow?" << endl;
            cin.get();
            cout << "John: Two kids no older than 12. But they knew there way around the mountains and have been hiding there for" << endl;
            cout << "      for 2 weeks. They survived on fish and bear meat reserves." << endl;
            cin.get();
            cout << "John: My point is, that new kid on our team spotted something we would've never noticed. Obviously our" << endl;
            cout << "      Commander thought he was hallucinating at first but we ended up rescuing those two kids." << endl;
            cout << "      So... Maybe we'll find something here, it's worth the risk." << endl;
            cin.get();
            cout << "Marius: Let's hope you're right." << endl;
            cin.get();
            cout << "Samuel: Armed guard at your 9 o'clock. He's unaware but is moving so I can't get a proper shot." << endl;
            cout << "        You'll have to take 'em out." << endl;
            cin.get();
            cout << "Samuel: Heeey, a guard all the way out here! That must be a good sign eh!? Why would a guard be out here instead of in there?" << endl;
            cin.get();
            cout << "Marius: He's clueless - and sleepy! Taking him out would be so fun for us." << endl;
            cout << "John: Hasn't been AS fun for the hostages though, am I right? Haha." << endl;
            cin.get();
            cout << "1. Wouldn't wanna be them right?                    2. Stop, you're not funny. My brother was taken hostage." << endl;
            cin >> input2b;
            while (input2b != 1 && input2b != 2)
            {
                cout << "Invalid. Please enter 1 or 2." << endl;
                cin >> input2b;
            }
            if (input2b == 1) // agrees and laughs with joke
            {
                cout << "John: Yeaaaaah. Let's just hope they're still alive, get 'em back and maybe we can get this promotion eh?" << endl;
                cin.get();
            }
            else if (input2b == 2) // disagrees with joke
            {
                cout << "John: Relax bro it's a joke. I'm glad I'm Canadian, 'least I got some humour in me." << endl;
                cin.get();
            }
            cout << "John: Jokes aside though, let's hope we can get 'em back home safely." << endl;
            cin.get();
            cout << "Marius: That is, if that guy is guarding SOMEONE and not SOMETHING." << endl;
            cin.get();
            cout << "Marius; John and I are in position, Sam." << endl;
            cout << "John: Take him out Marius." << endl;

            myShot = rand()%10 + 1; // generate random number for myShot
            if (myShot <= marius.hitChance) // if that number is smaller or equal to marius. HitChance, it is a hit
            {
                cout << "HIT!!!" << endl;
            }
            else // else, Marius doesn't hit
            {
                spot = rand()%10 + 1; // check to see if the enemy was aware of that missed shot or not
                cout << "MISSED." << endl;
                if (spot <= basicEnemy.awareness) // spotted. combat sequence
                {
                    cout << "Marius: He saw us! get down!" << endl;
                    cin.get();

                    while (myShot > marius.hitChance && bulletsLeft > 0 && result != 0) // play if shot was missed, bullets left and not dead
                    {
                        myShot = rand()%10 + 1;
                        cout << "Marius shoots: MISS!" << endl;
                        cout << "Marius: I got " << bulletsLeft << " bullets left!" << endl;
                        bulletsLeft--;
                        cin.get();
                        enemyShot = rand()%10 + 1; // check to see if enemy has hit Marius
                        if (enemyShot <= basicEnemy.hitChance)
                        {
                            cout << "Enemy shoots: HIT!" << endl;
                            cout << "YOU DIED." << endl;
                            cin.get();
                            system("CLS");
                            cout << "YOU DIED." << endl;

                            cout << "**You died in a gun fight. Improve your weapon skills to improve your chances of winning." << endl;
                            result--;
                        }
                        cout << "Enemy shoots: MISS!" << endl;
                        cout << "John: Try again!" << endl << endl;
                        cin.get();
                    }
                    if (bulletsLeft > 0)
                    {
                        cout << "Marius: HIT! Enemy down." << endl;
                        cout << "Marius: Reloading." << endl;
                        healthEnemy2 -= 100;
                        bulletsLeft = 4;
                    }
                    else if (bulletsLeft == 0 && marius.health > 0)
                    {
                        cout << "Marius: Reloading!" << endl;
                        cin.get();
                        cout << "John: Let me shoot him." << endl;
                        cin.get();
                        cout << "John: I got him!!" << endl;
                        cin.get();
                        healthEnemy2 -= 100;
                        cout << "John: Threat eliminated." << endl;
                        cin.get();
                    }
                } // if enemy noticed Marius
                else // if enemy hasn't noticed Marius. Shot was missed
                {
                    cout << "John: Shoot again brother. He hasn't noticed us." << endl;
                    cin.get();
                    cout << "Marius: HIT! Got him." << endl;
                    healthEnemy2 -= 100;
                    cin.get();
                    cout << "John: Not too shabby!" << endl;
                    cin.get();
                } // enemy did not notice Marius
            } // if Marius didn't hit
            if (result == 0)
                continue;
            cout << "Samuel: Status update boys! How are things going down there?" << endl;
            cin.get();
            cout << "Marius: Dude, you can see more than we can. Question is, how are things going UP THERE?" << endl;
            cin.get();
            cout << "Samuel: Nice and cozy. Almost fell asleep." << endl;
            cin.get();
            cout << "John: Alright, let's get to it Marius, can't waste time." << endl; // can be interpreted positively or negatively.
            cin.get();
            cout << "Marius: Hello? Anyone in there?" << endl;
            cin.get();
            cout << "**silence" << endl;
            cin.get();
            cout << "John: Oh come on, you tellin' me we came all this way here for nothing?" << endl;
            cin.get();
            cout << "Marius: Hold on, look." << endl;
            cout << "**Sees a lock on a lever." << endl;
            cin.get();
            cout << "John: Damn, what do we do now?" << endl;
            cin.get();
            cout << "Marius: Well, we gotta open it to see what's inside the container" << endl;
            cin.get();
            cout << "John: What do you propose we do?" << endl << endl;
            cout << "1. Open by shooting the lock.                      2. Lock pick it." << endl;
            cin >> input2c;
            while (input2c != 1 && input2c != 2 || marius.mySkills.lockPicking == 0 && input2c == 2) // error trap
            {
                if (marius.mySkills.lockPicking == 0 && input2c == 2)
                {
                    cout << "Invalid option. You have not unlocked this skill." << endl;
                }
                else
                {
                    cout << "Invalid. Please enter 1 or 2." << endl;
                }
                cin >> input2c;
            }
            if (input2c == 1)
            {
                cout << "Marius: I say we bust this thing open the traditional way." << endl;
                cin.get();
                cout << "John: Heeey that's more like it." << endl;
                cin.get();
                cout << "BOOM!" << endl;
                cin.get();
            }
            else if (input2c == 2)
            {
                cout << "Marius: The Commander taught me one or two tricks about lock picking." << endl;
                cin.get();
                cout << "John: Is that so? Is this true, Samuel?" << endl;
                cin.get();
                cout << "Samuel: If he doesn't open that lock I'm treating all of us free beer when we get back." << endl;
                cin.get();
                cout << "John: Well then, I guess IT IS true. Well, Kapitän, show me how it's done!" << endl;
                cin.get();
                cout << "Marius: My lock picking gear... Ah, there it is, it's in this pocket. Alright, step aside, recruit." << endl;
                cin.get();
                cout << "**A few seconds of silence as Marius tries to open this lock." << endl;
                cin.get();
                cout << "Marius: Annnnd, done!" << endl;
                cin.get();
                cout << "John: Wunderbar mein Freund!" << endl;
                cin.get();
            }
            cout << "**Cargo container door swings open." << endl;
            cin.get();
            cout << "**   Two women are in the container, one with a bomb vest, sat down and tied to a chair." << endl;
            cout << "     The other is standing up, pointing a pistol at you." << endl;
            cin.get();
            cout << "Yes... You read that right, she is pointing a pistol at you." << endl;
            cin.get();
            cout << "Marius: WHOA WHOA WHOA! STOP!" << endl;
            cin.get();
            cout << "John: PUT THAT GUN DOWN, NOW!" << endl;
            cin.get();
            cout << "Samuel: WHAT'S GOING ON?! MARIUS, JOHN!" << endl;
            cin.get();
            cout << "**John draws his rifle." << endl;
            cin.get();
            cout << "John: DROP THE GUN OR I SHOOT YOU." << endl;
            cout << "Marius: John!" << endl;
            cout << "**MARIUS DRAWS GUN." << endl;
            cin.get();
            cout << "**WOMAN SHOOTS JOHN, TURNS TOWARDS MARIUS." << endl;
            john.health -= 100;
            cin.get();
            cout << "**MARIUS SHOOTS WOMAN." << endl;
            cin.get();
            cout << "Marius: JOHN, JOHN, ARE YOU OKAY? WHERE DID YOU GET HIT AT? JOHN!" << endl;
            cout << "**John's current health: " << john.health << endl;
            cin.get();
            cout << "John: Oohh, I don't even, know. Ooooohhh." << endl;
            cout << "Marius: I got you John, let's patch you up. Watch out, you won't fully heal with that wound." << endl;
            john.health += 80;
            cout << "**John's current health: " << john.health << endl;
            cin.get();
            cout << "Samuel: Is everything good down there? Talk to me here!" << endl;
            cin.get();
            cout << "John: I thought you were sleeping, Sam!" << endl;
            cin.get();
            cout << "Samuel: Damn it, why couldn't she aim for the head!" << endl;
            cin.get();
            cout << "John: Ha haaaaaaa. I can't die. Canadians don't die!" << endl;
            cin.get();
            cout << "Marius: Alright, let's patch you up." << endl;
            cout << "        Annnnnd, done. The wound should hold." << endl;
            cout << "**John's current health: " << john.health << endl;
            cin.get();
            cout << "John: Thanks man. You're much more helpful than Sam up their eh?" << endl;
            cout << "Samuel: Yeah yeah..." << endl;
            cin.get();
            cout << "**Marius, almost forgetting about the other woman, stands up and approaches her with caution." << endl;
            cout << "  Marius rips the tape off of her mouth." << endl;
            cin.get();
            cout << "Marius: Tell me why I shouldn't shoot you right here." << endl;
            cin.get();
            cout << "** Woman gasps for air quickly." << endl;
            cout << "Woman: I - I work in the bank. They attacked us yesterday a - and I got knocked out." << endl;
            cout << "       I woke up in this container abo - about an hour ago, or was it two? I can't tell time anymore." << endl;
            cin.get();
            cout << "Woman: Please, help me. I need to get out of here, PLEASE!" << endl;
            cin.get();
            cout << "John: Alright calm down there. Care to explain to us why you're wearing a bomb vest why your friend their" << endl;
            cout << "      shot me? How do can I guarantee you're not going to kill us all?" << endl;
            cin.get();
            cout << "Woman: Th-the other woman. She is not my friend. She tied me up and put this vest around me." << endl;
            cout << "       She said she would pretend to be innocent when the police arrives then use me to kill everyone!" << endl;
            cout << "       She set me up!" << endl;
            cin.get();
            cout << "Marius: Yes, yes, we need you here right now." << endl;
            cout << "Dispatcher: Copy that." << endl;
            cout << "Marius: Alright, I've called the bomb unit to come. You stay here." << endl;
            cin.get();
            cout << "Woman: But -" << endl;
            cin.get();
            cout << "Marius: Before we listen to any of your words, that bomb needs to be disarmed right away." << endl;
            cout << "        It's not a dead man's switch and doesn't have a receiver to receive the detonation," << endl;
            cout << "        nor does it have a timer. Plus there's still a lot of parts left over there." << endl;
            cin.get();
            cout << "John: Looks like Sally there didn't finish building the bomb. Pfft as long as I'm here, NOTHING can kill me" << endl;
            cin.get();
            cout << "Marius: John can you just - please? For one minute, zip it." << endl;
            cin.get();
            cout << "Marius: Just hold tight, everything will be alright. Okay?" << endl;
            cout << "Woman: Okay." << endl;
            cin.get();
            cout << "Marius: Alright. Let's go." << endl;
            cin.get();
            cout << "Woman: Wait! I remember something else. The other woman mentioned a name - and, and the plot of all this!" << endl;
            cin.get();
            cout << "John: My god, what now?" << endl;
            cin.get();
            cout << "Marius: John, just. Please. What did you want to say?" << endl;
            cin.get();
            cout << "Woman: She said something about... revenge. There was a name, it sounded important - I just... I can't remember" << endl;
            cin.get();
            cout << "John: Lady if you can't remember THEN WHY DID YOU SAY WAIT -"<< endl;
            cin.get();
            cout << "Marius: JOHN IF YOU SAY ONE MORE WORD I WILL KNOCK YOU OUT RIGHT NOW!" << endl;
            cin.get();
            cout << "Woman: It was... it was... This whole thing was to meant to destroy the GSG 9. The leader is" << endl;
            cin.get();
            cout << "Marius: WHO?" << endl;
            cin.get();
            cout << "Woman: Dominic" << endl;
            cin.get();
            cout << "Woman: Streicher" << endl;
            cin.get();
            cout << "Marius: My... My brother." << endl;
            system("PAUSE");
            system("CLS");
            // make something so if previous chapter choice was 2, you know...
        } // if player chose to check things out
        else if (input2 == 2) // -------------------------- ignore / check things out
        {
            cout << "Marius: We can't let anything distract us from the mission. Our safety is the number one priority and" << endl;
            cout << "        the mission comes second. Choosing the unknown option increases the risk of failing the mission" << endl;
            cout << "        as well as jeopardizing our safety." << endl;
            cin.get();
            cout << "John: *Sigh. Aye aye, captain." << endl;
            cin.get();
            cout << "Samuel: You got two ways to enter the bank. Obviously, the main entrance is heavily fortified with booby traps," << endl;
            cout << "        barbed wire and reinforced walls, so, we might want to avoid that." << endl;
            cin.get();
            cout << "John: Looks like we got the back entrance or the sewers" << endl << endl;
            cout << "1. Back entrance                              2. Sewers" << endl;
            cin >> input3;
            while (input3 != 1 && input3 != 2 || input3 == 2 && marius.mySkills.endurance == 0)
            {
                if (input3 != 1 && input3 != 2)
                {
                    cout << "Invalid input. Enter 1 or 2." << endl;
                }
                else if (input3 == 2 && marius.mySkills.endurance == 0)
                {
                    cout << "Invalid option. Your endurance is too weak to be in the sewers. Select another option." << endl;
                }
                cin >> input3;
            } // error trap
            if (input3 == 1) // back entrance
            {
                cout << "Marius: Let's take the back." << endl;
                cin.get();
                cout << "John: Alrighty sir." << endl;
                cin.get();
                cout << "Samuel: Coast looks clear. I'm moving the nest to the back of the building." << endl;
                cin.get();
                cout << "** Moments later." << endl;
                cin.get();
                cout << "Marius: **Whispering We're in front of the gate, are you fully set up." << endl;
                cin.get();
                cout << "Samuel: Lock and loaded, nest is set." << endl;
                cin.get();
                cout << "Marius: Two tangos in sight, one armed." << endl;
                cout << "John: Let's do this!" << endl;
                cin.get();
                cout << "**Busts door open" << endl;
                cin.get();
                cout << "Enemy 1: Huh?" << endl;
                cin.get();
                cout << "John: Eat bullet!" << endl;
                cout << "     **Shoots enemy" << endl;
                cin.get();
                cout << "Marius: Let's see if my boxing skills have improved!" << endl;
                while (healthEnemy2 > 0)
                {
                    cout << "Marius health: " << marius.health << endl;
                    cout << "Marius attacks: " << marius.damage << " damage." << endl;
                    healthEnemy2 -= marius.damage;
                    cout << "Enemy health: " << healthEnemy2 << endl;
                    cout << "Enemy attacks: " << basicEnemy.damage << " damage." << endl << endl;
                    marius.health -= basicEnemy.damage;
                    cin.get();
                } // fighting sequence
                cout << "Marius: Tango eliminated" << endl;
                cin.get();
                cout << "John: OOOOH AND IT'S A KNOCCCCCK OUTTTT" << endl;
                cin.get();
                cout << "Marius: Alright. Let's keep going John. We'll celebrate when we get ba-." << endl;
                cin.get();
                cout << "**3 enemies show up." << endl;
                cin.get();
                cout << "John: THEY KNOW WE'RE HERE." << endl;
                cin.get();
                cout << "Marius: That's probably because of your LOUD and YAPPY voice." << endl;
                cin.get();
                cout << "**Getting shot at" << endl;
                cin.get();
                cout << "John: Oh come on! It was a good K.O." << endl;
                cout << "      You knocked him out the same way I got knocked out in the military!" << endl;
                cin.get();
                cout << "John: Yo- **getting shot at** You know, I always preferred choking someone out!" << endl;
                cout << "      It jus-**getting shot at** it just seems much more effective ya know? Your bones don't break," << endl;
                cout << "      the guy's face remains intact. The guy passes out quietly. I mean. It's really effective!" << endl;
                cin.get();
                cout << "Marius: Stop talking and start shooting!" << endl;
                cin.get();
                cout << "John: Here! Take a band-aid and heal yourself!" << endl;
                cin.get();
                healthEnemy2 = 80; // reset health of new enemy
                marius.health += 30;
                cout << "You've received 30 health." << endl;
                cin.get();
                while (marius.health > 0 && healthEnemy2 > 0)
                {
                    cout << "HEALTH: " << marius.health << endl;
                    cout << "Marius shoots: ";
                    myShot = rand()%10 + 1; // generate random number for myShot
                    if (myShot <= marius.hitChance) // if that number is smaller or equal to marius.HitChance, it is a hit
                    {
                        cout << "HIT!!!" << endl;
                        break;
                    }
                    else
                    {
                        cout << "MISS." << endl;
                    }
                    cin.get();
                    cout << "Enemy health: " << healthEnemy2;
                    cout << "Enemy shoots: ";
                    enemyShot = rand()%10 + 1;
                    if (enemyShot <= basicEnemy.hitChance)
                    {
                        cout << "HIT!" << endl;
                        marius.health -= 100;
                        if (marius.health > 0)
                        {
                            cout << "Marius: I'm wounded!" << endl;
                        }
                        else if (marius.health <= 0)
                        {
                            system("CLS");
                            cout << "YOU DIED FROM THE GUN FIGHT." << endl << endl << endl;
                            cout << "Press 1 to continue." << endl;
                            cin >> died;
                            while (died != 1)
                            {
                                cout << "Invalid input. Just please, all you have to do is type in number 1 and enter" << endl;
                                cin >> died;
                            }
                            result--;
                        } // part of else if player dies
                    } // if enemy hits
                    else
                        cout << "MISS." << endl << endl;
                } // shooting sequence
                if (result == 0)
                    continue;
                cin.get();
                cout << "Marius: Hostile eliminated." << endl;
                cin.get();
                cout << "John: Second hostile down!" << endl;
                cin.get();
                cout << "John: The third guy! He's running away!" << endl;
                cin.get();
                cout << "John: ** Shoots him in the leg." << endl;
                cin.get();
                cout << "Marius: WHO ARE YOU!? HOW MANY ARE LEFT! TALK OR I SHOOT YOU" << endl;
                cin.get();
                cout << "Enemy 3: You can't threaten me." << endl;
                cin.get();
                cout << "** John shoots him in the other leg." << endl;
                cin.get();
                cout << "Enemy 3: AHHHHHHH" << endl;
                cin.get();
                cout << "John: Next up will be your toes, then your fingers, then your arm." << endl;
                cin.get();
                cout << "Enemy 3: WHO- COUGH COUGH. WHO ARE YOU!?" << endl;
                cin.get();
                cout << "Marius: oh come on. You know who we are." << endl;
                cin.get();
                cout << "Enemy 3: The boss. He was RIGHT! You GSG 9 are MONSTERS!" << endl;
                cin.get();
                cout << "Marius: WHO IS YOUR BOSS? HOW MANY OF YOU ARE LEFT UP THERE?" << endl;
                cin.get();
                cout << "John: Hey, listen. We can do this the easy way, or the HARD way." << endl;
                cin.get();
                cout << "Enemy 3: My boss. He KNOWS you people, inside out. He LISTENS to you." << endl;
                cin.get();
                cout << "John: Right, and I'm going to get a girlfriend after this. Tell me lies again, I dare you." << endl;
                cout << "      I DOUBLE DARE YOU." << endl;
                cin.get();
                cout << "Enemy 3: He knows you. You, you're John Marx, the in Germany, we call you Jaeger!" << endl;
                cin.get();
                cout << "Marius: What a nice nickname! Hunter! Hey man, what's mine?" << endl;
                cin.get();
                cout << "Enemy 3: You? Cough cough** I have no idea who the hell you are." << endl;
                cin.get();
                cout << "John: Well, I guess I'm just that cooler!" << endl;
                cin.get();
                cout << "Marius: Well, you see. People who see me, tend to not stay alive... So, I got no names." << endl;
                cout << "John: 'Cause no one's been alive to tell the tale! Suffering from success I see." << endl;
                cin.get();
                cout << "Marius: Alright buddy. Let's get to the point. Who is your boss, tell me, and I will" << endl;
                cout << "        get your legs fixed AND, and, reduce your prison sentence for cooperating with me." << endl;
                cin.get();
                cout << "Marius: Sound good?" << endl;
                cin.get();
                cout << "Enemy 3: No point, I- I'm about to ble- bleed out anyway." << endl;
                cin.get();
                cout << "Enemy 3: But I will tell you. My boss. He used to for with you." << endl;
                cin.get();
                cout << "John: Bull crap. No GSG 9 would turn int a terrorist." << endl;
                cin.get();
                cout << "Enemy 3: Onl- only the ones who got abandoned and forgotten. He used to work with your leader." << endl;
                cin.get();
                cout << "Marius: Oh really? And what's my leader's name?" << endl;
                cin.get();
                cout << "Enemy 3: Commander Wolfe." << endl;
                cin.get();
                cout << "John: Unbelievable." << endl;
                cout << "Marius: Alright one last time. Your boss or I let you suffer slowly." << endl;
                cin.get();
                cout << "Enemy 3: He was one of you! But he was forgotten. Abandoned." << endl;
                cout << "         Dom" << endl;
                cin.get();
                cout << "Marius & John: ..." << endl;
                cin.get();
                cout << "Enemy 3: Dominic Strei-." << endl;
                cin.get();
                cout << "Marius: No, no it can't be." << endl;
                cout << "** Enemy 3 gasps for air." << endl;
                cin.get();
                cout << "Marius: No, no, no, no. Stay with me here. No noooo no" << endl;
                cout << "** Terrorist dies." << endl;
                cin.get();
                cout << "John: Who is this Dominic?" << endl;
                cin.get();
                cout << "John: Strei? Oooooohh. Dominic." << endl;
                cin.get();
                cout << "John: Dominic Streicher. Your brother." << endl; // back entrance
            }

            else if (input3 == 2) // sewers
            {
                cout << "Marius: Let's take the sewers." << endl;
                cin.get();
                cout << "John: Damn you! You just HAD to pick that didn't ya." << endl;
                cin.get();
                cout << "Samuel: Well... It's the safest way!" << endl;
                cin.get();
                cout << "John: Shut up man, you're sitting up there all nice and cozy!" << endl;
                cin.get();
                cout << "Samuel: Chill man, I'm going to have to move spots to get a better view." << endl;
                cin.get();
                cout << "John: Tough work." << endl;
                cin.get();
                cout << "Aight. We'll see you on the other side, Sam. Let's go John." << endl;
                cin.get();
                cout << "*Moments later." << endl;
                cin.get();
                cout << "Marius: **Whispering We're in." << endl;
                cin.get();
                cout << "**An enemy is right in front of you, turning their back against you." << endl;
                cin.get();
                cout << "John yells: ANNNND WE'RE IN!!!" << endl;
                cin.get();
                cout << "Enemy: What the - !" << endl;
                cin.get();
                cout << "Marius: John you idio-" << endl;
                cin.get();
                cout << "Marius: You wanna fight? Huh? Let's go!" << endl << endl;
                while (healthEnemy2 > 0)
                {
                    cout << "Marius health: " << marius.health << endl;
                    cout << "Marius attacks: " << marius.damage << " damage." << endl;
                    healthEnemy2 -= marius.damage;
                    cout << "Enemy health: " << healthEnemy2 << endl;
                    cout << "Enemy attacks: " << basicEnemy.damage << " damage." << endl << endl;
                    marius.health -= basicEnemy.damage;
                    cin.get();
                } // fighting sequence
                cout << "Marius: Threat eliminated." << endl;
                cin.get();
                cout << "John: Knockkkk outtttttt!!!" << endl;
                cin.get();
                cout << "Marius: John can you please. Keep it down!" << endl;
                cin.get();
                cout << "John: Alright, fine. Let's just go." << endl;
                cin.get();
                cout << "Marius: We've encountered and eliminated a hostile, do you copy?" << endl;
                cin.get();
                cout << "Samuel: ..." << endl;
                cin.get();
                cout << "Marius: Hello? Sam?" << endl;
                cout << "John: Looks like comms are out." << endl;
                cin.get();
                cout << "Marius: Let's move on, we'll try and get a better signal at the next checkpoint." << endl;
                cin.get();
                cout << "Marius: Ah, looks like this door separates into two paths." << endl;
                cin.get();
                cout << "John: I'll go one way, you go the other. Your call." << endl;
                cout << "Marius: I'll go _________________" << endl;
                cout << "1. Left                          2. Right" << endl;
                //if i live, i will see my brother then I escape with him. I get branded a terrorist
                cin >> input3b;
                while (input3b != 1 && input3 != 2) // error trap
                {
                    cout << "Invalid. Enter 1 or 2." << endl;
                    cin >> input3b;
                }
                if (input3b == 1) // left
                {
                    cout << "Marius: I'll take the left." << endl;
                    cin.get();
                    cout << "John: Got it sir!" << endl;
                    cin.get();
                    cin.get();
                    cin.get();
                    cout << "Marius: Huh?" << endl;
                    cin.get();
                    cout << "**BOOM!!!!!" << endl;
                    cin.get();
                    cout << "Marius: JOHN!? JOHN! WHAT'S HAPPENING!" << endl;
                    cin.get();
                    cout << "**Sees John on the ground, half of his body is on one side of the room, the other half is gone." << endl;
                    cout << "Marius: F*#$!!!!!!!" << endl;
                    john.health = 0;
                    cin.get();
                    cout << "** A figure appears at the corner of Marius' eyes." << endl;
                    cin.get();
                    cout << "** Marius draws his rifle." << endl;
                    cout << "Marius: WHO IS IT, HANDS WHERE I CAN SEE!?" << endl;
                    cin.get();
                    cout << "?????: No... It can't be." << endl;
                    cin.get();
                    cout << "Marius: What the..." << endl;
                    cin.get();
                    cout << "Marius: Dominic. You're alive." << endl;
                    cin.get();
                    cout << "Dominic: What the. They made you join GSG 9!?" << endl;
                    cin.get();
                    cout << "Marius: Wh- what are you doing here!??" << endl;
                    cin.get();
                    cout << "Dominic: The real question is, WHY ARE YOU HERE!?" << endl;
                    cin.get();
                    cout << "Marius: THEY TOLD ME YOU WERE IN THE GSG 9! WHY DIDN'T YOU TELL ME!?" << endl;
                    cin.get();
                    cout << "Dominic: Do you not understand the word. \"Undercover\" agent?" << endl;
                    cin.get();
                    cout << "Marius: You lied to us. You lied to us all! And what are you doing here?" << endl;
                    cout << "        Why are you in this mess? Did you organize this? Are you A PART OF THIS!?" << endl;
                    cin.get();
                    cout << "** Marius points his rifle at Dominic." << endl;
                    cout << "   Dominic points his pistol at Marius." << endl;
                    cin.get();
                    cout << "Marius: If you don't explain the situation, I WILL shoot you. You just killed MY teammate!" << endl;
                    cout << "HE HAS A FAMILY! AND SO DO YOU!" << endl;
                    cout << "Dominic: Fine. I'll explain." << endl;
                    cin.get();
                    cout << "Dominic: Two years ago, I was an undercover agent in Russia, I didn't want you to come with me" << endl;
                    cout << "         on that \"vacation\". It was a MISSION! But you decided to come." << endl;
                    cin.get();
                    cout << "Dominic: But it's not your fault, I just didn't want you to be there because if anything DID HAPPEN." << endl;
                    cin.get();
                    cout << "Dominic: I didn't want you to be there to experience it." << endl;
                    cin.get();
                    cout << "Marius: Doesn't explain why you're here. TALK." << endl;
                    cin.get();
                    cout << "Dominic: My team and I got captured. The bastard Wolfe, yeah your Commander? Was supposed to send" << endl;
                    cout << "         reinforcements. BUT GUESS WHAT!? He said we were \"lost assets\" and decided that we didn't" << endl;
                    cout << "         help anymore." << endl;
                    cin.get();
                    cout << "Dominic: In order to survive, I had to work with the terrorists, be a rat. But they found out." << endl;
                    cout << "         That's when the GSG 9 started to come and rescue me, but it was waaaay too late." << endl;
                    cout << "         They even brought YOU into it! My own brother!" << endl;
                    cin.get();
                    cout << "Marius: Go on." << endl;
                    cin.get();
                    cout << "Dominic: As a result, I spent TWO years as a bandit. I escaped those terrorists and joined another terrorist" << endl;
                    cout << "         group. I had to live the life of shame, away from you, from mom and dad." << endl;
                    cin.get();
                    cout << "Marius: But that doesn't justify you killing innocent people and robbing the bank!" << endl;
                    cin.get();
                    cout << "Dominic: THE GSG 9 IS NOT INNOCENT, listen to me Marius." << endl;
                    cout << "         They give terrorists money to get rid of people they can't get rid of themselves." << endl;
                    cin.get();
                    cout << "Marius: What? I don-" << endl;
                    cin.get();
                    cout << "Dominic: Wolfe is corrupt! Come with me. You have to get away from those so called commanders" << endl;
                    cout << "         They are nothing but hitmen." << endl;
                    cin.get();
                    cout << "Dominic: I will stop all of this madness right now. This bank robbery is just a bait for the GSG 9 to" << endl;
                    cout << "         come. I didn't know YOU were in the operation!" << endl;
                    cin.get();
                    cout << "Dominic: Alright. Fine. I believe you." << endl;
                    cin.get();
                    cout << "** A group of men enter the building." << endl;
                    cout << "Marius: What is that?" << endl;
                    cin.get();
                    cout << "????: PUT YOUR HANDS UP! ARMED POLICE, PUT YOUR HANDS IN THE AIR!" << endl;
                    cin.get();
                    cout << "Dominic: LET'S GO, MARIUS!" << endl;
                    cin.get();
                    cout << "GSG 9: Marius! What are you doing!? Attention. Marius is armed and dangerous." << endl;
                    cout << "       Again, one of your operators have joined the terrorists." << endl;
                    cout << "GSG 9: Both subjects are ARMED and DANGEROUS." << endl;
                    system("PAUSE");
                    system("CLS");
                    cout << "                  YOU'VE FINISHED THE GAME WITH ONE ENDING!!" << endl;
                    cout << "** You escape with Dominic. You find out that your brother is alive and you are one of of the most" << endl;
                    cout << "   wanted man in Germany." << endl;
                    cout << "If you would like to play alternate endings, you may restart the game." << endl;
                    return 0;
                } // left door
                else if (input3b) // right
                {
                    cout << "Marius: I'll take the right." << endl;
                    cin.get();
                    cout << "Dominic: Wow. I guess you picked... The RIGHT way to go!" << endl;
                    cin.get();
                    cout << "Marius: Dude just shut u-" << endl;
                    cin.get();
                    cout << "** BOOM!" << endl;
                    cin.get();
                    cout << "**You died. This path was rigged with explosives." << endl;
                    result--; // indicates player died
                } // right door
            } // if player picks sewers
        } // ignore the noise. proceed with the mission
    }
    while (result == 0);
    result = input2; // if input2 == 1, they ignored the noise. if input2 == 2, they followed the noise
    return result;
}

int chapterThree(MyCharacter marius, Characters john, Characters samuel, Characters basicEnemy, Characters dominic, int resultChapterThree)
{
    float myShot, enemyShot, spot;
    float healthEnemy1 = basicEnemy.health;
    float healthEnemy2 = basicEnemy.health;

    int died;
    int result = 1;
    int input1 = 1; // pick a side: with the GSG 9 or with his brother
    int input2 = 1; // stairs or climb
    int input3;
    // if resultChapterThree == 1 that means he got the info from the interrogation
    // if resultChapterThree == 2 that means he got the info from the innocent lady
    do
    {
        cout << "                      CHAPTER THREE            " << endl << endl;
        cout << "Location: Hannover, Germany." << endl;
        cout << "Briefing: Bank robbery in progress. A hostage still captured." << endl;
        cout << "       Threats are no longer unknown and have been identified as former GSG 9 members." << endl;
        cout << "       The leader of the organized terrorist attack is Marius' brother, Dominic Streicher." << endl;
        cout << "       You and your team are regrouping outside the building, planning the rest of the operation. " << endl;
        cout << "       You are to eliminate all hostiles and secure the hostage." << endl << endl;
        cin.get();
        cout << "Come home safe, Marius." << endl;
        system("PAUSE");
        system("CLS");

        cout << "** Marius thinks to himself in shock." << endl;
        cin.get();
        cout << "Marius: I- I can't even." << endl;
        cin.get();
        cout << "My brother isn't... He isn't dead. Sho-Should I be happy?" << endl;
        cin.get();
        cout << "Or should I be angry, knowing that he was a GSG 9 member and not an accountant?" << endl;
        cin.get();
        cout << "That he lied to us about his day to day job? Putting himself in danger?" << endl;
        cin.get();
        cout << "Should I be mad that he organized a bank robbery and a terrorist act? That he is using hostages" << endl;
        cout << "     as bait to kill more people?" << endl;
        cin.get();
        cout << "Or... Or should I be mad at the Commanders for abandoning him?" << endl;
        cin.get();
        cout << "All the pain he must've been through, feeling betrayed, feeling lonely." << endl;
        cin.get();
        cout << "It all makes sense now." << endl;
        cin.get();
        cout << "That wasn't a vacation, he went on a mission in Russia." << endl;
        cin.get();
        cout << "But my childish attitude wanted to go on the \"vacation\" with him." << endl;
        cin.get();
        cout << "I was bothering him. I was like the sibling or parent at a kid's sports tournament." << endl;
        cin.get();
        cout << "I made the person on the field lose focus - because I was there." << endl;
        cin.get();
        cout << "He didn't want to hurt my feelings, telling me I couldn't come on the vacation to Russia with him." << endl;
        cin.get();
        cout << "But at the same time... He felt that bringing me would put me in harm's way." << endl;
        cin.get();
        cout << "No... But that doesn't justify taking hostages, plotting a terrorist act, killing innocent lives." << endl;
        cin.get();
        cout << "You know what... I've made up my mind." << endl;
        cin.get();
        cout << "1. The GSG 9 Commanders betrayed him, his actions are justified and is a result of the pain." << endl;
        cout << "2. My brother's actions are not justified. Putting innocent lives in danger makes him no different than terrorists" << endl;
        cin >> input1; // to kill dominic, or not to kill dominic
        while (input1 != 1 && input1 != 2)
        {
            cout << "Invalid input. Please enter 1 or 2." << endl;
            cin >> input1;
        } // error trap
        if (input1 == 1)
        {
            cout << "Marius: Then I must find him and escape with him." << endl;
            cin.get();
        }
        else
        {
            cout << "Then I MUST stop him before he puts someone else's life in danger." << endl;
            cin.get();
        }
        cout << "John: Um, Marius?" << endl;
        cin.get();
        cout << "John: I know you're still shocked knowing that your brother is alive." << endl;
        cin.get();
        cout << "John: But we have to focus here." << endl;
        cin.get();
        cout << "Marius: Oh, yeah... Right." << endl;
        cin.get();
        cout << "Samuel: Guys we've found their location. They are located on the second top floor." << endl;
        cin.get();
        cout << "Samuel: It'll be quite some distance walking up the stairs, plus you'll have to deal with hostiles." << endl;
        cin.get();
        cout << "1. Take the stairs                    2. Climb up." << endl;
        cin >> input2;
        while (input2 != 1 && input2 != 2 || input2 == 2 && marius.mySkills.climbing == 0)
        {
            if(input2 != 1 && input2 != 2)
            {
                cout << "Invalid option. Please enter 1 or 2." << endl;
            }
            else
            {
                cout << "Invalid. You haven't unlocked Climbing Skill." << endl;
            }
            cin >> input2;
        } // error trap
        if (input2 == 1) // stairs
        {
            cout << "Marius: We'll have to take the stairs." << endl;
            cin.get();
            cout << "John: Alright." << endl;
            cin.get();
            cout << "** Gets to the first floor." << endl;
            cin.get();
            cout << "John: Watch out for traps." << endl;
            cin.get();
            cout << "Marius: Gotcha." << endl;
            cin.get();
            cout << "** John shoots traps." << endl;
            cin.get();
            cout << "John: Proceed." << endl;
            cin.get();
            cout << "Samuel: Hold on guys, one hostile near the window." << endl;
            cin.get();
            cout << "** Samuel shoots" << endl;
            cin.get();
            cout << "Samuel: Tango down." << endl;
            cin.get();
            cout << "Marius: Hmm, this area looks weir-." << endl;
            cin.get();
            cout << "Marius: whouuuh" << endl;
            cin.get();
            cout << "John: Enemy spotted! He just tackled, Marius." << endl;
            cin.get();
            cout << "John: I can't get a proper shot, you're moving too much!" << endl;
            cin.get();
            cout << "Marius: You wanna fight, huh? LET'S GO!" << endl;
            while (healthEnemy1 > 0)
                {
                    cout << "Marius health: " << marius.health << endl;
                    cout << "Marius attacks: " << marius.damage << " damage." << endl;
                    healthEnemy1 -= marius.damage;
                    cout << "Enemy health: " << healthEnemy1 << endl;
                    cout << "Enemy attacks: " << basicEnemy.damage << " damage." << endl << endl;
                    marius.health -= basicEnemy.damage;
                    cin.get();
                } // fighting sequence

            cout << "Marius: Exactly, you can't beat me." << endl;
            cin.get();
            cout << "John: John watch out! Enemies in coming!" << endl;
            cin.get();
            cout << "Marius: Lock and load. Ready to engage!" << endl;
            cin.get();

            while (marius.health > 0 && healthEnemy2 > 0)
                {
                    cout << "HEALTH: " << marius.health << endl;
                    cout << "Marius shoots: ";
                    myShot = rand()%10 + 1; // generate random number for myShot
                    if (myShot <= marius.hitChance) // if that number is smaller or equal to marius.HitChance, it is a hit
                    {
                        cout << "HIT!!!" << endl;
                        break;
                    }
                    else
                    {
                        cout << "MISS." << endl;
                    }
                    cin.get();
                    cout << "Enemy health: " << healthEnemy2;
                    cout << "Enemy shoots: ";
                    enemyShot = rand()%10 + 1;
                    if (enemyShot <= basicEnemy.hitChance)
                    {
                        cout << "HIT!" << endl;
                        marius.health -= 100;
                        if (marius.health > 0)
                        {
                            cout << "Marius: I'm hit!" << endl;
                        }
                        else if (marius.health <= 0)
                        {
                            system("CLS");
                            cout << "YOU DIED FROM THE GUN FIGHT." << endl << endl << endl;
                            cout << "Press 1 to continue." << endl;
                            cin >> died;
                            while (died != 1)
                            {
                                cout << "Invalid input. Just please, all you have to do is type in number 1 and enter" << endl;
                                cin >> died;
                            }
                            result--;
                        } // part of else if player dies
                    } // if enemy hits
                    else
                        cout << "MISS." << endl << endl;
                } // shooting sequence
                cout << "John: What's your health, Marius!?" << endl;
                cin.get();
                cout << "** Getting shot at" << endl;
                cout << "Marius: I'm holding up. I'- I'm ** getting shot at ** I'm at " << marius.health << " health!" << endl;
                cin.get();
                cout << "John: Right! Take my band-aid!" << endl;
                cin.get();
                cout << "Marius: What's? No! You keep it!" << endl;
                cin.get();
                cout << "John: NOW IS NOT THE TIME! TAKE IT AND USE IT!"  << endl;
                cin.get();
                cout << "Marius: Alright! Alright!" << endl;
                marius.health += 80;
                cin.get();
                cout << "** Marius health increased by 80." << endl;
                cin.get();
                healthEnemy2 = basicEnemy.health;
                while (marius.health > 0 && healthEnemy2 > 0)
                {
                    cout << "HEALTH: " << marius.health << endl;
                    cout << "Marius shoots: ";
                    myShot = rand()%10 + 8; // generate random number for myShot
                    if (myShot <= marius.hitChance) // if that number is smaller or equal to marius.HitChance, it is a hit
                    {
                        cout << "HIT!!!" << endl;
                        break;
                    }
                    else
                    {
                        cout << "MISS." << endl;
                    }
                    cin.get();
                    cout << "Enemy health: " << healthEnemy2;
                    cout << "Enemy shoots: ";
                    enemyShot = rand()%10 + 1;
                    if (enemyShot <= basicEnemy.hitChance)
                    {
                        cout << "HIT!" << endl;
                        marius.health -= 100;
                        if (marius.health > 0)
                        {
                            cout << "Marius: I'm wounded!" << endl;
                        }
                        else if (marius.health <= 0)
                        {
                            system("CLS");
                            cout << "YOU DIED FROM THE GUN FIGHT." << endl << endl << endl;
                            cout << "Press 1 to continue." << endl;
                            cin >> died;
                            while (died != 1)
                            {
                                cout << "Invalid input. Just please, all you have to do is type in number 1 and enter" << endl;
                                cin >> died;
                            }
                            result--;
                        } // part of else if player dies
                    } // if enemy hits
                    else
                        cout << "MISS." << endl << endl;
                } // shooting sequence
                cout << "John: Seems like we got 'em all." << endl;
                cin.get();
                cout << "Marius: Let's make our way to the objective." << endl;
                cin.get();

        } // take the stairs
        else // rope
        {
            cout << "Marius: Rope time!" << endl;
            cin.get();
            cout << "John: Now we're talking!" << endl;
            cin.get();
            cout << "Marius: You're not afraid of heights right, John?" << endl;
            cin.get();
            cout << "John: Terrified. Petrified. Mortified." << endl;
            cin.get();
            cout << "Marius: Too bad brotha." << endl;
            cin.get();
            cout << "** Shoots rope gun up to the roof." << endl;
            cin.get();
            cout << "Marius: Rope secured." << endl;
            cin.get();
            cout << "John: Secured." << endl;
            cin.get();
            cout << "John: Rappelling." << endl;
            cin.get();
            cout << "Samuel: Wait, enemy at a window." << endl;
            cin.get();
            cout << "** Shoots" << endl;
            cin.get();
            cout << "Samuel: Proceed and finish the deed." << endl;
            cin.get();
            cout << "John: Last time I was this high was April 20." << endl;
            cin.get();
            cout << "Marius: ..." << endl;
            cin.get();
            cout << "John: Oh come on... No laugh?" << endl;
            cin.get();
            cout << "Samuel: Marius just realized that his brother is alive and he organized a terrorist plot." << endl;
            cout << "       Cut him some slack, John." << endl;
            cin.get();
            cout << "John: Right... Sorry." << endl;
            cin.get();
        } // rope
        cin.get();
        cout << "Marius: We're in" << endl;
        cin.get();
        cout << "??????: Hands in the air where I can see them. Drop your weapons and turn around." << endl;
        cin.get();
        cout << "John: **Whispering Sam, we got caught. Move to window 4." << endl;
        cin.get();
        cout << "Samuel: Got cha." << endl;
        cin.get();
        cout << "** Marius and John slow turn around." << endl;
        cin.get();
        cout << "Marius: Dominic." << endl;
        cin.get();
        cout << "Dominic: What the..." << endl;
        cin.get();
        cout << "Marius: WHY ARE YOU DOING THIS!?" << endl;
        cin.get();
        cout << "Dominic: Why are you in the team? They made you join??" << endl;
        cin.get();
        cout << "Marius: No! I joined because of you! They told me you work for the GSG 9." << endl;
        cin.get();
        cout << "Dominic: ALL THE PAIN I'VE BEEN THROUGH, I'VE BEEN BETRAYED!" << endl;
        if (input1 == 1) // agree with Dominic
        {
            cout << "Marius: I agree." << endl;
            cin.get();
            cout << "John: What?" << endl;
            cin.get();
            cout << "Marius SHOOTS JOHN." << endl;
            cin.get();
            cout << "Dominic: What is this?" << endl;
            cin.get();
            cout << "Marius: I trust you, Dominic. And I'm sorry." << endl;
            cin.get();
            cout << "Marius: I'm coming with you." << endl;
            cin.get();
            cout << "Dominic: Okay, let's go." << endl;
            system("PAUSE");
            system("CLS");
            cout << "You've finished the game." << endl;
            cout << "Your brother is alive but you are now a fugitive." << endl;
            return 0;
        }
        else if (input1 == 2) // does not agree with Dominic
        {
            cout << "Marius: THAT DOES NOT JUSTIFY HURTING MORE INNOCENT PEOPLE!" << endl;
            cin.get();
            cout << "Dominic: Put the gun down." << endl;
            cin.get();
            cout << "Marius: Your wife, your kids. They're worried sick!" << endl;
            cin.get();
            cout << "Marius: Missing in action. MISSING IN ACTION." << endl;
            cin.get();
            cout << "Marius: It's worse than knowing you're dead, because you're guessing!" << endl;
            cin.get();
            cout << "Dominic: I was BETRAYED! It's not my fault I was forced to work for" << endl;
            cout << "        terrorists against my will." << endl;
            cin.get();
            cout << "** Marius and Dominic argue." << endl;
            cin.get();
            cout << "John whispering: Samuel, we need you." << endl;
            cin.get();
            cout << "Samuel: Target acquired. Fire when ready." << endl;
            cin.get();
            cout << "Press 1 for Samuel to shoot Dominic." << endl;
            cin >> input3;
            while (input3 != 1)
            {
                cout << "Invalid. Enter 1." << endl;
                cin >> input3;
            }
            cout << "Marius: NOOOOOOO!!" << endl;
            cin.get();
            cout << "Dominic shoots Marius." << endl;
            cin.get();
            cout << "Samuel shoots Dominic through the window. Dominic dies." << endl;
            cin.get();
            cout << "**John runs towards you and pushes you." << endl;
            cin.get();
            cout << "**THUMP**" << endl;
            cin.get();
            cout << "Marius: Wha- What?" << endl;
            cin.get();
            cout << "Marius: JOHN!! DOMINIC!" << endl;
            cin.get();
            cout << "John: It- It's okay." << endl;
            cin.get();
            cout << "John: I mask my pain- cough cough* with jokes." << endl;
            cin.get();
            cout << "John: it- It makes me feel better. But the truth is" << endl;
            cin.get();
            cout << "John: Bu- But... Cough*" << endl;
            cin.get();
            cout << "Marius: SAM HE'S BLEEDING, CALL FOR HELP! SAM, SAM PLEASE!" << endl;
            cin.get();
            cout << "Samuel: It would take hours for them to get here!" << endl;
            cin.get();
            cout << "Marius: CALL. THE MEDI-" << endl;
            cin.get();
            cout << "John: STOP! Marius, stop." << endl;
            cin.get();
            cout << "John: It's okay, it's good." << endl;
            cin.get();
            cout << "Marius: NOOOOOOOOO!!!" << endl;
            system("PAUSE");
            system("CLS");
            cout << "BBC World" << endl;
            cout << "BREAKING NEWS: Remembering Lieutenant John Marx." << endl;
            cin.get();
            cout << " - During yesterday's bank robbery in Hanover, Germany. John Marx, a Canadian-German" << endl;
            cout << "   Lieutenant died from a gunshot wound after intense confrontation with the leader of" << endl;
            cout << "   the organized bank robbery and terrorist plot." << endl;
            cin.get();
            cout << " - Lieutenant John Marx died heroically, saving Captain Marius Streicher from a gunshot" << endl;
            cout << " - Today, we remember our fallen hero and thank Captain Marius, now Commander Marius Streicher," << endl;
            cout << "   and army veteran, Lieutenant Samuel Krieg." << endl;
            cin.get();
            cout << "Commander Wolfe: Today, we remember Lieutenant John Marx from his heroic efforts." << endl;
            cout << "               During hard times, he always remained positive and vigilant. His support" << endl;
            cout << "               and bravery will never be forgotten. He is not just a great soldier, he is" << endl;
            cout << "               a great friend." << endl;
            cin.get();
            cout << "Samuel: John was a great friend. We've been going on operations with each other since way" << endl;
            cout << "        back. We were supposed to go on vacation after this and I would get him bear." << endl;
            cin.get();
            cout << "**Sobbing. But, but he's gone now." << endl;
            cin.get();
            cout << "Marius: This is my second operation with him. I didn't know him as well on the first operation" << endl;
            cout << "        but after this one. I will never forget him, and I will forever owe him my gratitude." << endl;
            cin.get();
            cout << "Marius: Thank you, John." << endl;
            system("PAUSE");
            system("CLS");
            cout << "You've finished Chapter 3. Here's what you've learned/results:" << endl << endl;
            cin.get();
            cout << " - You did not agree with your brother's actions." << endl;
            cin.get();
            cout << " - Sacrificed your brother for your values and beliefs, as well as the mission's objective." << endl;
            cin.get();
            cout << " - John died to save you." << endl;
            cin.get();
            cout << " - You lost your brother but you are called a hero." << endl;
            system("PAUSE");
            system("CLS");
            cout << "You've finished the game. Greatest thanks for playing Path of the Lost Engineer." << endl;
            cout << "Sincerely," << endl;
            cout << "Kien Do." << endl << endl;
        }
        // target in sight window shoot me
    }
    while (result == 0);

    return result;
}
// -------------------------------  skills menu  -------------------------------------------

int unlockSkill(MyCharacter& _myCharacter, int& points, int recentResult)
{
    int choice = 0;
    int repeat = 0;
    if (recentResult == 3) // increase Endurance by 1
    {
        cout << "**Based on your choices from Chapter One, your Endurance is increased by ONE POINT." << endl << endl;
    }
    if (recentResult == 4) // does not allow user to upgrade aim after Chapter One
    {
        cout << "**Based on your choices from Chapter One, your dominant arm is still recovering from injury." << endl;
        cout << "You may not upgrade your Weapon Skills until Chapter Two." << endl << endl;
    }
    do // skill menu and choice
    {
        cout << "SKILL GUIDE:" << endl;
        cout << "Environment Skills provide opportunities for alternate choices/routes AND bonus dialog." << endl;
        cout << "Weapon/Combat skills improve increase hit chance and close quarters damage." << endl;
        cout << "Endurance skills provide more health and alternate routes." << endl;
        cout << "   Maxing out your Endurance skills will let you take three bullet hits before dying." << endl;
        cout << "   **All bullets in the game deal 100 damage." << endl << endl;

        cout << "**A skill point is gained after completing a chapter. Each skill costs 1 point to unlock." << endl << endl;
        cout << "Available Skill Points: " << points << endl << endl;

        cout << "Environmental Skills                        Combat Skills" << endl;
        cout << "1. Lock Picking(" << _myCharacter.mySkills.lockPicking << "/1)                        2. Hand to Hand Combat(" << _myCharacter.mySkills.fighting << "/2)" << endl;
        cout << "3. Climbing(" << _myCharacter.mySkills.climbing <<"/1)                            4. Weapon Skills(" << _myCharacter.mySkills.aim << "/2)" << endl;
        cout << "Mixed Skills " << endl;
        cout << "5. Endurance(" << _myCharacter.mySkills.endurance << "/4)" << endl;
        cout << "6. Exit" << endl << endl;

        do // error trapping
        {
            cout << "Select a skill for Marius to master." << endl;
            cin >> choice;
            //----------------------- story error trapping -------------------------------------
            if (choice == 4 && recentResult == 4)
            {
                cout << "Invalid. Marius' arm is still recovering. Please select another skill to master." << endl;
                continue;
            }
            // ------------------- basic error trapping ---------------------------------
            if (choice < 0 || choice > 6) // error trap choice
            {
                cout << "Invalid. Please select a skill from 1 to 5." << endl;
            }
            else if (points <= 0 && choice != 6) // error trap if there are no points and user wants to unlock a skill
            {
                cout << "You do not have enough points to gain a skill." << endl;
            }
            else if (choice == 1 && _myCharacter.mySkills.lockPicking == 1) // lock pick up to 1
            {
                cout << "You've already mastered this skill. Please select another skill to master." << endl;
            }
            else if (choice == 2 && _myCharacter.mySkills.fighting == 2) // fighting up to 2
            {
                cout << "You've already mastered this skill. Please select another skill to master." << endl;
            }
            else if (choice == 3 && _myCharacter.mySkills.climbing == 1) // climbing up to 1
            {
                cout << "You've already mastered this skill. Please select another skill to master." << endl;
            }
            else if (choice == 4 && _myCharacter.mySkills.aim == 2) // aim up to 2
            {
                cout << "You've already mastered this skill. Please select another skill to master." << endl;
            }
            else if (choice == 5 && _myCharacter.mySkills.endurance == 4) // endurance up to 4
            {
                cout << "You've already mastered this skill. Please select another skill to master." << endl;
            }
            else
                break; // I'm sorry Mr. Maloley, I had to use it because I didn't know how else to break out of this loop.
        }
        while(true);
        if (choice != 6) // shows the unlocked skill if choice wasn't to EXIT
        {
            cout << "Congratulations! You've unlocked ";
        }
        switch (choice)
        {
        case 1: // lock picking
            cout << "Lock Picking! ALTERNATE and BONUS DIALOGUE may be available during the following Chapters." << endl;
            _myCharacter.mySkills.lockPicking++;
            break;
        case 2: // hand to hand combat
            cout << "Hand to Hand Combat! Your grappling and striking skills have been improved!" << endl;
            _myCharacter.mySkills.fighting++;
            _myCharacter.damage += 15;
            break;
        case 3: // climbing
            cout << "Climbing! This will allow you to choose bonus options!" << endl;
            _myCharacter.mySkills.climbing++;
            break;
        case 4: // aim. weapon skills
            _myCharacter.mySkills.aim++;
            if (_myCharacter.mySkills.aim == 1)
            {
                cout << "the first Weapon Skill! Your shots now have a 60% hit chance on your opponent." << endl;
                _myCharacter.hitChance = 6;
            }
            else if (_myCharacter.mySkills.aim == 2)
            {
                cout << "Weapon Skills! Your shots now have a 100% hit chance!" << endl;
                _myCharacter.hitChance = 10;
            }
            break;
        case 5: // endurance. health++
            cout << "Endurance! This increases health and provide alternate routes. Your health is now " << endl;
            _myCharacter.mySkills.endurance++;
            if (_myCharacter.mySkills.endurance == 1)
            {
                _myCharacter.health = 125;
            }
            else if (_myCharacter.mySkills.endurance == 2)
            {
                _myCharacter.health = 150;
            }
            else if (_myCharacter.mySkills.endurance == 3)
            {
                _myCharacter.health = 175;
            }
            else if (_myCharacter.mySkills.endurance == 4)
            {
                _myCharacter.health = 210;
            }
            cout << _myCharacter.health << "!" << endl;
            if (_myCharacter.health == 210)
            {
                cout << "You have maxed out your health level! You can now take three bullets before dying!" << endl;
            }
            break;
        case 6: // exit
            cout << "Exiting..." << endl;
            repeat = 2;
            system("PAUSE");
            system("CLS");
            break;
        }
        if (choice != 6) // only ask to unlock another skill unless user selected EXIT...
        {
            points--;
            cout << endl;
            cout << "You have " << points << " skill points left." << endl;
            if (points > 0)
            {
                cout << "It is recommended that you use all your skill points before proceeding." << endl;
            }
            cout << "Would you like to unlock another skill? Select 1 for yes, 2 for no." << endl;
            cin >> repeat;
            while (repeat != 1 && repeat != 2)
            {
                cout << "Invalid input. Please enter 1 or 2." << endl;
                cin >> repeat;
            }
            system("CLS");
        }
    }
    while (repeat == 1);  // loop in case player dies
    return choice;
}

// -------------------------------- display skills ------------------------------------------

void displayMarius(MyCharacter _myCharacter) // display Marius
{
    cout << "Marius Statistics: " << endl << endl;
    cout << "Environmental Skills                        Combat Skills" << endl;
    cout << "Hand to hand combat damage: " << _myCharacter.damage << endl;
    cout << "Health: " << _myCharacter.health << endl;
    cout << "Hit Chance: " << _myCharacter.hitChance << " out of 10." << endl << endl;

    cout << "Skills unlocked:" << endl << endl;
    cout << "Lock Picking(" << _myCharacter.mySkills.lockPicking << "/1)                        Hand to Hand Combat(" << _myCharacter.mySkills.fighting << "/2)" << endl;
    cout << "Climbing(" << _myCharacter.mySkills.climbing <<"/1)                            Weapon Skills(" << _myCharacter.mySkills.aim << "/2)" << endl;
    cout << "Mixed Skills " << endl;
    cout << "Endurance(" << _myCharacter.mySkills.endurance << "/4)" << endl;
    system("PAUSE");
    cout << endl;
    return;
}

void displayCharacter(Characters _character) // display any character other than Marius
{
    cout << "Damage: " << _character.damage << endl;
    cout << "Health: " << _character.health << endl;
    cout << "Hit Chance: " << _character.hitChance << " out of 10." << endl;
    cout << "Awareness: " << _character.awareness << " out of 10." << endl;
    system("PAUSE");
    cout << endl;
    return;
}

// ------------------------------------- int main ---------------------------------------------

int main()
{
    //------------------------       declaring variables       ----------------------------

    int a = 1; // for the main menu
    int menuOption, resultOne, resultTwo; // chapter results
    int resultPoint = 0; // ending 1: saves brother but becomes vigilante. ending 2: doesn't save brother, gets called hero
    int points = 0;
    srand(time(NULL));
    // ------------------------------------- initialize Skills skill ---------------------------------
    Skills skill;
    int infoSkill[5] = {0, 0, 0, 0, 0}; // 5 skills to initialize skills
    skill = initialize (skill, infoSkill[0], infoSkill[1], infoSkill[2], infoSkill[3], infoSkill[4]); // initialize
    // ------------------------------------- initialize MyCharacter marius ---------------------------------
    MyCharacter marius;
    float infoMarius[3] = {15, 100, 3}; // damage, health, hitChance, unlocked skills.
    marius = initialize (marius, infoMarius[0], infoMarius[1], infoMarius[2], skill);
    // ------------------------------------- initialize skills ---------------------------------
    Characters basicEnemy;
    float infoEnemy[4] = {10, 80, 1, 4}; // damage, health, hitChance, awareness.
    basicEnemy = initialize (basicEnemy, infoEnemy[0], infoEnemy[1], infoEnemy[2], infoEnemy[3]);

    Characters john;
    float infoJohn[4] = {30, 120, 7, 9}; // damage, health, hitChance, awareness.
    john = initialize (john, infoJohn[0], infoJohn[1], infoJohn[2], infoJohn[3]);

    Characters samuel;
    float infoSamuel[4] = {10, 100, 10, 10}; // damage, health, hitChance, awareness.
    samuel = initialize (samuel, infoSamuel[0], infoSamuel[1], infoSamuel[2], infoSamuel[3]);

    Characters dominic;
    float infoDominic[4] = {15, 300, 5, 6};
    dominic = initialize (dominic, infoDominic[0], infoDominic[1], infoDominic[2], infoDominic[3]);

    //------------------------          display menu           -----------------------------

    menuOption = mainMenu(a); // main menu
    if (menuOption == 4) // end program if menu option was to quit(option 4)
        return 0;

    //-------------------------        Chapter One              ------------------------------

    resultOne = chapterOne(resultOne);

    cout << "You've finished the Introduction to Marius Streicher's life. Here's how your choice has impacted the story." << endl << endl;
    if (resultOne == 1)      // knowledge gained: wife + 2 sons
    {
        cout << "Result: Knowledge gained." << endl << endl;
        cout << "You now know that Dominic, Marius' brother, has a wife and two sons." << endl;
    }
    else if (resultOne == 2) // finds out brother works for GSG 9
    {
        cout << "Result: Knowledge gained." << endl << endl;
        cout << "You've found out that your brother works as a GSG 9 undercover agent in Russia" << endl;
        cout << "       to help prevent terrorists and provide intel to the German anti-terrorism unit." << endl;
        cout << "He was never a boring Accountant." << endl << endl;
    }
    else if (resultOne == 3) // endurance +1, health = 125
    {
        cout << "Result: Character mindset changed." << endl << endl;
        cout << "Marius was a coward. After the incident, he is now braver than ever." << endl;
        cout << "   *Health increased from 100 to 125." << endl << endl;
        marius.mySkills.endurance++;
        marius.health = 125; // health increase
    }
    else                     // can not upgrade aim in the next round
    {
        cout << "Result: Information gained" << endl;
        cout << "        Character performance affected." << endl;
        cout << "Info: Marius acts without thinking through. This may serve to be a good thing or a bad thing." << endl;
        cout << "Performance affected: Marius' dominant hand is weakened." << endl << endl;
    }
    cout << "This information may be valuable to you in the following chapters." << endl << endl;
    cin.get();
    system("CLS");

    //------------------------------  end of Chapter One   ---------------------------------

    //-------------------------- display Marius properties and skill points ---------------------------------------

    cout << "Before we proceed, here are Marius' current statistics." << endl;
    displayMarius(marius);
    cout << "These are rookie statistics." << endl;
    cout << "Let's give Marius a skill before proceeding. Skills affect available choices and Marius' performance." << endl << endl;
    cout << "TWO skill point have been added to your inventory." << endl;
    points += 2; // gives player point(s) to upgrade their skills
    cin.get();
    system("CLS");

    //------------------------   call skill menu function    --------------------------

    unlockSkill(marius, points, resultOne); // send structure, # of points and recent chapter results
    cin.get();
    cout << "Now let's see Marius' NEW qualities." << endl << endl; // display unlocked/locked skills
    displayMarius(marius);
    cout << "You can access the Skill Menu after each chapter." << endl << endl;
    cin.get();
    system("CLS");

    //--------------------------------    start chapter Two   -----------------------------

    resultTwo = chapterTwo(marius, john, samuel, basicEnemy, resultOne);
    system("PAUSE");
    system("CLS");
    cout << "Congratulations! You've completed Chapter Two!" << endl;
    cout << "Here's how your choices have affected what you learned." << endl << endl;
    if (resultTwo == 1)
    {
        cout << "You decided to ignore the noise instead of investigate it." << endl;
        cout << "You chose the back entrance instead of the sewers." << endl;
        cout << "You interrogated the enemy after the gun fight and found out that your brother is:" << endl;
        cout << "     - Still alive" << endl;
        cout << "     - Wants revenge on the GSG 9 for abandoning him." << endl;
        cin.get();
    }
    else if (resultTwo == 2)
    {
        cout << "You decided to investigate the noise which lead you to find a guarded cargo container." << endl;
        cout << "Inside the container, there was:" << endl;
        cout << "     - An innocent women who would have been set up to be a terrorist if you hadn't saved her." << endl;
        cout << "     - An armed woman building explosives and bomb vests. She shot John." << endl;
        cout << "You found out that your brother is still alive and plotted this entire robbery." << endl;
        cout << "You realize that the bank robbery is just a decoy to attract operators so that your brother" << endl;
        cout << "     could kill them all." << endl;
        cin.get();
    }
    cout << "Three skill points have been awarded to your inventory for completing the Chapter!" << endl;
    cout << "You them wisely as Chapter Three will be the last Chapter." << endl;
    system("PAUSE");
    system("CLS");

    resultTwo += 4; // can't have the same value as result from chapter One
    points += 3;
    unlockSkill(marius, points, resultTwo); // unlock skills
    displayMarius(marius); // display stats
    system("CLS");

    //--------------------------------    start Chapter Three   -----------------------------

    chapterThree (marius, john, samuel, basicEnemy, dominic, resultTwo);

    //--------------------------------    end Chapter Three   -------------------------------
    //--------------------------------      credits     -------------------------------
    cout << "Special thanks to:" << endl;
    cout << " - Sarp Kilinc(ALPHA Tested, suggested story ideas)." << endl;
    cout << " - Simon C., Luc L.(suggested story ideas)." << endl;
    cout << " - Isaac Kuru (ALPHA Tested)." << endl;

    return 0;
}
