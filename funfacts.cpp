#include "funfacts.h"

FunFacts::FunFacts()
{
    _iterator = 0;
}

string FunFacts::getFunFact()
{   // From 'www.kickassfacts.com/30-kickass-interesting-facts-about-computers/'

    _iterator++;
    _iterator = _iterator % 10;

    switch(_iterator)
    {
        case 0: return "Only 8% of the world’s currency is physical money \n"
                       "the rest only exists on computers.";
                break;
        case 1: return "There was a computer worm that would gain access to \n"
                       "Windows XP systems, download a patch from Microsoft to \n"
                       "close the vulnerability that it used to infect the system, \n"
                       "attempt to delete the infamous Blaster worm (if present) \n"
                       "from the system, then delete itself.";
                break;
        case 2: return "The worst breach of U.S. military computers in history \n"
                       "happened when someone picked up a memory stick (infected \n"
                       "by a foreign intelligence agency) they found in the parking \n"
                       "lot and plugged it into their computer, which was attached \n"
                       "to United States Central Command.";
                break;
        case 3: return "The Motion Picture Academy refused to nominate Tron (1982) \n"
                       "for a special-effects award because, according to director \n"
                       "Steven Lisberger, “The Academy thought we cheated by using \n"
                       "computers”";
                break;
        case 4: return "Mary Kenneth Keller, the first woman to earn a Ph.D. in \n"
                       "Computer Science in the United States also earned a Master’s \n"
                       "degree in Mathematics and Physics, helped develop computer \n"
                       "programming languages and she was a Catholic nun.";
                break;
        case 5: return "Illegal prime numbers exist. An illegal prime is a prime \n"
                       "number that represents information which is forbidden to possess \n"
                       "or distribute. For example, when interpreted in a particular way, \n"
                       "a certain prime describes a computer program that bypasses the \n"
                       "digital rights management scheme used on DVDs";
                break;
        case 6: return "In 1936, the Russians made a computer that ran on water.";
                break;
        case 7: return "Tandy TRS-80 Model I computer radiated so much interference \n"
                       "that many games were designed so that an AM radio next to the \n"
                       "computer could be used to provide sounds.";
                break;
        case 8: return "In September 1956 IBM launched the 305 RAMAC, the first ‘SUPER’ \n"
                       "computer with a hard disk drive (HDD). The HDD weighed over a ton \n"
                       "and stored 5 MB of data.";
                break;
        case 9: return "A computer as powerful as the human brain would be able to perform \n"
                       "about 38 thousand trillion operations per second and hold about \n"
                       "3,584 terabytes of memory.";
                break;
    }

                return "MIT has developed a computer software that can identify and \n"
                       "distinguish a real smile from a smile of frustration.";
}
