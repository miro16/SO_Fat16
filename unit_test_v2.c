/*
 * Unit Test Bootstrap
 * Autor: Tomasz Jaworski, 2018-2020
 *
 * Test dla zadania Projekt: czytnik dysku, woluminu, katalogu głównego i plików (3,0)
 * Autor testowanej odpowiedzi: Maciek Mirowski
 * Test wygenerowano automatycznie o 2024-01-18 22:15:03.337775
 *
 * Debug: 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <signal.h>
#include <setjmp.h>
#include <assert.h>

#if !defined(__clang__) && !defined(__GNUC__)
// Zakomentuj poniższy błąd, jeżeli chcesz przetestować testy na swoim kompilatorze C.
#error System testow jednostkowych jest przeznaczony dla kompilatorów GCC/Clang.
#endif

#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
// Zakomentuj poniższy błąd, jeżeli chcesz przetestować testy na platformie Windows.
#error System testow jednostkowych NIE jest przeznaczony dla testów uruchamianych na platformach Windows.
#endif

#define _RLDEBUG_API_
#include "unit_helper_v2.h"
#include "rdebug.h"

#include "tested_declarations.h"
#include "rdebug.h"

//
// Elementy globalne dla całego testu
//




//
//  Test 1: Sprawdzanie poprawności działania funkcji disk_open_from_file
//
void UTEST1(void)
{
    // informacje o teście
    test_start(1, "Sprawdzanie poprawności działania funkcji disk_open_from_file", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            struct disk_t* disk = disk_open_from_file("BOTTOM");
            test_error(disk == NULL, "Funkcja disk_open_from_file() powinna zwrócić NULL przy próbie otwarcia nieistniejącego pliku");

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 2: Sprawdzanie poprawności działania funkcji disk_open_from_file
//
void UTEST2(void)
{
    // informacje o teście
    test_start(2, "Sprawdzanie poprawności działania funkcji disk_open_from_file", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            struct disk_t* disk = disk_open_from_file(NULL);
            test_error(disk == NULL, "Funkcja disk_open_from_file() powinna zwrócić NULL przy próbie otwarcia nieistniejącego pliku");

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 3: Sprawdzanie poprawności działania funkcji disk_close
//
void UTEST3(void)
{
    // informacje o teście
    test_start(3, "Sprawdzanie poprawności działania funkcji disk_close", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            disk_close(NULL);
      
            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 4: Sprawdzanie poprawności działania funkcji fat_open
//
void UTEST4(void)
{
    // informacje o teście
    test_start(4, "Sprawdzanie poprawności działania funkcji fat_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    


            struct disk_t* disk = disk_open_from_file("baby.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume == NULL, "Funkcja fat_open() powinna zwrócić NULL w przypadku przekazania błędnego obrazu dysku");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 5: Sprawdzanie poprawności działania funkcji disk_open_from_file
//
void UTEST5(void)
{
    // informacje o teście
    test_start(5, "Sprawdzanie poprawności działania funkcji disk_open_from_file", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct volume_t* volume = fat_open(NULL, 0);
            test_error(volume == NULL, "Funkcja fat_open() powinna zwrócić NULL w przypadku przekazania błędnego obrazu dysku");

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 6: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST6(void)
{
    // informacje o teście
    test_start(6, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(10240, 1);
                char expected_filecontent[10241] = "";
        
                strcat(expected_filecontent, "ator, and remains\nEver between the sun and winter) for the cause\nThou hast assign\'d, from hence toward the north\nDeparts, when those who in the Hebrew land\nInhabit, see it tow\'rds the warmer part.\nBut if it please thee, I would gladly know,\nHow far we have to journey: for the hill\nMounts higher, than this sight of mine can mount.\"\n     He thus to me:  \"Such is this steep ascent,\nThat it is ever difficult at first,\nBut, more a man proceeds, less evil grows.\nWhen pleasant it shall seem to thee, so much\nThat upward going shall be easy to thee.\nAs in a vessel to go down the tide,\nThen of this path thou wilt have reach\'d the end.\nThere hope to rest thee from thy toil.  No more\nI answer, and thus far for certain know.\"\nAs he his words had spoken, near to us\nA voice there sounded:  \"Yet ye first perchance\nMay to repose you by constraint be led.\"\nAt sound thereof each turn\'d, and on the left\nA huge stone we beheld, of which nor I\nNor he before was ware.  Thither we drew,\nfind there were some, who in the shady place\nBehind the rock were standing, as a man\nThru\' idleness might stand.  Among them one,\nWho seem\'d to me much wearied, sat him down,\nAnd with his arms did fold his knees about,\nHolding his face between them downward bent.\n     \"Sweet Sir!\"  I cry\'d, \"behold that man, who shows\nHimself more idle, than if laziness\nWere sister to him.\"  Straight he turn\'d to us,\nAnd, o\'er the thigh lifting his face, observ\'d,\nThen in these accents spake:  \"Up then, proceed\nThou valiant one.\"  Straight who it was I knew;\nNor could the pain I felt (for want of breath\nStill somewhat urg\'d me) hinder my approach.\nAnd when I came to him, he scarce his head\nUplifted, saying \"Well hast thou discern\'d,\nHow from the left the sun his chariot leads.\"\n     His lazy acts and broken words my lips\nTo laughter somewhat mov\'d; when I began:\n\"Belacqua, now for thee I grieve no more.\nBut tell, why thou art seated upright there?\nWaitest thou escort to conduct thee hence?\nOr blame I only shine accustom\'d ways?\"\nThen he:  \"My brother, of what use to mount,\nWhen to my suffering would not let me pass\nThe bird of God, who at the portal sits?\nBehooves so long that heav\'n first bear me round\nWithout its limits, as in life it bore,\nBecause I to the end repentant Sighs\nDelay\'d, if prayer do not aid me first,\nThat riseth up from heart which lives in grace.\nWhat other kind avails, not heard in heaven?\"\'\n     Before me now the Poet up the mount\nAscending, cried:  \"Haste thee, for see the sun\nHas touch\'d the point meridian, and the night\nNow covers with her foot Marocco\'s shore.\"\n\n\n\nCANTO V\n\nNow had I left those spirits, and pursued\nThe steps of my Conductor, when beheld\nPointing the finger at me one exclaim\'d:\n\"See how it seems as if the light not shone\nFrom the left hand of him beneath, and he,\nAs living, seems to be led on.\"  Mine eyes\nI at that sound reverting, saw them gaze\nThrough wonder first at me, and then at me\nAnd the light broken underneath, by turns.\n\"Why are thy thoughts thus riveted?\"  my guide\nExclaim\'d, \"that thou hast slack\'d thy pace?  or how\nImports it thee, what thing is whisper\'d here?\nCome after me, and to their babblings leave\nThe crowd. Be as a tower, that, firmly set,\nShakes not its top for any blast that blows!\nHe, in whose bosom thought on thought shoots out,\nStill of his aim is wide, in that the one\nSicklies and wastes to nought the other\'s strength.\"\n     What other could I answer save \"I come?\"\nI said it, somewhat with that colour ting\'d\nWhich ofttimes pardon meriteth for man.\n     Meanwhile traverse along the hill there came,\nA little way before us, some who sang\nThe \"Miserere\" in responsive Strains.\nWhen they perceiv\'d that through my body I\nGave way not for the rays to pass, their song\nStraight to a long and hoarse exclaim they chang\'d;\nAnd two of them, in guise of messengers,\nRan on to meet us, and inquiring ask\'d:\nOf your condition we would gladly learn.\"\n     To them my guide.  \"Ye may return, and bear\nTidings to them who sent you, that his frame\nIs real flesh.  If, as I deem, to view\nHis shade they paus\'d, enough is answer\'d them.\nHim");
    strcat(expected_filecontent, " let them honour, they may prize him well.\"\n     Ne\'er saw I fiery vapours with such speed\nCut through the serene air at fall of night,\nNor August\'s clouds athwart the setting sun,\nThat upward these did not in shorter space\nReturn; and, there arriving, with the rest\nWheel back on us, as with loose rein a troop.\n     \"Many,\" exclaim\'d the bard, \"are these, who throng\nAround us: to petition thee they come.\nGo therefore on, and listen as thou go\'st.\"\n     \"O spirit!  who go\'st on to blessedness\nWith the same limbs, that clad thee at thy birth.\"\nShouting they came, \"a little rest thy step.\nLook if thou any one amongst our tribe\nHast e\'er beheld, that tidings of him there\nThou mayst report.  Ah, wherefore go\'st thou on?\nAh wherefore tarriest thou not?  We all\nBy violence died, and to our latest hour\nWere sinners, but then warn\'d by light from heav\'n,\nSo that, repenting and forgiving, we\nDid issue out of life at peace with God,\nWho with desire to see him fills our heart.\"\n     Then I:  \"The visages of all I scan\nYet none of ye remember.  But if aught,\nThat I can do, may please you, gentle spirits!\nSpeak; and I will perform it, by that peace,\nWhich on the steps of guide so excellent\nFollowing from world to world intent I seek.\"\n     In answer he began:  \"None here distrusts\nThy kindness, though not promis\'d with an oath;\nSo as the will fail not for want of power.\nWhence I, who sole before the others speak,\nEntreat thee, if thou ever see that land,\nWhich lies between Romagna and the realm\nOf Charles, that of thy courtesy thou pray\nThose who inhabit Fano, that for me\nTheir adorations duly be put up,\nBy which I may purge off my grievous sins.\nFrom thence I came.  But the deep passages,\nWhence issued out the blood wherein I dwelt,\nUpon my bosom in Antenor\'s land\nWere made, where to be more secure I thought.\nThe author of the deed was Este\'s prince,\nWho, more than right could warrant, with his wrath\nPursued me.  Had I towards Mira fled,\nWhen overta\'en at Oriaco, still\nMight I have breath\'d. But to the marsh I sped,\nAnd in the mire and rushes tangled there\nFell, and beheld my life-blood float the plain.\"\n     Then said another:  \"Ah! so may the wish,\nThat takes thee o\'er the mountain, be fulfill\'d,\nAs thou shalt graciously give aid to mine.\nOf Montefeltro I; Buonconte I:\nGiovanna nor none else have care for me,\nSorrowing with these I therefore go.\"  I thus:\n\"From Campaldino\'s field what force or chance\nDrew thee, that ne\'er thy sepulture was known?\"\n     \"Oh!\"  answer\'d he, \"at Casentino\'s foot\nA stream there courseth, nam\'d Archiano, sprung\nIn Apennine above the Hermit\'s seat.\nE\'en where its name is cancel\'d, there came I,\nPierc\'d in the heart, fleeing away on foot,\nAnd bloodying the plain.  Here sight and speech\nFail\'d me, and finishing with Mary\'s name\nI fell, and tenantless my flesh remain\'d.\nI will report the truth; which thou again0\nTell to the living.  Me God\'s angel took,\nWhilst he of hell exclaim\'d:  \"O thou from heav\'n!\nSay wherefore hast thou robb\'d me?  Thou of him\nTh\' eternal portion bear\'st with thee away\nFor one poor tear that he deprives me of.\nBut of the other, other rule I make.\"\n     \"Thou knowest how in the atmosphere collects\nThat vapour dank, returning into water,\nSoon as it mounts where cold condenses it.\nThat evil will, which in his intellect\nStill follows evil, came, and rais\'d the wind\nAnd smoky mist, by virtue of the power\nGiven by his nature.  Thence the valley, soon\nAs day was spent, he cover\'d o\'er with cloud\nFrom Pratomagno to the mountain range,\nAnd stretch\'d the sky above, so that the air\nImpregnate chang\'d to water.  Fell the rain,\nAnd to the fosses came all that the land\nContain\'d not; and, as mightiest streams are wont,\nTo the great river with such headlong sweep\nRush\'d, that nought stay\'d its course.  My stiffen\'d frame\nLaid at his mouth the fell Archiano found,\nAnd dash\'d it into Arno, from my breast\nLoos\'ning the cross, that of myself I made\nWhen overcome with pain.  He hurl\'d me on,\nAlong the banks and bottom of his course;\nThen in his muddy spoils encircling wrapt.\"\n     \"Ah!  when thou to th");
    strcat(expected_filecontent, "e world shalt be return\'d,\nAnd rested after thy long road,\" so spake\nNext the third spirit; \"then remember me.\nI once was Pia.  Sienna gave me life,\nMaremma took it from me.  That he knows,\nWho me with jewell\'d ring had first espous\'d.\"\n\n\n\nCANTO VI\n\nWhen from their game of dice men separate,\nHe, who hath lost, remains in sadness fix\'d,\nRevolving in his mind, what luckless throws\nHe cast: but meanwhile all the company\nGo with the other; one before him runs,\nAnd one behind his mantle twitches, one\nFast by his side bids him remember him.\nHe stops not; and each one, to whom his hand\nIs stretch\'d, well knows he bids him stand aside;\nAnd thus he from the press defends himself.\nE\'en such was I in that close-crowding throng;\nAnd turning so my face around to all,\nAnd promising, I \'scap\'d from it with pains.\n     Here of Arezzo him I saw, who fell\nBy Ghino\'s cruel arm; and him beside,\nWho in his chase was swallow\'d by the stream.\nHere Frederic Novello, with his hand\nStretch\'d forth, entreated; and of Pisa he,\nWho put the good Marzuco to such proof\nOf constancy.  Count Orso I beheld;\nAnd from its frame a soul dismiss\'d for spite\nAnd envy, as it said, but for no crime:\nI speak of Peter de la Brosse; and here,\nWhile she yet lives, that Lady of Brabant\nLet her beware; lest for so false a deed\nShe herd with worse than these. When I was freed\nFrom all those spirits, who pray\'d for others\' prayers\nTo hasten on their state of blessedness;\nStraight I began:  \"O thou, my luminary!\nIt seems expressly in thy text denied,\nThat heaven\'s supreme decree can never bend\nTo supplication; yet with this design\nDo these entreat.  Can then their hope be vain,\nOr is thy saying not to me reveal\'d?\"\n     He thus to me:  \"Both what I write is plain,\nAnd these deceiv\'d not in their hope, if well\nThy mind consider, that the sacred height\nOf judgment doth not stoop, because love\'s flame\nIn a short moment all fulfils, which he\nWho sojourns here, in right should satisfy.\nBesides, when I this point concluded thus,\nBy praying no defect could be supplied;\nBec");
                
        
                struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "WISH.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 10240, file);
                test_error(size == 10240, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 10240 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 10240);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 10240);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 7: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST7(void)
{
    // informacje o teście
    test_start(7, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(9688, 1);
                char expected_filecontent[9689] = "";
        
                strcat(expected_filecontent, "e?\nHe hath in sooth good cause for endless grief,\nWho, for the love of thing that lasteth not,\nDespoils himself forever of that love.\n     As oft along the still and pure serene,\nAt nightfall, glides a sudden trail of fire,\nAttracting with involuntary heed\nThe eye to follow it, erewhile at rest,\nAnd seems some star that shifted place in heav\'n,\nOnly that, whence it kindles, none is lost,\nAnd it is soon extinct; thus from the horn,\nThat on the dexter of the cross extends,\nDown to its foot, one luminary ran\nFrom mid the cluster shone there; yet no gem\nDropp\'d from its foil; and through the beamy list\nLike flame in alabaster, glow\'d its course.\n     So forward stretch\'d him (if of credence aught\nOur greater muse may claim) the pious ghost\nOf old Anchises, in the\' Elysian bower,\nWhen he perceiv\'d his son.  \"O thou, my blood!\nO most exceeding grace divine!  to whom,\nAs now to thee, hath twice the heav\'nly gate\nBeen e\'er unclos\'d?\" so spake the light; whence I\nTurn\'d me toward him; then unto my dame\nMy sight directed, and on either side\nAmazement waited me; for in her eyes\nWas lighted such a smile, I thought that mine\nHad div\'d unto the bottom of my grace\nAnd of my bliss in Paradise.  Forthwith\nTo hearing and to sight grateful alike,\nThe spirit to his proem added things\nI understood not, so profound he spake;\nYet not of choice but through necessity\nMysterious; for his high conception scar\'d\nBeyond the mark of mortals.  When the flight\nOf holy transport had so spent its rage,\nThat nearer to the level of our thought\nThe speech descended, the first sounds I heard\nWere, \"Best he thou, Triunal Deity!\nThat hast such favour in my seed vouchsaf\'d!\"\nThen follow\'d:  \"No unpleasant thirst, tho\' long,\nWhich took me reading in the sacred book,\nWhose leaves or white or dusky never change,\nThou hast allay\'d, my son, within this light,\nFrom whence my voice thou hear\'st; more thanks to her.\nWho for such lofty mounting has with plumes\nBegirt thee.  Thou dost deem thy thoughts to me\nFrom him transmitted, who is first of all,\nE\'en as all numbers ray from unity;\nAnd therefore dost not ask me who I am,\nOr why to thee more joyous I appear,\nThan any other in this gladsome throng.\nThe truth is as thou deem\'st; for in this hue\nBoth less and greater in that mirror look,\nIn which thy thoughts, or ere thou think\'st, are shown.\nBut, that the love, which keeps me wakeful ever,\nUrging with sacred thirst of sweet desire,\nMay be contended fully, let thy voice,\nFearless, and frank and jocund, utter forth\nThy will distinctly, utter forth the wish,\nWhereto my ready answer stands decreed.\"\n     I turn\'d me to Beatrice; and she heard\nEre I had spoken, smiling, an assent,\nThat to my will gave wings; and I began\n\"To each among your tribe, what time ye kenn\'d\nThe nature, in whom naught unequal dwells,\nWisdom and love were in one measure dealt;\nFor that they are so equal in the sun,\nFrom whence ye drew your radiance and your heat,\nAs makes all likeness scant.  But will and means,\nIn mortals, for the cause ye well discern,\nWith unlike wings are fledge.  A mortal I\nExperience inequality like this,\nAnd therefore give no thanks, but in the heart,\nFor thy paternal greeting.  This howe\'er\nI pray thee, living topaz!  that ingemm\'st\nThis precious jewel, let me hear thy name.\"\n     \"I am thy root, O leaf!  whom to expect\nEven, hath pleas\'d me:  \"thus the prompt reply\nPrefacing, next it added;  \"he, of whom\nThy kindred appellation comes, and who,\nThese hundred years and more, on its first ledge\nHath circuited the mountain, was my son\nAnd thy great grandsire.  Well befits, his long\nEndurance should he shorten\'d by thy deeds.\n     \"Florence, within her ancient limit-mark,\nWhich calls her still to matin prayers and noon,\nWas chaste and sober, and abode in peace.\nShe had no armlets and no head-tires then,\nNo purfled dames, no zone, that caught the eye\nMore than the person did.  Time was not yet,\nWhen at his daughter\'s birth the sire grew pale.\nFor fear the age and dowry should exceed\nOn each side just proportion.  House was none\nVoid of its family; nor yet had come\nHardanapalus, to");
    strcat(expected_filecontent, " exhibit feats\nOf chamber prowess.  Montemalo yet\nO\'er our suburban turret rose; as much\nTo be surpass in fall, as in its rising.\nI saw Bellincione Berti walk abroad\nIn leathern girdle and a clasp of bone;\nAnd, with no artful colouring on her cheeks,\nHis lady leave the glass.  The sons I saw\nOf Nerli and of Vecchio well content\nWith unrob\'d jerkin; and their good dames handling\nThe spindle and the flax; O happy they!\nEach sure of burial in her native land,\nAnd none left desolate a-bed for France!\nOne wak\'d to tend the cradle, hushing it\nWith sounds that lull\'d the parent\'s infancy:\nAnother, with her maidens, drawing off\nThe tresses from the distaff, lectur\'d them\nOld tales of Troy and Fesole and Rome.\nA Salterello and Cianghella we\nHad held as strange a marvel, as ye would\nA Cincinnatus or Cornelia now.\n     \"In such compos\'d and seemly fellowship,\nSuch faithful and such fair equality,\nIn so sweet household, Mary at my birth\nBestow\'d me, call\'d on with loud cries; and there\nIn your old baptistery, I was made\nChristian at once and Cacciaguida; as were\nMy brethren, Eliseo and Moronto.\n     \"From Valdipado came to me my spouse,\nAnd hence thy surname grew.  I follow\'d then\nThe Emperor Conrad; and his knighthood he\nDid gird on me; in such good part he took\nMy valiant service.  After him I went\nTo testify against that evil law,\nWhose people, by the shepherd\'s fault, possess\nYour right, usurping.  There, by that foul crew\nWas I releas\'d from the deceitful world,\nWhose base affection many a spirit soils,\nAnd from the martyrdom came to this peace.\"\n\n\n\nCANTO XVI\n\nO slight respect of man\'s nobility!\nI never shall account it marvelous,\nThat our infirm affection here below\nThou mov\'st to boasting, when I could not choose,\nE\'en in that region of unwarp\'d desire,\nIn heav\'n itself, but make my vaunt in thee!\nYet cloak thou art soon shorten\'d, for that time,\nUnless thou be eked out from day to day,\nGoes round thee with his shears.  Resuming then\nWith greeting such, as Rome, was first to bear,\nBut since hath disaccustom\'d I began;\nAnd Beatrice, that a little space\nWas sever\'d, smil\'d reminding me of her,\nWhose cough embolden\'d (as the story holds)\nTo first offence the doubting Guenever.\n     \"You are my sire,\" said I, \"you give me heart\nFreely to speak my thought: above myself\nYou raise me.  Through so many streams with joy\nMy soul is fill\'d, that gladness wells from it;\nSo that it bears the mighty tide, and bursts not\nSay then, my honour\'d stem!  what ancestors\nWhere those you sprang from, and what years were mark\'d\nIn your first childhood?  Tell me of the fold,\nThat hath Saint John for guardian, what was then\nIts state, and who in it were highest seated?\"\n     As embers, at the breathing of the wind,\nTheir flame enliven, so that light I saw\nShine at my blandishments; and, as it grew\nMore fair to look on, so with voice more sweet,\nYet not in this our modern phrase, forthwith\nIt answer\'d:  \"From the day, when it was said\n\' Hail Virgin!\' to the throes, by which my mother,\nWho now is sainted, lighten\'d her of me\nWhom she was heavy with, this fire had come,\nFive hundred fifty times and thrice, its beams\nTo reilumine underneath the foot\nOf its own lion.  They, of whom I sprang,\nAnd I, had there our birth-place, where the last\nPartition of our city first is reach\'d\nBy him, that runs her annual game.  Thus much\nSuffice of my forefathers: who they were,\nAnd whence they hither came, more honourable\nIt is to pass in silence than to tell.\nAll those, who in that time were there from Mars\nUntil the Baptist, fit to carry arms,\nWere but the fifth of them this day alive.\nBut then the citizen\'s blood, that now is mix\'d\nFrom Campi and Certaldo and Fighine,\nRan purely through the last mechanic\'s veins.\nO how much better were it, that these people\nWere neighbours to you, and that at Galluzzo\nAnd at Trespiano, ye should have your bound\'ry,\nThan to have them within, and bear the stench\nOf Aguglione\'s hind, and Signa\'s, him,\nThat hath his eye already keen for bart\'ring!\nHad not the people, which of all the world\nDegenerates most, been stepdame unto Caesar,\nBu");
    strcat(expected_filecontent, "t, as a mother, gracious to her son;\nSuch one, as hath become a Florentine,\nAnd trades and traffics, had been turn\'d adrift\nTo Simifonte, where his grandsire ply\'d\nThe beggar\'s craft.  The Conti were possess\'d\nOf Montemurlo still: the Cerchi still\nWere in Acone\'s parish; nor had haply\nFrom Valdigrieve past the Buondelmonte.\nThe city\'s malady hath ever source\nIn the confusion of its persons, as\nThe body\'s, in variety of food:\nAnd the blind bull falls with a steeper plunge,\nThan the blind lamb; and oftentimes one sword\nDoth more and better execution,\nThan five.  Mark Luni, Urbisaglia mark,\nHow they are gone, and after them how go\nChiusi and Sinigaglia; and \'t will seem\nNo longer new or strange to thee to hear,\nThat families fail, when cities have their end.\nAll things, that appertain t\' ye, like yourselves,\nAre mortal: but mortality in some\nYe mark not, they endure so long, and you\nPass by so suddenly.  And as the moon\nDoth, by the rolling of her heav\'nly sphere,\nHide and reveal the strand unceasingly;\nSo fortune deals with Florence.  Hence admire not\nAt what of them I tell thee, whose renown\nTime covers, the first Florentines.  I saw\nThe Ughi, Catilini and Filippi,\nThe Alberichi, Greci and Ormanni,\nNow in their wane, illustrious citizens:\nAnd great as ancient, of Sannella him,\nWith him of Arca saw, and Soldanieri\nAnd Ardinghi, and Bostichi.  At the poop,\nThat now is laden with new felony,\nSo cumb\'rous it may speedily sink the bark,\nThe Ravignani sat, of whom is sprung\nThe Co");
                
        
                struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "LEARN.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 9688, file);
                test_error(size == 9688, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 9688 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 9688);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 9688);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 8: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST8(void)
{
    // informacje o teście
    test_start(8, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(10313, 1);
                char expected_filecontent[10314] = "";
        
                strcat(expected_filecontent, "rtue guides not; that if aught of good\nMy gentle star, or something better gave me,\nI envy not myself the precious boon.\n     As in that season, when the sun least veils\nHis face that lightens all, what time the fly\nGives way to the shrill gnat, the peasant then\nUpon some cliff reclin\'d, beneath him sees\nFire-flies innumerous spangling o\'er the vale,\nVineyard or tilth, where his day-labour lies:\nWith flames so numberless throughout its space\nShone the eighth chasm, apparent, when the depth\nWas to my view expos\'d. As he, whose wrongs\nThe bears aveng\'d, at its departure saw\nElijah\'s chariot, when the steeds erect\nRais\'d their steep flight for heav\'n; his eyes meanwhile,\nStraining pursu\'d them, till the flame alone\nUpsoaring like a misty speck he kenn\'d;\nE\'en thus along the gulf moves every flame,\nA sinner so enfolded close in each,\nThat none exhibits token of the theft.\n     Upon the bridge I forward bent to look,\nAnd grasp\'d a flinty mass, or else had fall\'n,\nThough push\'d not from the height.  The guide, who mark d\nHow I did gaze attentive, thus began:\n\"Within these ardours are the spirits, each\nSwath\'d in confining fire.\"--\"Master, thy word,\"\nI answer\'d, \"hath assur\'d me; yet I deem\'d\nAlready of the truth, already wish\'d\nTo ask thee, who is in yon fire, that comes\nSo parted at the summit, as it seem\'d\nAscending from that funeral pile, where lay\nThe Theban brothers?\"  He replied:  \"Within\nUlysses there and Diomede endure\nTheir penal tortures, thus to vengeance now\nTogether hasting, as erewhile to wrath.\nThese in the flame with ceaseless groans deplore\nThe ambush of the horse, that open\'d wide\nA portal for that goodly seed to pass,\nWhich sow\'d imperial Rome; nor less the guile\nLament they, whence of her Achilles \'reft\nDeidamia yet in death complains.\nAnd there is rued the stratagem, that Troy\nOf her Palladium spoil\'d.\"--\"If they have power\nOf utt\'rance from within these sparks,\" said I,\n\"O master!  think my prayer a thousand fold\nIn repetition urg\'d, that thou vouchsafe\nTo pause, till here the horned flame arrive.\nSee, how toward it with desire I bend.\"\n     He thus:  \"Thy prayer is worthy of much praise,\nAnd I accept it therefore:  but do thou\nThy tongue refrain:  to question them be mine,\nFor I divine thy wish:  and they perchance,\nFor they were Greeks, might shun discourse with thee.\"\n     When there the flame had come, where time and place\nSeem\'d fitting to my guide, he thus began:\n\"O ye, who dwell two spirits in one fire!\nIf living I of you did merit aught,\nWhate\'er the measure were of that desert,\nWhen in the world my lofty strain I pour\'d,\nMove ye not on, till one of you unfold\nIn what clime death o\'ertook him self-destroy\'d.\"\n     Of the old flame forthwith the greater horn\nBegan to roll, murmuring, as a fire\nThat labours with the wind, then to and fro\nWagging the top, as a tongue uttering sounds,\nThrew out its voice, and spake:  \"When I escap\'d\nFrom Circe, who beyond a circling year\nHad held me near Caieta, by her charms,\nEre thus Aeneas yet had nam\'d the shore,\nNor fondness for my son, nor reverence\nOf my old father, nor return of love,\nThat should have crown\'d Penelope with joy,\nCould overcome in me the zeal I had\nT\' explore the world, and search the ways of life,\nMan\'s evil and his virtue.  Forth I sail\'d\nInto the deep illimitable main,\nWith but one bark, and the small faithful band\nThat yet cleav\'d to me.  As Iberia far,\nFar as Morocco either shore I saw,\nAnd the Sardinian and each isle beside\nWhich round that ocean bathes.  Tardy with age\nWere I and my companions, when we came\nTo the strait pass, where Hercules ordain\'d\nThe bound\'ries not to be o\'erstepp\'d by man.\nThe walls of Seville to my right I left,\nOn the\' other hand already Ceuta past.\n\"O brothers!\"  I began, \"who to the west\nThrough perils without number now have reach\'d,\nTo this the short remaining watch, that yet\nOur senses have to wake, refuse not proof\nOf the unpeopled world, following the track\nOf Phoebus. Call to mind from whence we sprang:\nYe were not form\'d to live the life of brutes\nBut virtue to pursue and knowledge high.\nWith these few wo");
    strcat(expected_filecontent, "rds I sharpen\'d for the voyage\nThe mind of my associates, that I then\nCould scarcely have withheld them.  To the dawn\nOur poop we turn\'d, and for the witless flight\nMade our oars wings, still gaining on the left.\nEach star of the\' other pole night now beheld,\nAnd ours so low, that from the ocean-floor\nIt rose not.  Five times re-illum\'d, as oft\nVanish\'d the light from underneath the moon\nSince the deep way we enter\'d, when from far\nAppear\'d a mountain dim, loftiest methought\nOf all I e\'er beheld.  Joy seiz\'d us straight,\nBut soon to mourning changed.  From the new land\nA whirlwind sprung, and at her foremost side\nDid strike the vessel.  Thrice it whirl\'d her round\nWith all the waves, the fourth time lifted up\nThe poop, and sank the prow: so fate decreed:\nAnd over us the booming billow clos\'d.\"\n\n\n\nCANTO XXVII\n\nNOW upward rose the flame, and still\'d its light\nTo speak no more, and now pass\'d on with leave\nFrom the mild poet gain\'d, when following came\nAnother, from whose top a sound confus\'d,\nForth issuing, drew our eyes that way to look.\n     As the Sicilian bull, that rightfully\nHis cries first echoed, who had shap\'d its mould,\nDid so rebellow, with the voice of him\nTormented, that the brazen monster seem\'d\nPierc\'d through with pain; thus while no way they found\nNor avenue immediate through the flame,\nInto its language turn\'d the dismal words:\nBut soon as they had won their passage forth,\nUp from the point, which vibrating obey\'d\nTheir motion at the tongue, these sounds we heard:\n\"O thou!  to whom I now direct my voice!\nThat lately didst exclaim in Lombard phrase,\n     Depart thou, I solicit thee no more,\'\nThough somewhat tardy I perchance arrive\nLet it not irk thee here to pause awhile,\nAnd with me parley:  lo! it irks not me\nAnd yet I burn.  If but e\'en now thou fall\ninto this blind world, from that pleasant land\nOf Latium, whence I draw my sum of guilt,\nTell me if those, who in Romagna dwell,\nHave peace or war.  For of the mountains there\nWas I, betwixt Urbino and the height,\nWhence Tyber first unlocks his mighty flood.\"\n     Leaning I listen\'d yet with heedful ear,\nWhen, as he touch\'d my side, the leader thus:\n\"Speak thou: he is a Latian.\"  My reply\nWas ready, and I spake without delay:\n     \"O spirit!  who art hidden here below!\nNever was thy Romagna without war\nIn her proud tyrants\' bosoms, nor is now:\nBut open war there left I none.  The state,\nRavenna hath maintain\'d this many a year,\nIs steadfast.  There Polenta\'s eagle broods,\nAnd in his broad circumference of plume\nO\'ershadows Cervia. The green talons grasp\nThe land, that stood erewhile the proof so long,\nAnd pil\'d in bloody heap the host of France.\n     \"The\' old mastiff of Verruchio and the young,\nThat tore Montagna in their wrath, still make,\nWhere they are wont, an augre of their fangs.\n     \"Lamone\'s city and Santerno\'s range\nUnder the lion of the snowy lair.\nInconstant partisan! that changeth sides,\nOr ever summer yields to winter\'s frost.\nAnd she, whose flank is wash\'d of Savio\'s wave,\nAs \'twixt the level and the steep she lies,\nLives so \'twixt tyrant power and liberty.\n     \"Now tell us, I entreat thee, who art thou?\nBe not more hard than others.  In the world,\nSo may thy name still rear its forehead high.\"\n     Then roar\'d awhile the fire, its sharpen\'d point\nOn either side wav\'d, and thus breath\'d at last:\n\"If I did think, my answer were to one,\nWho ever could return unto the world,\nThis flame should rest unshaken.  But since ne\'er,\nIf true be told me, any from this depth\nHas found his upward way, I answer thee,\nNor fear lest infamy record the words.\n     \"A man of arms at first, I cloth\'d me then\nIn good Saint Francis\' girdle, hoping so\nT\' have made amends.  And certainly my hope\nHad fail\'d not, but that he, whom curses light on,\nThe\' high priest again seduc\'d me into sin.\nAnd how and wherefore listen while I tell.\nLong as this spirit mov\'d the bones and pulp\nMy mother gave me, less my deeds bespake\nThe nature of the lion than the fox.\nAll ways of winding subtlety I knew,\nAnd with such art conducted, that the sound\nReach\'d the world\'s limit.  Soon ");
    strcat(expected_filecontent, "as to that part\nOf life I found me come, when each behoves\nTo lower sails and gather in the lines;\nThat which before had pleased me then I rued,\nAnd to repentance and confession turn\'d;\nWretch that I was! and well it had bested me!\nThe chief of the new Pharisees meantime,\nWaging his warfare near the Lateran,\nNot with the Saracens or Jews (his foes\nAll Christians were, nor against Acre one\nHad fought, nor traffic\'d in the Soldan\'s land),\nHe his great charge nor sacred ministry\nIn himself, rev\'renc\'d, nor in me that cord,\nWhich us\'d to mark with leanness whom it girded.\nAs in Socrate, Constantine besought\nTo cure his leprosy Sylvester\'s aid,\nSo me to cure the fever of his pride\nThis man besought: my counsel to that end\nHe ask\'d:  and I was silent:  for his words\nSeem\'d drunken:  but forthwith he thus resum\'d:\n\"From thy heart banish fear:  of all offence\nI hitherto absolve thee.  In return,\nTeach me my purpose so to execute,\nThat Penestrino cumber earth no more.\nHeav\'n, as thou knowest, I have power to shut\nAnd open:  and the keys are therefore twain,\nThe which my predecessor meanly priz\'d.\"\n     Then, yielding to the forceful arguments,\nOf silence as more perilous I deem\'d,\nAnd answer\'d:  \"Father! since thou washest me\nClear of that guilt wherein I now must fall,\nLarge promise with performance scant, be sure,\nShall make thee triumph in thy lofty seat.\"\n     \"When I was number\'d with the dead, then came\nSaint Francis for me; but a cherub dark\nHe met, who cried: \"\'Wrong me not; he is mine,\nAnd must below to join the wretched crew,\nFor the deceitful counsel which he gave.\nE\'er since I watch\'d him, hov\'ring at his hair,\nNo power can the impenitent absolve;\nNor to repent and will at once consist,\nBy contradiction absolute forbid.\"\nOh mis\'ry! how I shook myself, when he\nSeiz\'d me, and cried, \"Thou haply thought\'st me not\nA disputant in logic so exact.\"\nTo Minos down he bore me, and the judge\nTwin\'d eight times round his callous back the tail,\nWhich biting with excess of rage, he spake:\n\"This is a guilty soul, that in the fire\nMust vanish.\'  Hence perdition-doom\'d I rove\nA prey to rankling sorro");
                
        
                struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "DRINK.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 10313, file);
                test_error(size == 10313, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 10313 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 10313);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 10313);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 9: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST9(void)
{
    // informacje o teście
    test_start(9, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(1544, 1);
                char expected_filecontent[1545] = "";
        
                strcat(expected_filecontent, "males to\ndeath.\n\nv. 120.  Alessio.]  Alessio, of an ancient and considerable\nfamily in Lucca, called the Interminei.\n\nv. 130.  Thais.]  He alludes to that passage in the Eunuchus of\nTerence where Thraso asks if Thais was obliged to him for the\npresent he had sent her, and Gnatho replies, that she had\nexpressed her obligation in the most forcible terms.\n        T.  Magnas vero agere gratias Thais mihi?\n        G.  Ingentes.\n               Eun. a. iii. s. i.\n\nCANTO XIX\n\nv. 18.  Saint John\'s fair dome.]  The apertures in the  rock were\nof the same dimensions as the fonts of St. John the Baptist at\nFlorence, one of which, Dante says he had broken, to rescue a\nchild  that was playing near and fell in. He intimates that the\nmotive of his  breaking the font had been maliciously represented\nby his enemies.\n\nv. 55.  O Boniface!]  The spirit mistakes Dante for  Boniface\nVIII. who was then alive, and who he did not expect would have\narrived so soon, in consequence, as it should seem, of a\nprophecy, which  predicted the death of that Pope at a later\nperiod. Boniface died in  1303.\n\nv. 58.  In guile.]  \"Thou didst presume to arrive by fraudulent\nmeans at the papal power, and afterwards to abuse it.\"\n\nv. 71.  In the mighty mantle I was rob\'d.]  Nicholas III, of the\nOrsini family, whom the poet therefore calls \"figliuol dell\'\norsa,\" \"son of the she-bear.\"  He died in 1281.\n\nv. 86.  From forth the west, a shepherd without law.]   Bertrand\nde Got Archbishop of Bordeaux, who succeeded to the pontificate\nin 1305, and assumed the title of");
                
        
                struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "COME");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 1544, file);
                test_error(size == 1544, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 1544 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 1544);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 1544);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 10: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST10(void)
{
    // informacje o teście
    test_start(10, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(12521, 1);
                char expected_filecontent[12522] = "";
        
                strcat(expected_filecontent, "h, conjur\'d by fell\nErictho, sorceress, who compell\'d the shades\nBack to their bodies.  No long space my flesh\nWas naked of me, when within these walls\nShe made me enter, to draw forth a spirit\nFrom out of Judas\' circle.  Lowest place\nIs that of all, obscurest, and remov\'d\nFarthest from heav\'n\'s all-circling orb.  The road\nFull well I know:  thou therefore rest secure.\nThat lake, the noisome stench exhaling, round\nThe city\' of grief encompasses, which now\nWe may not enter without rage.\"  Yet more\nHe added:  but I hold it not in mind,\nFor that mine eye toward the lofty tower\nHad drawn me wholly, to its burning top.\nWhere in an instant I beheld uprisen\nAt once three hellish furies stain\'d with blood:\nIn limb and motion feminine they seem\'d;\nAround them greenest hydras twisting roll\'d\nTheir volumes; adders and cerastes crept\nInstead of hair, and their fierce temples bound.\n     He knowing well the miserable hags\nWho tend the queen of endless woe, thus spake:\n\"Mark thou each dire Erinnys. To the left\nThis is Megaera; on the right hand she,\nWho wails, Alecto; and Tisiphone\nI\' th\' midst.\"  This said, in silence he remain\'d\nTheir breast they each one clawing tore; themselves\nSmote with their palms, and such shrill clamour rais\'d,\nThat to the bard I clung, suspicion-bound.\n\"Hasten Medusa: so to adamant\nHim shall we change;\" all looking down exclaim\'d.\n\"E\'en when by Theseus\' might assail\'d, we took\nNo ill revenge.\"  \"Turn thyself round, and keep\nThy count\'nance hid; for if the Gorgon dire\nBe shown, and thou shouldst view it, thy return\nUpwards would be for ever lost.\"  This said,\nHimself my gentle master turn\'d me round,\nNor trusted he my hands, but with his own\nHe also hid me.  Ye of intellect\nSound and entire, mark well the lore conceal\'d\nUnder close texture of the mystic strain!\n     And now there came o\'er the perturbed waves\nLoud-crashing, terrible, a sound that made\nEither shore tremble, as if of a wind\nImpetuous, from conflicting vapours sprung,\nThat \'gainst some forest driving all its might,\nPlucks off the branches, beats them down and hurls\nAfar; then onward passing proudly sweeps\nIts whirlwind rage, while beasts and shepherds fly.\n     Mine eyes he loos\'d, and spake: \"And now direct\nThy visual nerve along that ancient foam,\nThere, thickest where the smoke ascends.\" As frogs\nBefore their foe the serpent, through the wave\nPly swiftly all, till at the ground each one\nLies on a heap; more than a thousand spirits\nDestroy\'d, so saw I fleeing before one\nWho pass\'d with unwet feet the Stygian sound.\nHe, from his face removing the gross air,\nOft his left hand forth stretch\'d, and seem\'d alone\nBy that annoyance wearied.  I perceiv\'d\nThat he was sent from heav\'n, and to my guide\nTurn\'d me, who signal made that I should stand\nQuiet, and bend to him. Ah me!  how full\nOf noble anger seem\'d he!  To the gate\nHe came, and with his wand touch\'d it, whereat\nOpen without impediment it flew.\n     \"Outcasts of heav\'n!  O abject race and scorn\'d!\"\nBegan he on the horrid grunsel standing,\n\"Whence doth this wild excess of insolence\nLodge in you? wherefore kick you \'gainst that will\nNe\'er frustrate of its end, and which so oft\nHath laid on you enforcement of your pangs?\nWhat profits at the fays to but the horn?\nYour Cerberus, if ye remember, hence\nBears still, peel\'d of their hair, his throat and maw.\"\n     This said, he turn\'d back o\'er the filthy way,\nAnd syllable to us spake none, but wore\nThe semblance of a man by other care\nBeset, and keenly press\'d, than thought of him\nWho in his presence stands.  Then we our steps\nToward that territory mov\'d, secure\nAfter the hallow\'d words.  We unoppos\'d\nThere enter\'d; and my mind eager to learn\nWhat state a fortress like to that might hold,\nI soon as enter\'d throw mine eye around,\nAnd see on every part wide-stretching space\nReplete with bitter pain and torment ill.\n     As where Rhone stagnates on the plains of Arles,\nOr as at Pola, near Quarnaro\'s gulf,\nThat closes Italy and laves her bounds,\nThe place is all thick spread with sepulchres;\nSo was it here, save what in horror here\nExcell\'d:  for \'midst ");
    strcat(expected_filecontent, "the graves were scattered flames,\nWherewith intensely all throughout they burn\'d,\nThat iron for no craft there hotter needs.\n     Their lids all hung suspended, and beneath\nFrom them forth issu\'d lamentable moans,\nSuch as the sad and tortur\'d well might raise.\n     I thus:  \"Master! say who are these, interr\'d\nWithin these vaults, of whom distinct we hear\nThe dolorous sighs?\"  He answer thus return\'d:\n     \"The arch-heretics are here, accompanied\nBy every sect their followers; and much more,\nThan thou believest, tombs are freighted:  like\nWith like is buried; and the monuments\nAre different in degrees of heat. \"This said,\nHe to the right hand turning, on we pass\'d\nBetwixt the afflicted and the ramparts high.\n\n\n\nCANTO X\n\nNOW by a secret pathway we proceed,\nBetween the walls, that hem the region round,\nAnd the tormented souls:  my master first,\nI close behind his steps.  \"Virtue supreme!\"\nI thus began; \"who through these ample orbs\nIn circuit lead\'st me, even as thou will\'st,\nSpeak thou, and satisfy my wish.  May those,\nWho lie within these sepulchres, be seen?\nAlready all the lids are rais\'d, and none\nO\'er them keeps watch.\"  He thus in answer spake\n\"They shall be closed all, what-time they here\nFrom Josaphat return\'d shall come, and bring\nTheir bodies, which above they now have left.\nThe cemetery on this part obtain\nWith Epicurus all his followers,\nWho with the body make the spirit die.\nHere therefore satisfaction shall be soon\nBoth to the question ask\'d, and to the wish,\nWhich thou conceal\'st in silence.\"  I replied:\n\"I keep not, guide belov\'d! from thee my heart\nSecreted, but to shun vain length of words,\nA lesson erewhile taught me by thyself.\"\n     \"O Tuscan! thou who through the city of fire\nAlive art passing, so discreet of speech!\nHere please thee stay awhile. Thy utterance\nDeclares the place of thy nativity\nTo be that noble land, with which perchance\nI too severely dealt.\"  Sudden that sound\nForth issu\'d from a vault, whereat in fear\nI somewhat closer to my leader\'s side\nApproaching, he thus spake:  \"What dost thou?  Turn.\nLo, Farinata, there! who hath himself\nUplifted:  from his girdle upwards all\nExpos\'d behold him.\"  On his face was mine\nAlready fix\'d; his breast and forehead there\nErecting, seem\'d as in high scorn he held\nE\'en hell.  Between the sepulchres to him\nMy guide thrust me with fearless hands and prompt,\nThis warning added:  \"See thy words be clear!\"\n     He, soon as there I stood at the tomb\'s foot,\nEy\'d me a space, then in disdainful mood\nAddress\'d me:  \"Say, what ancestors were thine?\"\n     I, willing to obey him, straight reveal\'d\nThe whole, nor kept back aught: whence he, his brow\nSomewhat uplifting, cried:  \"Fiercely were they\nAdverse to me, my party, and the blood\nFrom whence I sprang:  twice therefore I abroad\nScatter\'d them.\"  \"Though driv\'n out, yet they each time\nFrom all parts,\" answer\'d I, \"return\'d; an art\nWhich yours have shown, they are not skill\'d to learn.\"\n     Then, peering forth from the unclosed jaw,\nRose from his side a shade, high as the chin,\nLeaning, methought, upon its knees uprais\'d.\nIt look\'d around, as eager to explore\nIf there were other with me; but perceiving\nThat fond imagination quench\'d, with tears\nThus spake:  \"If thou through this blind prison go\'st.\nLed by thy lofty genius and profound,\nWhere is my son? and wherefore not with thee?\"\n     I straight replied:  \"Not of myself I come,\nBy him, who there expects me, through this clime\nConducted, whom perchance Guido thy son\nHad in contempt.\"  Already had his words\nAnd mode of punishment read me his name,\nWhence I so fully answer\'d.  He at once\nExclaim\'d, up starting, \"How! said\'st thou he HAD?\nNo longer lives he?  Strikes not on his eye\nThe blessed daylight?\"  Then of some delay\nI made ere my reply aware, down fell\nSupine, not after forth appear\'d he more.\n     Meanwhile the other, great of soul, near whom\nI yet was station\'d, chang\'d not count\'nance stern,\nNor mov\'d the neck, nor bent his ribbed side.\n\"And if,\" continuing the first discourse,\n\"They in this art,\" he cried, \"small skill have shown,\nThat doth torment m");
    strcat(expected_filecontent, "e more e\'en than this bed.\nBut not yet fifty times shall be relum\'d\nHer aspect, who reigns here Queen of this realm,\nEre thou shalt know the full weight of that art.\nSo to the pleasant world mayst thou return,\nAs thou shalt tell me, why in all their laws,\nAgainst my kin this people is so fell?\"\n     \"The slaughter and great havoc,\" I replied,\n\"That colour\'d Arbia\'s flood with crimson stain--\nTo these impute, that in our hallow\'d dome\nSuch orisons ascend.\"  Sighing he shook\nThe head, then thus resum\'d:  \"In that affray\nI stood not singly, nor without just cause\nAssuredly should with the rest have stirr\'d;\nBut singly there I stood, when by consent\nOf all, Florence had to the ground been raz\'d,\nThe one who openly forbad the deed.\"\n     \"So may thy lineage find at last repose,\"\nI thus adjur\'d him, \"as thou solve this knot,\nWhich now involves my mind.  If right I hear,\nYe seem to view beforehand, that which time\nLeads with him, of the present uninform\'d.\"\n     \"We view, as one who hath an evil sight,\"\nHe answer\'d, \"plainly, objects far remote:\nSo much of his large spendour yet imparts\nThe\' Almighty Ruler; but when they approach\nOr actually exist, our intellect\nThen wholly fails, nor of your human state\nExcept what others bring us know we aught.\nHence therefore mayst thou understand, that all\nOur knowledge in that instant shall expire,\nWhen on futurity the portals close.\"\n     Then conscious of my fault, and by remorse\nSmitten, I added thus:  \"Now shalt thou say\nTo him there fallen, that his offspring still\nIs to the living join\'d; and bid him know,\nThat if from answer silent I abstain\'d,\n\'Twas that my thought was occupied intent\nUpon that error, which thy help hath solv\'d.\"\n     But now my master summoning me back\nI heard, and with more eager haste besought\nThe spirit to inform me, who with him\nPartook his lot.  He answer thus return\'d:\n     \"More than a thousand with me here are laid\nWithin is Frederick, second of that name,\nAnd the Lord Cardinal, and of the rest\nI speak not.\"  He, this said, from sight withdrew.\nBut I my steps towards the ancient bard\nReverting, ruminated on the words\nBetokening me such ill.  Onward he mov\'d,\nAnd thus in going question\'d:  \"Whence the\' amaze\nThat holds thy senses wrapt?\"  I satisfied\nThe\' inquiry, and the sage enjoin\'d me straight:\n\"Let thy safe memory store what thou hast heard\nTo thee importing harm; and note thou this,\"\nWith his rais\'d finger bidding me take heed,\n     \"When thou shalt stand before her gracious beam,\nWhose bright eye all surveys, she of thy life\nThe future tenour will to thee unfold.\"\n     Forthwith he to the left hand turn\'d his feet:\nWe left the wall, and tow\'rds the middle space\nWent by a path, that to a valley strikes;\nWhich e\'en thus high exhal\'d its noisome steam.\n\n\n\nCANTO XI\n\nUPON the utmost verge of a high bank,\nBy craggy rocks environ\'d round, we came,\nWhere woes beneath more cruel yet were stow\'d:\nAnd here to shun the horrible excess\nOf fetid exhalation, upward cast\nFrom the profound abyss, behind the lid\nOf a great monument we stood retir\'d,\nWhereon this scroll I mark\'d:  \"I have in charge\nPope Anastasius, whom Photinus drew\nFrom the right path.--Ere our descent behooves\nWe make delay, that somewhat first the sense,\nTo the dire breath accustom\'d, afterward\nRegard it not.\"  My master thus; to whom\nAnswering I spake:  \"Some compensation find\nThat the time past not wholly lost.\"  He then:\n\"Lo! how my thoughts e\'en to thy wishes tend!\nMy son! within these rocks,\" he thus began,\n\"Are three close circles in gradation plac\'d,\nAs these which now thou leav\'st. Each one is full\nOf spirits accurs\'d; but that the sight alone\nHereafter may suffice thee, listen how\nAnd for what cause in durance they abide.\n     \"Of all malicious act abhorr\'d in heaven,\nThe end is injury; and all such end\nEither by force or fraud works other\'s woe\nBut fraud, because of man peculiar evil,\nTo God is more displeasing; and beneath\nThe fraudulent are therefore doom\'d to\' endure\nSeverer pang.  The violent occupy\nAll the first circle; and because to force\nThree persons are obnoxious, in three roun");
    strcat(expected_filecontent, "ds\nHach within other sep\'rate is it fram\'d.\nTo God, his neighbour, and himself, by man\nForce may be offer\'d; to himself I say\nAnd his possessions, as thou soon shalt hear\nAt full.  Death, violent death, and painful wounds\nUpon his neigh");
                
        
                struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "SEVEN.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 12521, file);
                test_error(size == 12521, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 12521 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 12521);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 12521);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 11: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST11(void)
{
    // informacje o teście
    test_start(11, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(7471, 1);
                char expected_filecontent[7472] = "";
        
                strcat(expected_filecontent, "t it out of the\nkingdom, because it was the land of the church, and that it was\nburied by the river Verde, on the borders of the kingdom and of\nCarapagna. this, however, we do not affirm.\"  G. Villani, Hist.\nl. vii.  c. 9.\n\nv. 111.  Costanza.]  See Paradise Canto III.  v. 121.\n\nv. 112.  My fair daughter.]  Costanza, the daughter of Manfredi,\nand wife of Peter III.  King of Arragon, by whom she was mother\nto  Frederick, King of Sicily and James, King of Arragon With the\nlatter of these she was at Rome 1296. See G. Villani, 1. viii. c.\n18. and notes to Canto VII.\n\nv. 122.  Clement.]  Pope Clement IV.\n\nv. 127.  The stream of Verde.]  A river near Ascoli, that falls\ninto he Toronto. The \"xtinguished lights \" formed part of the\nceremony t the interment of one excommunicated.\n\nv. 130.  Hope.]\nMentre che la speranza ha fior del verde.\nTasso, G. L. c. xix. st. 53.\n--infin che verde e fior di speme.\n\nCANTO IV\n\nv. 1.  When.] It must be owned the beginning of this Canto is\nsomewhat obscure. Bellutello refers, for an elucidation of it, to\nthe reasoning of Statius in the twenty-fifth canto. Perhaps some\nillustration may be derived from the following, passage in\nSouth\'s Sermons, in which I have ventured to supply the words\nbetween crotchets that seemed to be wanting to complete\nthe sense. Now whether these three, judgement memory, and\ninvention, are three distinct things, both in being distinguished\nfrom one another, and likewise from the substance of the soul\nitself, considered without any such faculties, (or whether the\nsoul be one individual substance) but only receiving these\nseveral denominations rom the several respects arising from the\nseveral actions exerted immediately by itself upon several\nobjects, or several qualities of the same object, I say whether\nof these it is, is not easy to decide, and it is well that it is\nnot necessary Aquinas, and most with him, affirm the former, and\nScotus with his followers the latter.\" Vol. iv. Serm. 1.\n\nv. 23.  Sanleo.]  A fortress on the summit of Montefeltro.\n\nv. 24.  Noli.]  In the Genoese territory, between Finale and\nSavona.\n\nv. 25.  Bismantua.]  A steep mountain in the territory of Reggio.\n\nv. 55.  From the left.]  Vellutello observes an imitation of\nLucan in this passage:\n\nIgnotum vobis, Arabes, venistis in orbem,\nUmbras mirati nemornm non ire sinistras.\nPhars.  s. 1.  iii. 248\n\nv. 69 Thou wilt see.]  \"If you consider that this mountain of\nPurgatory and that of Sion are antipodal to each other, you will\nperceive that the sun must rise on opposite sides of the\nrespective eminences.\"\n\nv. 119.  Belacqua.]  Concerning this man, the commentators afford\nno information.\n\nCANTO V\n\nv. 14.  Be as a tower.]  Sta  ome torre ferma\n\nBerni, Orl.  Inn. 1. 1. c. xvi. st. 48:\nIn quei due piedi sta fermo il gigante\nCom\' una torre in mezzo d\'un castello.\n\nAnd Milton, P. L. b. i.  591.\nStood like a tower.\n\nv. 36.  Ne\'er saw I fiery vapours.]  Imitated by Tasso, G. L, c.\nxix t. 62:\nTal suol fendendo liquido sereno\nStella cader della gran madre in seno.\n\nAnd by Milton, P. L. b. iv. 558:\nSwift as a shooting star\nIn autumn thwarts the night, when vapours fir\'d\nImpress the air.\n\nv. 67.  That land.]  The Marca d\'Ancona, between Romagna and\nApulia, the kingdom of Charles of Anjou.\n\nv. 76.  From thence I came.]  Giacopo del Cassero, a citizen of\nFano who having spoken ill of Azzo da Este, Marquis of Ferrara,\nwas by his orders put to death.  Giacopo, was overtaken by the\nassassins at Oriaco a place near the Brenta, from whence, if he\nhad fled towards Mira, higher up on that river, instead of making\nfor the marsh on the sea shore, he might have escaped.\n\nv. 75.  Antenor\'s land.]  The city of Padua, said to be founded\nby Antenor.\n\nv. 87.  Of Montefeltro I.]  Buonconte (son of Guido da\nMontefeltro, whom we have had in the twenty-seventh Canto of\nHell) fell in the battle of Campaldino (1289), fighting on the\nside of the Aretini.\n\nv. 88.  Giovanna.]  Either the wife, or kinswoman, of Buonconte.\n\nv. 91.  The hermit\'s seat.]  The hermitage of Camaldoli.\n\nv. 95.  Where its name is cancel\'d.]  That is, between Bibbiena\na");
    strcat(expected_filecontent, "nd Poppi, where the Archiano falls into the Arno.\n\nv. 115.  From Pratomagno to the mountain range.]  From Pratomagno\nnow called Prato Vecchio (which divides the Valdarno from\nCasentino) as far as to the Apennine.\n\nv. 131.  Pia.] She is said to have been a Siennese lady, of the\nfamily of Tolommei, secretly made away with by her husband, Nello\ndella Pietra, of the same city, in Maremma, where he had some\npossessions.\n\nCANTO VI\n\nv. 14.  Of Arezzo him.]  Benincasa of Arezzo, eminent for his\nskill in jurisprudence, who, having condemned to death Turrino da\nTurrita brother of Ghino di Tacco, for his robberies in Maremma,\nwas murdered by Ghino, in an apartment of his own house, in the\npresence of many witnesses. Ghino was not only suffered to escape\nin safety, but (as the commentators inform us) obtained so high a\nreputation by the liberality with which he was accustomed to\ndispense the fruits of his plunder, and treated those who fell\ninto his hands with so much courtesy, that he was afterwards\ninvited to Rome, and knighted by Boniface VIII. A story is told\nof him by Boccaccio, G. x. N. 2.\n\nv. 15.  Him beside.]  Ciacco de\' Tariatti of Arezzo.  He is said\nto have been carried by his horse into the Arno, and there\ndrowned, while he was in pursuit of certain of his enemies.\n\nv. 17.  Frederic Novello.]  Son of the Conte Guido da Battifolle,\nand slain by one of the family of Bostoli.\n\nv. 18.  Of Pisa he.]  Farinata de\' Scornigiani of Pisa.  His\nfather Marzuco, who had entered the order of the Frati Minori, so\nentirely overcame the feelings of resentment, that he even kissed\nthe hands of the slayer of his son, and, as he was following the\nfuneral, exhorted his kinsmen to reconciliation.\n\nv. 20.  Count 0rso.]  Son of Napoleone da Cerbaia, slain by\nAlberto da Mangona, his uncle.\n\nv. 23.  Peter de la Brosse.]  Secretary of Philip III  of France.\nThe courtiers, envying the high place which he held in the king\'s\nfavour, prevailed on Mary of Brabant to charge him falsely with\nan attempt upon her person for which supposed crime he suffered\ndeath. So say the Italian commentators.  Henault represents the\nmatter very differently: \"Pierre de la Brosse, formerly barber to\nSt. Louis, afterwards the favorite of Philip, fearing the too\ngreat attachment of the king for his wife Mary, accuses this\nprincess of having poisoned Louis, eldest son of Philip, by his\nfirst marriage. This calumny is discovered by a nun of Nivelle in\nFlanders.  La Brosse is hung.\" Abrege Chron. t. 275, &c.\n\nv. 30.  In thy text.]  He refers to Virgil, Aen. 1, vi.  376.\nDesine fata deum flecti sperare precando, 37. The sacred height\nOf judgment. Shakespeare, Measure for Measure, a. ii. s. 2.\nIf he, which is the top of judgment\n\nv. 66.  Eyeing us as a lion on his watch.]\nA guisa di Leon quando si posa.\nA line taken by Tasso, G.  L. c. x. st. 56.\n\nv. 76.  Sordello.]  The history of Sordello\'s life is wrapt in\nthe obscurity of romance.  That he distinguished himself by his\nskill in Provencal poetry is certain. It is probable that he was\nborn towards the end of the twelfth, and died about the middle of\nthe succeeding century.  Tiraboschi has taken much pains to sift\nall the notices he could collect relating to him.  Honourable\nmention of his name is made by our Poet in the Treatise de Vulg.\nEloq.  1. i. c. 15.\n\nv. 76.  Thou inn of grief.]\nThou most beauteous inn\nWhy should h");
                
        
                struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "QUESTION.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 7471, file);
                test_error(size == 7471, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 7471 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 7471);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 7471);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 12: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST12(void)
{
    // informacje o teście
    test_start(12, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
        
                char *filecontent = (char *)calloc(11807, 1);
                char expected_filecontent[11808] = "";
        
                strcat(expected_filecontent, "ucca: and that face beyond him, pierc\'d\nUnto a leaner fineness than the rest,\nHad keeping of the church: he was of Tours,\nAnd purges by wan abstinence away\nBolsena\'s eels and cups of muscadel.\"\n     He show\'d me many others, one by one,\nAnd all, as they were nam\'d, seem\'d well content;\nFor no dark gesture I discern\'d in any.\nI saw through hunger Ubaldino grind\nHis teeth on emptiness; and Boniface,\nThat wav\'d the crozier o\'er a num\'rous flock.\nI saw the Marquis, who tad time erewhile\nTo swill at Forli with less drought, yet so\nWas one ne\'er sated.  I howe\'er, like him,\nThat gazing \'midst a crowd, singles out one,\nSo singled him of Lucca; for methought\nWas none amongst them took such note of me.\nSomewhat I heard him whisper of Gentucca:\nThe sound was indistinct, and murmur\'d there,\nWhere justice, that so strips them, fix\'d her sting.\n     \"Spirit!\" said I, \"it seems as thou wouldst fain\nSpeak with me.  Let me hear thee.  Mutual wish\nTo converse prompts, which let us both indulge.\"\n     He, answ\'ring, straight began: \"Woman is born,\nWhose brow no wimple shades yet, that shall make\nMy city please thee, blame it as they may.\nGo then with this forewarning.  If aught false\nMy whisper too implied, th\' event shall tell\nBut say, if of a  truth I see the man\nOf that new lay th\' inventor, which begins\nWith \'Ladies, ye that con the lore of love\'.\"\n     To whom I thus:  \"Count of me but as one\nWho am the scribe of love; that, when he breathes,\nTake up my pen, and, as he dictates, write.\"\n     \"Brother!\" said he, \"the hind\'rance which once held\nThe notary with Guittone and myself,\nShort of that new and sweeter style I hear,\nIs now disclos\'d.  I see how ye your plumes\nStretch, as th\' inditer guides them; which, no question,\nOurs did not.  He that seeks a grace beyond,\nSees not the distance parts one style from other.\"\nAnd, as contented, here he held his peace.\n     Like as the bird, that winter near the Nile,\nIn squared regiment direct their course,\nThen stretch themselves in file for speedier flight;\nThus all the tribe of spirits, as they turn\'d\nTheir visage, faster deaf, nimble alike\nThrough leanness and desire.  And as a man,\nTir\'d With the motion of a trotting steed,\nSlacks pace, and stays behind his company,\nTill his o\'erbreathed lungs keep temperate time;\nE\'en so Forese let that holy crew\nProceed, behind them lingering at my side,\nAnd saying: \"When shall I again behold thee?\"\n     \"How long my life may last,\" said I, \"I know not;\nThis know, how soon soever I return,\nMy wishes will before me have arriv\'d.\nSithence the place, where I am set to live,\nIs, day by day, more scoop\'d of all its good,\nAnd dismal ruin seems to threaten it.\"\n     \"Go now,\" he cried:  \"lo!  he, whose guilt is most,\nPasses before my vision, dragg\'d at heels\nOf an infuriate beast.  Toward the vale,\nWhere guilt hath no redemption, on it speeds,\nEach step increasing swiftness on the last;\nUntil a blow it strikes, that leaveth him\nA corse most vilely shatter\'d.  No long space\nThose wheels have yet to roll\"  (therewith his eyes\nLook\'d up to heav\'n) \"ere thou shalt plainly see\nThat which my words may not more plainly tell.\nI quit thee: time is precious here: I lose\nToo much, thus measuring my pace with shine.\"\n     As from a troop of well-rank\'d chivalry\nOne knight, more enterprising than the rest,\nPricks forth at gallop, eager to display\nHis prowess in the first encounter prov\'d\nSo parted he from us with lengthen\'d strides,\nAnd left me on the way with those twain spirits,\nWho were such mighty marshals of the world.\n     When he beyond us had so fled mine eyes\nNo nearer reach\'d him, than my thought his words,\nThe branches of another fruit, thick hung,\nAnd blooming fresh, appear\'d.  E\'en as our steps\nTurn\'d thither, not far off it rose to view.\nBeneath it were a multitude, that rais\'d\nTheir hands, and shouted forth I know not What\nUnto the boughs; like greedy and fond brats,\nThat beg, and answer none obtain from him,\nOf whom they beg; but more to draw them on,\nHe at arm\'s length the object of their wish\nAbove them holds aloft, and hides it not.\n     At length, as un");
    strcat(expected_filecontent, "deceiv\'d they went their way:\nAnd we approach the tree, who vows and tears\nSue to in vain, the mighty tree.  \"Pass on,\nAnd come not near.  Stands higher up the wood,\nWhereof Eve tasted, and from it was ta\'en\n\'this plant.\" Such sounds from midst the thickets came.\nWhence I, with either bard, close to the side\nThat rose, pass\'d forth beyond.  \"Remember,\" next\nWe heard, \"those noblest creatures of the clouds,\nHow they their twofold bosoms overgorg\'d\nOppos\'d in fight to Theseus:  call to mind\nThe Hebrews, how effeminate they stoop\'d\nTo ease their thirst; whence Gideon\'s ranks were thinn\'d,\nAs he to Midian march\'d adown the hills.\"\n     Thus near one border coasting, still we heard\nThe sins of gluttony, with woe erewhile\nReguerdon\'d.  Then along the lonely path,\nOnce more at large, full thousand paces on\nWe travel\'d, each contemplative and mute.\n     \"Why pensive journey thus ye three alone?\"\nThus suddenly a voice exclaim\'d: whereat\nI shook, as doth a scar\'d and paltry beast;\nThen rais\'d my head to look from whence it came.\n     Was ne\'er, in furnace, glass, or metal seen\nSo bright and glowing red, as was the shape\nI now beheld.  \"If ye desire to mount,\"\nHe cried, \"here must ye turn.  This way he goes,\nWho goes in quest of peace.\"  His countenance\nHad dazzled me; and to my guides I fac\'d\nBackward, like one who walks, as sound directs.\n     As when, to harbinger the dawn, springs up\nOn freshen\'d wing the air of May, and breathes\nOf fragrance, all impregn\'d with herb and flowers,\nE\'en such a wind I felt upon my front\nBlow gently, and the moving of a wing\nPerceiv\'d, that moving shed ambrosial smell;\nAnd then a voice:  \"Blessed are they, whom grace\nDoth so illume, that appetite in them\nExhaleth no inordinate desire,\nStill hung\'ring as the rule of temperance wills.\"\n\n\n\nCANTO XXV\n\nIt was an hour, when he who climbs, had need\nTo walk uncrippled: for the sun had now\nTo Taurus the meridian circle left,\nAnd to the Scorpion left the night.  As one\nThat makes no pause, but presses on his road,\nWhate\'er betide him, if some urgent need\nImpel: so enter\'d we upon our way,\nOne before other; for, but singly, none\nThat steep and narrow scale admits to climb.\n     E\'en as the young stork lifteth up his wing\nThrough wish to fly, yet ventures not to quit\nThe nest, and drops it; so in me desire\nOf questioning my guide arose, and fell,\nArriving even to the act, that marks\nA man prepar\'d for speech.  Him all our haste\nRestrain\'d not, but thus spake the sire belov\'d:\nFear not to speed the shaft, that on thy lip\nStands trembling for its flight.\"  Encourag\'d thus\nI straight began:  \"How there can leanness come,\nWhere is no want of nourishment to feed?\"\n     \"If thou,\" he answer\'d, \"hadst remember\'d thee,\nHow Meleager with the wasting brand\nWasted alike, by equal fires consm\'d,\nThis would not trouble thee: and hadst thou thought,\nHow in the mirror your reflected form\nWith mimic motion vibrates, what now seems\nHard, had appear\'d no harder than the pulp\nOf summer fruit mature.  But that thy will\nIn certainty may find its full repose,\nLo Statius here!  on him I call, and pray\nThat he would now be healer of thy wound.\"\n     \"If in thy presence I unfold to him\nThe secrets of heaven\'s vengeance, let me plead\nThine own injunction, to exculpate me.\"\nSo Statius answer\'d, and forthwith began:\n\"Attend my words, O son, and in thy mind\nReceive them: so shall they be light to clear\nThe doubt thou offer\'st. Blood, concocted well,\nWhich by the thirsty veins is ne\'er imbib\'d,\nAnd rests as food superfluous, to be ta\'en\nFrom the replenish\'d table, in the heart\nDerives effectual virtue, that informs\nThe several human limbs, as being that,\nWhich passes through the veins itself to make them.\nYet more concocted it descends, where shame\nForbids to mention: and from thence distils\nIn natural vessel on another\'s blood.\nThen each unite together, one dispos\'d\nT\' endure, to act the other, through meet frame\nOf its recipient mould: that being reach\'d,\nIt \'gins to work, coagulating first;\nThen vivifies what its own substance caus\'d\nTo bear.  With animation now indued,\nThe active virt");
    strcat(expected_filecontent, "ue (differing from a plant\nNo further, than that this is on the way\nAnd at its limit that) continues yet\nTo operate, that now it moves, and feels,\nAs sea sponge clinging to the rock: and there\nAssumes th\' organic powers its seed convey\'d.\n\'This is the period, son!  at which the virtue,\nThat from the generating heart proceeds,\nIs pliant and expansive; for each limb\nIs in the heart by forgeful nature plann\'d.\nHow babe of animal becomes, remains\nFor thy consid\'ring.  At this point, more wise,\nThan thou hast err\'d, making the soul disjoin\'d\nFrom passive intellect, because he saw\nNo organ for the latter\'s use assign\'d.\n     \"Open thy bosom to the truth that comes.\nKnow soon as in the embryo, to the brain,\nArticulation is complete, then turns\nThe primal Mover with a smile of joy\nOn such great work of nature, and imbreathes\nNew spirit replete with virtue, that what here\nActive it finds, to its own substance draws,\nAnd forms an individual soul, that lives,\nAnd feels, and bends reflective on itself.\nAnd that thou less mayst marvel at the word,\nMark the sun\'s heat, how that to wine doth change,\nMix\'d with the moisture filter\'d through the vine.\n     \"When Lachesis hath spun the thread, the soul\nTakes with her both the human and divine,\nMemory, intelligence, and will, in act\nFar keener than before, the other powers\nInactive all and mute.  No pause allow\'d,\nIn wond\'rous sort self-moving, to one strand\nOf those, where the departed roam, she falls,\nHere learns her destin\'d path.  Soon as the place\nReceives her, round the plastic virtue beams,\nDistinct as in the living limbs before:\nAnd as the air, when saturate with showers,\nThe casual beam refracting, decks itself\nWith many a hue; so here the ambient air\nWeareth that form, which influence of the soul\nImprints on it; and like the flame, that where\nThe fire moves, thither follows, so henceforth\nThe new form on the spirit follows still:\nHence hath it semblance, and is shadow call\'d,\nWith each sense even to the sight endued:\nHence speech is ours, hence laughter, tears, and sighs\nWhich thou mayst oft have witness\'d on the mount\nTh\' obedient shadow fails not to present\nWhatever varying passion moves within us.\nAnd this the cause of what thou marvel\'st at.\"\n     Now the last flexure of our way we reach\'d,\nAnd to the right hand turning, other care\nAwaits us.  Here the rocky precipice\nHurls forth redundant flames, and from the rim\nA blast upblown, with forcible rebuff\nDriveth them back, sequester\'d from its bound.\n     Behoov\'d us, one by one, along the side,\nThat border\'d on the void, to pass; and I\nFear\'d on one hand the fire, on th\' other fear\'d\nHeadlong to fall: when thus th\' instructor warn\'d:\n\"Strict rein must in this place direct the eyes.\nA little swerving and the way is lost.\"\n     Then from the bosom of the burning mass,\n\"O God of mercy!\" heard I sung; and felt\nNo less desire to turn.  And when I saw\nSpirits along the flame proceeding, I\nBetween their footsteps and mine own was fain\nTo share by turns my view.  At the hymn\'s close\nThey shouted loud, \"I do not know a man;\"\nThen in low voice again took up the strain,\nWhich once more ended, \"To the wood,\" they cried,\n\"Ran Dian, and drave forth Callisto, stung\nWith Cytherea\'s poison:\" then return\'d\nUnto their song; then marry a pair extoll\'d,\nWho liv\'d in virtue chastely, and the bands\nOf wedded love.  Nor from that task, I ween,\nSurcease they; whilesoe\'er the scorching fire\nEnclasps them.  Of such skill appliance needs\nTo medicine the wound, that healeth last.\n\n\n\nCANTO XXVI\n\nWhile singly thus along the rim we walk\'d,\nOft the good master warn\'d me:  \"Look thou well.\nA");
                
        
                struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                struct file_t* file = file_open(volume, "TOUCH.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
                size_t size = file_read(filecontent, 1, 11807, file);
                test_error(size == 11807, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 11807 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 11807);
            
                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));
            
                onerror_compare_memory(expected_filecontent, filecontent, 11807);


                free(filecontent);
        
                file_close(file);
                fat_close(volume);
                disk_close(disk);
        
                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 13: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST13(void)
{
    // informacje o teście
    test_start(13, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(10240, 1);
                char expected_filecontent[10241] = "";

                strcat(expected_filecontent, "ator, and remains\nEver between the sun and winter) for the cause\nThou hast assign\'d, from hence toward the north\nDeparts, when those who in the Hebrew land\nInhabit, see it tow\'rds the warmer part.\nBut if it please thee, I would gladly know,\nHow far we have to journey: for the hill\nMounts higher, than this sight of mine can mount.\"\n     He thus to me:  \"Such is this steep ascent,\nThat it is ever difficult at first,\nBut, more a man proceeds, less evil grows.\nWhen pleasant it shall seem to thee, so much\nThat upward going shall be easy to thee.\nAs in a vessel to go down the tide,\nThen of this path thou wilt have reach\'d the end.\nThere hope to rest thee from thy toil.  No more\nI answer, and thus far for certain know.\"\nAs he his words had spoken, near to us\nA voice there sounded:  \"Yet ye first perchance\nMay to repose you by constraint be led.\"\nAt sound thereof each turn\'d, and on the left\nA huge stone we beheld, of which nor I\nNor he before was ware.  Thither we drew,\nfind there were some, who in the shady place\nBehind the rock were standing, as a man\nThru\' idleness might stand.  Among them one,\nWho seem\'d to me much wearied, sat him down,\nAnd with his arms did fold his knees about,\nHolding his face between them downward bent.\n     \"Sweet Sir!\"  I cry\'d, \"behold that man, who shows\nHimself more idle, than if laziness\nWere sister to him.\"  Straight he turn\'d to us,\nAnd, o\'er the thigh lifting his face, observ\'d,\nThen in these accents spake:  \"Up then, proceed\nThou valiant one.\"  Straight who it was I knew;\nNor could the pain I felt (for want of breath\nStill somewhat urg\'d me) hinder my approach.\nAnd when I came to him, he scarce his head\nUplifted, saying \"Well hast thou discern\'d,\nHow from the left the sun his chariot leads.\"\n     His lazy acts and broken words my lips\nTo laughter somewhat mov\'d; when I began:\n\"Belacqua, now for thee I grieve no more.\nBut tell, why thou art seated upright there?\nWaitest thou escort to conduct thee hence?\nOr blame I only shine accustom\'d ways?\"\nThen he:  \"My brother, of what use to mount,\nWhen to my suffering would not let me pass\nThe bird of God, who at the portal sits?\nBehooves so long that heav\'n first bear me round\nWithout its limits, as in life it bore,\nBecause I to the end repentant Sighs\nDelay\'d, if prayer do not aid me first,\nThat riseth up from heart which lives in grace.\nWhat other kind avails, not heard in heaven?\"\'\n     Before me now the Poet up the mount\nAscending, cried:  \"Haste thee, for see the sun\nHas touch\'d the point meridian, and the night\nNow covers with her foot Marocco\'s shore.\"\n\n\n\nCANTO V\n\nNow had I left those spirits, and pursued\nThe steps of my Conductor, when beheld\nPointing the finger at me one exclaim\'d:\n\"See how it seems as if the light not shone\nFrom the left hand of him beneath, and he,\nAs living, seems to be led on.\"  Mine eyes\nI at that sound reverting, saw them gaze\nThrough wonder first at me, and then at me\nAnd the light broken underneath, by turns.\n\"Why are thy thoughts thus riveted?\"  my guide\nExclaim\'d, \"that thou hast slack\'d thy pace?  or how\nImports it thee, what thing is whisper\'d here?\nCome after me, and to their babblings leave\nThe crowd. Be as a tower, that, firmly set,\nShakes not its top for any blast that blows!\nHe, in whose bosom thought on thought shoots out,\nStill of his aim is wide, in that the one\nSicklies and wastes to nought the other\'s strength.\"\n     What other could I answer save \"I come?\"\nI said it, somewhat with that colour ting\'d\nWhich ofttimes pardon meriteth for man.\n     Meanwhile traverse along the hill there came,\nA little way before us, some who sang\nThe \"Miserere\" in responsive Strains.\nWhen they perceiv\'d that through my body I\nGave way not for the rays to pass, their song\nStraight to a long and hoarse exclaim they chang\'d;\nAnd two of them, in guise of messengers,\nRan on to meet us, and inquiring ask\'d:\nOf your condition we would gladly learn.\"\n     To them my guide.  \"Ye may return, and bear\nTidings to them who sent you, that his frame\nIs real flesh.  If, as I deem, to view\nHis shade they paus\'d, enough is answer\'d them.\nHim");
    strcat(expected_filecontent, " let them honour, they may prize him well.\"\n     Ne\'er saw I fiery vapours with such speed\nCut through the serene air at fall of night,\nNor August\'s clouds athwart the setting sun,\nThat upward these did not in shorter space\nReturn; and, there arriving, with the rest\nWheel back on us, as with loose rein a troop.\n     \"Many,\" exclaim\'d the bard, \"are these, who throng\nAround us: to petition thee they come.\nGo therefore on, and listen as thou go\'st.\"\n     \"O spirit!  who go\'st on to blessedness\nWith the same limbs, that clad thee at thy birth.\"\nShouting they came, \"a little rest thy step.\nLook if thou any one amongst our tribe\nHast e\'er beheld, that tidings of him there\nThou mayst report.  Ah, wherefore go\'st thou on?\nAh wherefore tarriest thou not?  We all\nBy violence died, and to our latest hour\nWere sinners, but then warn\'d by light from heav\'n,\nSo that, repenting and forgiving, we\nDid issue out of life at peace with God,\nWho with desire to see him fills our heart.\"\n     Then I:  \"The visages of all I scan\nYet none of ye remember.  But if aught,\nThat I can do, may please you, gentle spirits!\nSpeak; and I will perform it, by that peace,\nWhich on the steps of guide so excellent\nFollowing from world to world intent I seek.\"\n     In answer he began:  \"None here distrusts\nThy kindness, though not promis\'d with an oath;\nSo as the will fail not for want of power.\nWhence I, who sole before the others speak,\nEntreat thee, if thou ever see that land,\nWhich lies between Romagna and the realm\nOf Charles, that of thy courtesy thou pray\nThose who inhabit Fano, that for me\nTheir adorations duly be put up,\nBy which I may purge off my grievous sins.\nFrom thence I came.  But the deep passages,\nWhence issued out the blood wherein I dwelt,\nUpon my bosom in Antenor\'s land\nWere made, where to be more secure I thought.\nThe author of the deed was Este\'s prince,\nWho, more than right could warrant, with his wrath\nPursued me.  Had I towards Mira fled,\nWhen overta\'en at Oriaco, still\nMight I have breath\'d. But to the marsh I sped,\nAnd in the mire and rushes tangled there\nFell, and beheld my life-blood float the plain.\"\n     Then said another:  \"Ah! so may the wish,\nThat takes thee o\'er the mountain, be fulfill\'d,\nAs thou shalt graciously give aid to mine.\nOf Montefeltro I; Buonconte I:\nGiovanna nor none else have care for me,\nSorrowing with these I therefore go.\"  I thus:\n\"From Campaldino\'s field what force or chance\nDrew thee, that ne\'er thy sepulture was known?\"\n     \"Oh!\"  answer\'d he, \"at Casentino\'s foot\nA stream there courseth, nam\'d Archiano, sprung\nIn Apennine above the Hermit\'s seat.\nE\'en where its name is cancel\'d, there came I,\nPierc\'d in the heart, fleeing away on foot,\nAnd bloodying the plain.  Here sight and speech\nFail\'d me, and finishing with Mary\'s name\nI fell, and tenantless my flesh remain\'d.\nI will report the truth; which thou again0\nTell to the living.  Me God\'s angel took,\nWhilst he of hell exclaim\'d:  \"O thou from heav\'n!\nSay wherefore hast thou robb\'d me?  Thou of him\nTh\' eternal portion bear\'st with thee away\nFor one poor tear that he deprives me of.\nBut of the other, other rule I make.\"\n     \"Thou knowest how in the atmosphere collects\nThat vapour dank, returning into water,\nSoon as it mounts where cold condenses it.\nThat evil will, which in his intellect\nStill follows evil, came, and rais\'d the wind\nAnd smoky mist, by virtue of the power\nGiven by his nature.  Thence the valley, soon\nAs day was spent, he cover\'d o\'er with cloud\nFrom Pratomagno to the mountain range,\nAnd stretch\'d the sky above, so that the air\nImpregnate chang\'d to water.  Fell the rain,\nAnd to the fosses came all that the land\nContain\'d not; and, as mightiest streams are wont,\nTo the great river with such headlong sweep\nRush\'d, that nought stay\'d its course.  My stiffen\'d frame\nLaid at his mouth the fell Archiano found,\nAnd dash\'d it into Arno, from my breast\nLoos\'ning the cross, that of myself I made\nWhen overcome with pain.  He hurl\'d me on,\nAlong the banks and bottom of his course;\nThen in his muddy spoils encircling wrapt.\"\n     \"Ah!  when thou to th");
    strcat(expected_filecontent, "e world shalt be return\'d,\nAnd rested after thy long road,\" so spake\nNext the third spirit; \"then remember me.\nI once was Pia.  Sienna gave me life,\nMaremma took it from me.  That he knows,\nWho me with jewell\'d ring had first espous\'d.\"\n\n\n\nCANTO VI\n\nWhen from their game of dice men separate,\nHe, who hath lost, remains in sadness fix\'d,\nRevolving in his mind, what luckless throws\nHe cast: but meanwhile all the company\nGo with the other; one before him runs,\nAnd one behind his mantle twitches, one\nFast by his side bids him remember him.\nHe stops not; and each one, to whom his hand\nIs stretch\'d, well knows he bids him stand aside;\nAnd thus he from the press defends himself.\nE\'en such was I in that close-crowding throng;\nAnd turning so my face around to all,\nAnd promising, I \'scap\'d from it with pains.\n     Here of Arezzo him I saw, who fell\nBy Ghino\'s cruel arm; and him beside,\nWho in his chase was swallow\'d by the stream.\nHere Frederic Novello, with his hand\nStretch\'d forth, entreated; and of Pisa he,\nWho put the good Marzuco to such proof\nOf constancy.  Count Orso I beheld;\nAnd from its frame a soul dismiss\'d for spite\nAnd envy, as it said, but for no crime:\nI speak of Peter de la Brosse; and here,\nWhile she yet lives, that Lady of Brabant\nLet her beware; lest for so false a deed\nShe herd with worse than these. When I was freed\nFrom all those spirits, who pray\'d for others\' prayers\nTo hasten on their state of blessedness;\nStraight I began:  \"O thou, my luminary!\nIt seems expressly in thy text denied,\nThat heaven\'s supreme decree can never bend\nTo supplication; yet with this design\nDo these entreat.  Can then their hope be vain,\nOr is thy saying not to me reveal\'d?\"\n     He thus to me:  \"Both what I write is plain,\nAnd these deceiv\'d not in their hope, if well\nThy mind consider, that the sacred height\nOf judgment doth not stoop, because love\'s flame\nIn a short moment all fulfils, which he\nWho sojourns here, in right should satisfy.\nBesides, when I this point concluded thus,\nBy praying no defect could be supplied;\nBec");

                struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "WISH.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 10439, file);
                test_error(size == 10240, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 10240 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 10240);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 10240);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 14: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST14(void)
{
    // informacje o teście
    test_start(14, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(9688, 1);
                char expected_filecontent[9689] = "";

                strcat(expected_filecontent, "e?\nHe hath in sooth good cause for endless grief,\nWho, for the love of thing that lasteth not,\nDespoils himself forever of that love.\n     As oft along the still and pure serene,\nAt nightfall, glides a sudden trail of fire,\nAttracting with involuntary heed\nThe eye to follow it, erewhile at rest,\nAnd seems some star that shifted place in heav\'n,\nOnly that, whence it kindles, none is lost,\nAnd it is soon extinct; thus from the horn,\nThat on the dexter of the cross extends,\nDown to its foot, one luminary ran\nFrom mid the cluster shone there; yet no gem\nDropp\'d from its foil; and through the beamy list\nLike flame in alabaster, glow\'d its course.\n     So forward stretch\'d him (if of credence aught\nOur greater muse may claim) the pious ghost\nOf old Anchises, in the\' Elysian bower,\nWhen he perceiv\'d his son.  \"O thou, my blood!\nO most exceeding grace divine!  to whom,\nAs now to thee, hath twice the heav\'nly gate\nBeen e\'er unclos\'d?\" so spake the light; whence I\nTurn\'d me toward him; then unto my dame\nMy sight directed, and on either side\nAmazement waited me; for in her eyes\nWas lighted such a smile, I thought that mine\nHad div\'d unto the bottom of my grace\nAnd of my bliss in Paradise.  Forthwith\nTo hearing and to sight grateful alike,\nThe spirit to his proem added things\nI understood not, so profound he spake;\nYet not of choice but through necessity\nMysterious; for his high conception scar\'d\nBeyond the mark of mortals.  When the flight\nOf holy transport had so spent its rage,\nThat nearer to the level of our thought\nThe speech descended, the first sounds I heard\nWere, \"Best he thou, Triunal Deity!\nThat hast such favour in my seed vouchsaf\'d!\"\nThen follow\'d:  \"No unpleasant thirst, tho\' long,\nWhich took me reading in the sacred book,\nWhose leaves or white or dusky never change,\nThou hast allay\'d, my son, within this light,\nFrom whence my voice thou hear\'st; more thanks to her.\nWho for such lofty mounting has with plumes\nBegirt thee.  Thou dost deem thy thoughts to me\nFrom him transmitted, who is first of all,\nE\'en as all numbers ray from unity;\nAnd therefore dost not ask me who I am,\nOr why to thee more joyous I appear,\nThan any other in this gladsome throng.\nThe truth is as thou deem\'st; for in this hue\nBoth less and greater in that mirror look,\nIn which thy thoughts, or ere thou think\'st, are shown.\nBut, that the love, which keeps me wakeful ever,\nUrging with sacred thirst of sweet desire,\nMay be contended fully, let thy voice,\nFearless, and frank and jocund, utter forth\nThy will distinctly, utter forth the wish,\nWhereto my ready answer stands decreed.\"\n     I turn\'d me to Beatrice; and she heard\nEre I had spoken, smiling, an assent,\nThat to my will gave wings; and I began\n\"To each among your tribe, what time ye kenn\'d\nThe nature, in whom naught unequal dwells,\nWisdom and love were in one measure dealt;\nFor that they are so equal in the sun,\nFrom whence ye drew your radiance and your heat,\nAs makes all likeness scant.  But will and means,\nIn mortals, for the cause ye well discern,\nWith unlike wings are fledge.  A mortal I\nExperience inequality like this,\nAnd therefore give no thanks, but in the heart,\nFor thy paternal greeting.  This howe\'er\nI pray thee, living topaz!  that ingemm\'st\nThis precious jewel, let me hear thy name.\"\n     \"I am thy root, O leaf!  whom to expect\nEven, hath pleas\'d me:  \"thus the prompt reply\nPrefacing, next it added;  \"he, of whom\nThy kindred appellation comes, and who,\nThese hundred years and more, on its first ledge\nHath circuited the mountain, was my son\nAnd thy great grandsire.  Well befits, his long\nEndurance should he shorten\'d by thy deeds.\n     \"Florence, within her ancient limit-mark,\nWhich calls her still to matin prayers and noon,\nWas chaste and sober, and abode in peace.\nShe had no armlets and no head-tires then,\nNo purfled dames, no zone, that caught the eye\nMore than the person did.  Time was not yet,\nWhen at his daughter\'s birth the sire grew pale.\nFor fear the age and dowry should exceed\nOn each side just proportion.  House was none\nVoid of its family; nor yet had come\nHardanapalus, to");
    strcat(expected_filecontent, " exhibit feats\nOf chamber prowess.  Montemalo yet\nO\'er our suburban turret rose; as much\nTo be surpass in fall, as in its rising.\nI saw Bellincione Berti walk abroad\nIn leathern girdle and a clasp of bone;\nAnd, with no artful colouring on her cheeks,\nHis lady leave the glass.  The sons I saw\nOf Nerli and of Vecchio well content\nWith unrob\'d jerkin; and their good dames handling\nThe spindle and the flax; O happy they!\nEach sure of burial in her native land,\nAnd none left desolate a-bed for France!\nOne wak\'d to tend the cradle, hushing it\nWith sounds that lull\'d the parent\'s infancy:\nAnother, with her maidens, drawing off\nThe tresses from the distaff, lectur\'d them\nOld tales of Troy and Fesole and Rome.\nA Salterello and Cianghella we\nHad held as strange a marvel, as ye would\nA Cincinnatus or Cornelia now.\n     \"In such compos\'d and seemly fellowship,\nSuch faithful and such fair equality,\nIn so sweet household, Mary at my birth\nBestow\'d me, call\'d on with loud cries; and there\nIn your old baptistery, I was made\nChristian at once and Cacciaguida; as were\nMy brethren, Eliseo and Moronto.\n     \"From Valdipado came to me my spouse,\nAnd hence thy surname grew.  I follow\'d then\nThe Emperor Conrad; and his knighthood he\nDid gird on me; in such good part he took\nMy valiant service.  After him I went\nTo testify against that evil law,\nWhose people, by the shepherd\'s fault, possess\nYour right, usurping.  There, by that foul crew\nWas I releas\'d from the deceitful world,\nWhose base affection many a spirit soils,\nAnd from the martyrdom came to this peace.\"\n\n\n\nCANTO XVI\n\nO slight respect of man\'s nobility!\nI never shall account it marvelous,\nThat our infirm affection here below\nThou mov\'st to boasting, when I could not choose,\nE\'en in that region of unwarp\'d desire,\nIn heav\'n itself, but make my vaunt in thee!\nYet cloak thou art soon shorten\'d, for that time,\nUnless thou be eked out from day to day,\nGoes round thee with his shears.  Resuming then\nWith greeting such, as Rome, was first to bear,\nBut since hath disaccustom\'d I began;\nAnd Beatrice, that a little space\nWas sever\'d, smil\'d reminding me of her,\nWhose cough embolden\'d (as the story holds)\nTo first offence the doubting Guenever.\n     \"You are my sire,\" said I, \"you give me heart\nFreely to speak my thought: above myself\nYou raise me.  Through so many streams with joy\nMy soul is fill\'d, that gladness wells from it;\nSo that it bears the mighty tide, and bursts not\nSay then, my honour\'d stem!  what ancestors\nWhere those you sprang from, and what years were mark\'d\nIn your first childhood?  Tell me of the fold,\nThat hath Saint John for guardian, what was then\nIts state, and who in it were highest seated?\"\n     As embers, at the breathing of the wind,\nTheir flame enliven, so that light I saw\nShine at my blandishments; and, as it grew\nMore fair to look on, so with voice more sweet,\nYet not in this our modern phrase, forthwith\nIt answer\'d:  \"From the day, when it was said\n\' Hail Virgin!\' to the throes, by which my mother,\nWho now is sainted, lighten\'d her of me\nWhom she was heavy with, this fire had come,\nFive hundred fifty times and thrice, its beams\nTo reilumine underneath the foot\nOf its own lion.  They, of whom I sprang,\nAnd I, had there our birth-place, where the last\nPartition of our city first is reach\'d\nBy him, that runs her annual game.  Thus much\nSuffice of my forefathers: who they were,\nAnd whence they hither came, more honourable\nIt is to pass in silence than to tell.\nAll those, who in that time were there from Mars\nUntil the Baptist, fit to carry arms,\nWere but the fifth of them this day alive.\nBut then the citizen\'s blood, that now is mix\'d\nFrom Campi and Certaldo and Fighine,\nRan purely through the last mechanic\'s veins.\nO how much better were it, that these people\nWere neighbours to you, and that at Galluzzo\nAnd at Trespiano, ye should have your bound\'ry,\nThan to have them within, and bear the stench\nOf Aguglione\'s hind, and Signa\'s, him,\nThat hath his eye already keen for bart\'ring!\nHad not the people, which of all the world\nDegenerates most, been stepdame unto Caesar,\nBu");
    strcat(expected_filecontent, "t, as a mother, gracious to her son;\nSuch one, as hath become a Florentine,\nAnd trades and traffics, had been turn\'d adrift\nTo Simifonte, where his grandsire ply\'d\nThe beggar\'s craft.  The Conti were possess\'d\nOf Montemurlo still: the Cerchi still\nWere in Acone\'s parish; nor had haply\nFrom Valdigrieve past the Buondelmonte.\nThe city\'s malady hath ever source\nIn the confusion of its persons, as\nThe body\'s, in variety of food:\nAnd the blind bull falls with a steeper plunge,\nThan the blind lamb; and oftentimes one sword\nDoth more and better execution,\nThan five.  Mark Luni, Urbisaglia mark,\nHow they are gone, and after them how go\nChiusi and Sinigaglia; and \'t will seem\nNo longer new or strange to thee to hear,\nThat families fail, when cities have their end.\nAll things, that appertain t\' ye, like yourselves,\nAre mortal: but mortality in some\nYe mark not, they endure so long, and you\nPass by so suddenly.  And as the moon\nDoth, by the rolling of her heav\'nly sphere,\nHide and reveal the strand unceasingly;\nSo fortune deals with Florence.  Hence admire not\nAt what of them I tell thee, whose renown\nTime covers, the first Florentines.  I saw\nThe Ughi, Catilini and Filippi,\nThe Alberichi, Greci and Ormanni,\nNow in their wane, illustrious citizens:\nAnd great as ancient, of Sannella him,\nWith him of Arca saw, and Soldanieri\nAnd Ardinghi, and Bostichi.  At the poop,\nThat now is laden with new felony,\nSo cumb\'rous it may speedily sink the bark,\nThe Ravignani sat, of whom is sprung\nThe Co");

                struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "LEARN.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 10046, file);
                test_error(size == 9688, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 9688 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 9688);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 9688);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 15: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST15(void)
{
    // informacje o teście
    test_start(15, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(10313, 1);
                char expected_filecontent[10314] = "";

                strcat(expected_filecontent, "rtue guides not; that if aught of good\nMy gentle star, or something better gave me,\nI envy not myself the precious boon.\n     As in that season, when the sun least veils\nHis face that lightens all, what time the fly\nGives way to the shrill gnat, the peasant then\nUpon some cliff reclin\'d, beneath him sees\nFire-flies innumerous spangling o\'er the vale,\nVineyard or tilth, where his day-labour lies:\nWith flames so numberless throughout its space\nShone the eighth chasm, apparent, when the depth\nWas to my view expos\'d. As he, whose wrongs\nThe bears aveng\'d, at its departure saw\nElijah\'s chariot, when the steeds erect\nRais\'d their steep flight for heav\'n; his eyes meanwhile,\nStraining pursu\'d them, till the flame alone\nUpsoaring like a misty speck he kenn\'d;\nE\'en thus along the gulf moves every flame,\nA sinner so enfolded close in each,\nThat none exhibits token of the theft.\n     Upon the bridge I forward bent to look,\nAnd grasp\'d a flinty mass, or else had fall\'n,\nThough push\'d not from the height.  The guide, who mark d\nHow I did gaze attentive, thus began:\n\"Within these ardours are the spirits, each\nSwath\'d in confining fire.\"--\"Master, thy word,\"\nI answer\'d, \"hath assur\'d me; yet I deem\'d\nAlready of the truth, already wish\'d\nTo ask thee, who is in yon fire, that comes\nSo parted at the summit, as it seem\'d\nAscending from that funeral pile, where lay\nThe Theban brothers?\"  He replied:  \"Within\nUlysses there and Diomede endure\nTheir penal tortures, thus to vengeance now\nTogether hasting, as erewhile to wrath.\nThese in the flame with ceaseless groans deplore\nThe ambush of the horse, that open\'d wide\nA portal for that goodly seed to pass,\nWhich sow\'d imperial Rome; nor less the guile\nLament they, whence of her Achilles \'reft\nDeidamia yet in death complains.\nAnd there is rued the stratagem, that Troy\nOf her Palladium spoil\'d.\"--\"If they have power\nOf utt\'rance from within these sparks,\" said I,\n\"O master!  think my prayer a thousand fold\nIn repetition urg\'d, that thou vouchsafe\nTo pause, till here the horned flame arrive.\nSee, how toward it with desire I bend.\"\n     He thus:  \"Thy prayer is worthy of much praise,\nAnd I accept it therefore:  but do thou\nThy tongue refrain:  to question them be mine,\nFor I divine thy wish:  and they perchance,\nFor they were Greeks, might shun discourse with thee.\"\n     When there the flame had come, where time and place\nSeem\'d fitting to my guide, he thus began:\n\"O ye, who dwell two spirits in one fire!\nIf living I of you did merit aught,\nWhate\'er the measure were of that desert,\nWhen in the world my lofty strain I pour\'d,\nMove ye not on, till one of you unfold\nIn what clime death o\'ertook him self-destroy\'d.\"\n     Of the old flame forthwith the greater horn\nBegan to roll, murmuring, as a fire\nThat labours with the wind, then to and fro\nWagging the top, as a tongue uttering sounds,\nThrew out its voice, and spake:  \"When I escap\'d\nFrom Circe, who beyond a circling year\nHad held me near Caieta, by her charms,\nEre thus Aeneas yet had nam\'d the shore,\nNor fondness for my son, nor reverence\nOf my old father, nor return of love,\nThat should have crown\'d Penelope with joy,\nCould overcome in me the zeal I had\nT\' explore the world, and search the ways of life,\nMan\'s evil and his virtue.  Forth I sail\'d\nInto the deep illimitable main,\nWith but one bark, and the small faithful band\nThat yet cleav\'d to me.  As Iberia far,\nFar as Morocco either shore I saw,\nAnd the Sardinian and each isle beside\nWhich round that ocean bathes.  Tardy with age\nWere I and my companions, when we came\nTo the strait pass, where Hercules ordain\'d\nThe bound\'ries not to be o\'erstepp\'d by man.\nThe walls of Seville to my right I left,\nOn the\' other hand already Ceuta past.\n\"O brothers!\"  I began, \"who to the west\nThrough perils without number now have reach\'d,\nTo this the short remaining watch, that yet\nOur senses have to wake, refuse not proof\nOf the unpeopled world, following the track\nOf Phoebus. Call to mind from whence we sprang:\nYe were not form\'d to live the life of brutes\nBut virtue to pursue and knowledge high.\nWith these few wo");
    strcat(expected_filecontent, "rds I sharpen\'d for the voyage\nThe mind of my associates, that I then\nCould scarcely have withheld them.  To the dawn\nOur poop we turn\'d, and for the witless flight\nMade our oars wings, still gaining on the left.\nEach star of the\' other pole night now beheld,\nAnd ours so low, that from the ocean-floor\nIt rose not.  Five times re-illum\'d, as oft\nVanish\'d the light from underneath the moon\nSince the deep way we enter\'d, when from far\nAppear\'d a mountain dim, loftiest methought\nOf all I e\'er beheld.  Joy seiz\'d us straight,\nBut soon to mourning changed.  From the new land\nA whirlwind sprung, and at her foremost side\nDid strike the vessel.  Thrice it whirl\'d her round\nWith all the waves, the fourth time lifted up\nThe poop, and sank the prow: so fate decreed:\nAnd over us the booming billow clos\'d.\"\n\n\n\nCANTO XXVII\n\nNOW upward rose the flame, and still\'d its light\nTo speak no more, and now pass\'d on with leave\nFrom the mild poet gain\'d, when following came\nAnother, from whose top a sound confus\'d,\nForth issuing, drew our eyes that way to look.\n     As the Sicilian bull, that rightfully\nHis cries first echoed, who had shap\'d its mould,\nDid so rebellow, with the voice of him\nTormented, that the brazen monster seem\'d\nPierc\'d through with pain; thus while no way they found\nNor avenue immediate through the flame,\nInto its language turn\'d the dismal words:\nBut soon as they had won their passage forth,\nUp from the point, which vibrating obey\'d\nTheir motion at the tongue, these sounds we heard:\n\"O thou!  to whom I now direct my voice!\nThat lately didst exclaim in Lombard phrase,\n     Depart thou, I solicit thee no more,\'\nThough somewhat tardy I perchance arrive\nLet it not irk thee here to pause awhile,\nAnd with me parley:  lo! it irks not me\nAnd yet I burn.  If but e\'en now thou fall\ninto this blind world, from that pleasant land\nOf Latium, whence I draw my sum of guilt,\nTell me if those, who in Romagna dwell,\nHave peace or war.  For of the mountains there\nWas I, betwixt Urbino and the height,\nWhence Tyber first unlocks his mighty flood.\"\n     Leaning I listen\'d yet with heedful ear,\nWhen, as he touch\'d my side, the leader thus:\n\"Speak thou: he is a Latian.\"  My reply\nWas ready, and I spake without delay:\n     \"O spirit!  who art hidden here below!\nNever was thy Romagna without war\nIn her proud tyrants\' bosoms, nor is now:\nBut open war there left I none.  The state,\nRavenna hath maintain\'d this many a year,\nIs steadfast.  There Polenta\'s eagle broods,\nAnd in his broad circumference of plume\nO\'ershadows Cervia. The green talons grasp\nThe land, that stood erewhile the proof so long,\nAnd pil\'d in bloody heap the host of France.\n     \"The\' old mastiff of Verruchio and the young,\nThat tore Montagna in their wrath, still make,\nWhere they are wont, an augre of their fangs.\n     \"Lamone\'s city and Santerno\'s range\nUnder the lion of the snowy lair.\nInconstant partisan! that changeth sides,\nOr ever summer yields to winter\'s frost.\nAnd she, whose flank is wash\'d of Savio\'s wave,\nAs \'twixt the level and the steep she lies,\nLives so \'twixt tyrant power and liberty.\n     \"Now tell us, I entreat thee, who art thou?\nBe not more hard than others.  In the world,\nSo may thy name still rear its forehead high.\"\n     Then roar\'d awhile the fire, its sharpen\'d point\nOn either side wav\'d, and thus breath\'d at last:\n\"If I did think, my answer were to one,\nWho ever could return unto the world,\nThis flame should rest unshaken.  But since ne\'er,\nIf true be told me, any from this depth\nHas found his upward way, I answer thee,\nNor fear lest infamy record the words.\n     \"A man of arms at first, I cloth\'d me then\nIn good Saint Francis\' girdle, hoping so\nT\' have made amends.  And certainly my hope\nHad fail\'d not, but that he, whom curses light on,\nThe\' high priest again seduc\'d me into sin.\nAnd how and wherefore listen while I tell.\nLong as this spirit mov\'d the bones and pulp\nMy mother gave me, less my deeds bespake\nThe nature of the lion than the fox.\nAll ways of winding subtlety I knew,\nAnd with such art conducted, that the sound\nReach\'d the world\'s limit.  Soon ");
    strcat(expected_filecontent, "as to that part\nOf life I found me come, when each behoves\nTo lower sails and gather in the lines;\nThat which before had pleased me then I rued,\nAnd to repentance and confession turn\'d;\nWretch that I was! and well it had bested me!\nThe chief of the new Pharisees meantime,\nWaging his warfare near the Lateran,\nNot with the Saracens or Jews (his foes\nAll Christians were, nor against Acre one\nHad fought, nor traffic\'d in the Soldan\'s land),\nHe his great charge nor sacred ministry\nIn himself, rev\'renc\'d, nor in me that cord,\nWhich us\'d to mark with leanness whom it girded.\nAs in Socrate, Constantine besought\nTo cure his leprosy Sylvester\'s aid,\nSo me to cure the fever of his pride\nThis man besought: my counsel to that end\nHe ask\'d:  and I was silent:  for his words\nSeem\'d drunken:  but forthwith he thus resum\'d:\n\"From thy heart banish fear:  of all offence\nI hitherto absolve thee.  In return,\nTeach me my purpose so to execute,\nThat Penestrino cumber earth no more.\nHeav\'n, as thou knowest, I have power to shut\nAnd open:  and the keys are therefore twain,\nThe which my predecessor meanly priz\'d.\"\n     Then, yielding to the forceful arguments,\nOf silence as more perilous I deem\'d,\nAnd answer\'d:  \"Father! since thou washest me\nClear of that guilt wherein I now must fall,\nLarge promise with performance scant, be sure,\nShall make thee triumph in thy lofty seat.\"\n     \"When I was number\'d with the dead, then came\nSaint Francis for me; but a cherub dark\nHe met, who cried: \"\'Wrong me not; he is mine,\nAnd must below to join the wretched crew,\nFor the deceitful counsel which he gave.\nE\'er since I watch\'d him, hov\'ring at his hair,\nNo power can the impenitent absolve;\nNor to repent and will at once consist,\nBy contradiction absolute forbid.\"\nOh mis\'ry! how I shook myself, when he\nSeiz\'d me, and cried, \"Thou haply thought\'st me not\nA disputant in logic so exact.\"\nTo Minos down he bore me, and the judge\nTwin\'d eight times round his callous back the tail,\nWhich biting with excess of rage, he spake:\n\"This is a guilty soul, that in the fire\nMust vanish.\'  Hence perdition-doom\'d I rove\nA prey to rankling sorro");

                struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "DRINK.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 10485, file);
                test_error(size == 10313, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 10313 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 10313);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 10313);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 16: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST16(void)
{
    // informacje o teście
    test_start(16, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(1544, 1);
                char expected_filecontent[1545] = "";

                strcat(expected_filecontent, "males to\ndeath.\n\nv. 120.  Alessio.]  Alessio, of an ancient and considerable\nfamily in Lucca, called the Interminei.\n\nv. 130.  Thais.]  He alludes to that passage in the Eunuchus of\nTerence where Thraso asks if Thais was obliged to him for the\npresent he had sent her, and Gnatho replies, that she had\nexpressed her obligation in the most forcible terms.\n        T.  Magnas vero agere gratias Thais mihi?\n        G.  Ingentes.\n               Eun. a. iii. s. i.\n\nCANTO XIX\n\nv. 18.  Saint John\'s fair dome.]  The apertures in the  rock were\nof the same dimensions as the fonts of St. John the Baptist at\nFlorence, one of which, Dante says he had broken, to rescue a\nchild  that was playing near and fell in. He intimates that the\nmotive of his  breaking the font had been maliciously represented\nby his enemies.\n\nv. 55.  O Boniface!]  The spirit mistakes Dante for  Boniface\nVIII. who was then alive, and who he did not expect would have\narrived so soon, in consequence, as it should seem, of a\nprophecy, which  predicted the death of that Pope at a later\nperiod. Boniface died in  1303.\n\nv. 58.  In guile.]  \"Thou didst presume to arrive by fraudulent\nmeans at the papal power, and afterwards to abuse it.\"\n\nv. 71.  In the mighty mantle I was rob\'d.]  Nicholas III, of the\nOrsini family, whom the poet therefore calls \"figliuol dell\'\norsa,\" \"son of the she-bear.\"  He died in 1281.\n\nv. 86.  From forth the west, a shepherd without law.]   Bertrand\nde Got Archbishop of Bordeaux, who succeeded to the pontificate\nin 1305, and assumed the title of");

                struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "COME");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 1670, file);
                test_error(size == 1544, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 1544 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 1544);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 1544);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 17: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST17(void)
{
    // informacje o teście
    test_start(17, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(12521, 1);
                char expected_filecontent[12522] = "";

                strcat(expected_filecontent, "h, conjur\'d by fell\nErictho, sorceress, who compell\'d the shades\nBack to their bodies.  No long space my flesh\nWas naked of me, when within these walls\nShe made me enter, to draw forth a spirit\nFrom out of Judas\' circle.  Lowest place\nIs that of all, obscurest, and remov\'d\nFarthest from heav\'n\'s all-circling orb.  The road\nFull well I know:  thou therefore rest secure.\nThat lake, the noisome stench exhaling, round\nThe city\' of grief encompasses, which now\nWe may not enter without rage.\"  Yet more\nHe added:  but I hold it not in mind,\nFor that mine eye toward the lofty tower\nHad drawn me wholly, to its burning top.\nWhere in an instant I beheld uprisen\nAt once three hellish furies stain\'d with blood:\nIn limb and motion feminine they seem\'d;\nAround them greenest hydras twisting roll\'d\nTheir volumes; adders and cerastes crept\nInstead of hair, and their fierce temples bound.\n     He knowing well the miserable hags\nWho tend the queen of endless woe, thus spake:\n\"Mark thou each dire Erinnys. To the left\nThis is Megaera; on the right hand she,\nWho wails, Alecto; and Tisiphone\nI\' th\' midst.\"  This said, in silence he remain\'d\nTheir breast they each one clawing tore; themselves\nSmote with their palms, and such shrill clamour rais\'d,\nThat to the bard I clung, suspicion-bound.\n\"Hasten Medusa: so to adamant\nHim shall we change;\" all looking down exclaim\'d.\n\"E\'en when by Theseus\' might assail\'d, we took\nNo ill revenge.\"  \"Turn thyself round, and keep\nThy count\'nance hid; for if the Gorgon dire\nBe shown, and thou shouldst view it, thy return\nUpwards would be for ever lost.\"  This said,\nHimself my gentle master turn\'d me round,\nNor trusted he my hands, but with his own\nHe also hid me.  Ye of intellect\nSound and entire, mark well the lore conceal\'d\nUnder close texture of the mystic strain!\n     And now there came o\'er the perturbed waves\nLoud-crashing, terrible, a sound that made\nEither shore tremble, as if of a wind\nImpetuous, from conflicting vapours sprung,\nThat \'gainst some forest driving all its might,\nPlucks off the branches, beats them down and hurls\nAfar; then onward passing proudly sweeps\nIts whirlwind rage, while beasts and shepherds fly.\n     Mine eyes he loos\'d, and spake: \"And now direct\nThy visual nerve along that ancient foam,\nThere, thickest where the smoke ascends.\" As frogs\nBefore their foe the serpent, through the wave\nPly swiftly all, till at the ground each one\nLies on a heap; more than a thousand spirits\nDestroy\'d, so saw I fleeing before one\nWho pass\'d with unwet feet the Stygian sound.\nHe, from his face removing the gross air,\nOft his left hand forth stretch\'d, and seem\'d alone\nBy that annoyance wearied.  I perceiv\'d\nThat he was sent from heav\'n, and to my guide\nTurn\'d me, who signal made that I should stand\nQuiet, and bend to him. Ah me!  how full\nOf noble anger seem\'d he!  To the gate\nHe came, and with his wand touch\'d it, whereat\nOpen without impediment it flew.\n     \"Outcasts of heav\'n!  O abject race and scorn\'d!\"\nBegan he on the horrid grunsel standing,\n\"Whence doth this wild excess of insolence\nLodge in you? wherefore kick you \'gainst that will\nNe\'er frustrate of its end, and which so oft\nHath laid on you enforcement of your pangs?\nWhat profits at the fays to but the horn?\nYour Cerberus, if ye remember, hence\nBears still, peel\'d of their hair, his throat and maw.\"\n     This said, he turn\'d back o\'er the filthy way,\nAnd syllable to us spake none, but wore\nThe semblance of a man by other care\nBeset, and keenly press\'d, than thought of him\nWho in his presence stands.  Then we our steps\nToward that territory mov\'d, secure\nAfter the hallow\'d words.  We unoppos\'d\nThere enter\'d; and my mind eager to learn\nWhat state a fortress like to that might hold,\nI soon as enter\'d throw mine eye around,\nAnd see on every part wide-stretching space\nReplete with bitter pain and torment ill.\n     As where Rhone stagnates on the plains of Arles,\nOr as at Pola, near Quarnaro\'s gulf,\nThat closes Italy and laves her bounds,\nThe place is all thick spread with sepulchres;\nSo was it here, save what in horror here\nExcell\'d:  for \'midst ");
    strcat(expected_filecontent, "the graves were scattered flames,\nWherewith intensely all throughout they burn\'d,\nThat iron for no craft there hotter needs.\n     Their lids all hung suspended, and beneath\nFrom them forth issu\'d lamentable moans,\nSuch as the sad and tortur\'d well might raise.\n     I thus:  \"Master! say who are these, interr\'d\nWithin these vaults, of whom distinct we hear\nThe dolorous sighs?\"  He answer thus return\'d:\n     \"The arch-heretics are here, accompanied\nBy every sect their followers; and much more,\nThan thou believest, tombs are freighted:  like\nWith like is buried; and the monuments\nAre different in degrees of heat. \"This said,\nHe to the right hand turning, on we pass\'d\nBetwixt the afflicted and the ramparts high.\n\n\n\nCANTO X\n\nNOW by a secret pathway we proceed,\nBetween the walls, that hem the region round,\nAnd the tormented souls:  my master first,\nI close behind his steps.  \"Virtue supreme!\"\nI thus began; \"who through these ample orbs\nIn circuit lead\'st me, even as thou will\'st,\nSpeak thou, and satisfy my wish.  May those,\nWho lie within these sepulchres, be seen?\nAlready all the lids are rais\'d, and none\nO\'er them keeps watch.\"  He thus in answer spake\n\"They shall be closed all, what-time they here\nFrom Josaphat return\'d shall come, and bring\nTheir bodies, which above they now have left.\nThe cemetery on this part obtain\nWith Epicurus all his followers,\nWho with the body make the spirit die.\nHere therefore satisfaction shall be soon\nBoth to the question ask\'d, and to the wish,\nWhich thou conceal\'st in silence.\"  I replied:\n\"I keep not, guide belov\'d! from thee my heart\nSecreted, but to shun vain length of words,\nA lesson erewhile taught me by thyself.\"\n     \"O Tuscan! thou who through the city of fire\nAlive art passing, so discreet of speech!\nHere please thee stay awhile. Thy utterance\nDeclares the place of thy nativity\nTo be that noble land, with which perchance\nI too severely dealt.\"  Sudden that sound\nForth issu\'d from a vault, whereat in fear\nI somewhat closer to my leader\'s side\nApproaching, he thus spake:  \"What dost thou?  Turn.\nLo, Farinata, there! who hath himself\nUplifted:  from his girdle upwards all\nExpos\'d behold him.\"  On his face was mine\nAlready fix\'d; his breast and forehead there\nErecting, seem\'d as in high scorn he held\nE\'en hell.  Between the sepulchres to him\nMy guide thrust me with fearless hands and prompt,\nThis warning added:  \"See thy words be clear!\"\n     He, soon as there I stood at the tomb\'s foot,\nEy\'d me a space, then in disdainful mood\nAddress\'d me:  \"Say, what ancestors were thine?\"\n     I, willing to obey him, straight reveal\'d\nThe whole, nor kept back aught: whence he, his brow\nSomewhat uplifting, cried:  \"Fiercely were they\nAdverse to me, my party, and the blood\nFrom whence I sprang:  twice therefore I abroad\nScatter\'d them.\"  \"Though driv\'n out, yet they each time\nFrom all parts,\" answer\'d I, \"return\'d; an art\nWhich yours have shown, they are not skill\'d to learn.\"\n     Then, peering forth from the unclosed jaw,\nRose from his side a shade, high as the chin,\nLeaning, methought, upon its knees uprais\'d.\nIt look\'d around, as eager to explore\nIf there were other with me; but perceiving\nThat fond imagination quench\'d, with tears\nThus spake:  \"If thou through this blind prison go\'st.\nLed by thy lofty genius and profound,\nWhere is my son? and wherefore not with thee?\"\n     I straight replied:  \"Not of myself I come,\nBy him, who there expects me, through this clime\nConducted, whom perchance Guido thy son\nHad in contempt.\"  Already had his words\nAnd mode of punishment read me his name,\nWhence I so fully answer\'d.  He at once\nExclaim\'d, up starting, \"How! said\'st thou he HAD?\nNo longer lives he?  Strikes not on his eye\nThe blessed daylight?\"  Then of some delay\nI made ere my reply aware, down fell\nSupine, not after forth appear\'d he more.\n     Meanwhile the other, great of soul, near whom\nI yet was station\'d, chang\'d not count\'nance stern,\nNor mov\'d the neck, nor bent his ribbed side.\n\"And if,\" continuing the first discourse,\n\"They in this art,\" he cried, \"small skill have shown,\nThat doth torment m");
    strcat(expected_filecontent, "e more e\'en than this bed.\nBut not yet fifty times shall be relum\'d\nHer aspect, who reigns here Queen of this realm,\nEre thou shalt know the full weight of that art.\nSo to the pleasant world mayst thou return,\nAs thou shalt tell me, why in all their laws,\nAgainst my kin this people is so fell?\"\n     \"The slaughter and great havoc,\" I replied,\n\"That colour\'d Arbia\'s flood with crimson stain--\nTo these impute, that in our hallow\'d dome\nSuch orisons ascend.\"  Sighing he shook\nThe head, then thus resum\'d:  \"In that affray\nI stood not singly, nor without just cause\nAssuredly should with the rest have stirr\'d;\nBut singly there I stood, when by consent\nOf all, Florence had to the ground been raz\'d,\nThe one who openly forbad the deed.\"\n     \"So may thy lineage find at last repose,\"\nI thus adjur\'d him, \"as thou solve this knot,\nWhich now involves my mind.  If right I hear,\nYe seem to view beforehand, that which time\nLeads with him, of the present uninform\'d.\"\n     \"We view, as one who hath an evil sight,\"\nHe answer\'d, \"plainly, objects far remote:\nSo much of his large spendour yet imparts\nThe\' Almighty Ruler; but when they approach\nOr actually exist, our intellect\nThen wholly fails, nor of your human state\nExcept what others bring us know we aught.\nHence therefore mayst thou understand, that all\nOur knowledge in that instant shall expire,\nWhen on futurity the portals close.\"\n     Then conscious of my fault, and by remorse\nSmitten, I added thus:  \"Now shalt thou say\nTo him there fallen, that his offspring still\nIs to the living join\'d; and bid him know,\nThat if from answer silent I abstain\'d,\n\'Twas that my thought was occupied intent\nUpon that error, which thy help hath solv\'d.\"\n     But now my master summoning me back\nI heard, and with more eager haste besought\nThe spirit to inform me, who with him\nPartook his lot.  He answer thus return\'d:\n     \"More than a thousand with me here are laid\nWithin is Frederick, second of that name,\nAnd the Lord Cardinal, and of the rest\nI speak not.\"  He, this said, from sight withdrew.\nBut I my steps towards the ancient bard\nReverting, ruminated on the words\nBetokening me such ill.  Onward he mov\'d,\nAnd thus in going question\'d:  \"Whence the\' amaze\nThat holds thy senses wrapt?\"  I satisfied\nThe\' inquiry, and the sage enjoin\'d me straight:\n\"Let thy safe memory store what thou hast heard\nTo thee importing harm; and note thou this,\"\nWith his rais\'d finger bidding me take heed,\n     \"When thou shalt stand before her gracious beam,\nWhose bright eye all surveys, she of thy life\nThe future tenour will to thee unfold.\"\n     Forthwith he to the left hand turn\'d his feet:\nWe left the wall, and tow\'rds the middle space\nWent by a path, that to a valley strikes;\nWhich e\'en thus high exhal\'d its noisome steam.\n\n\n\nCANTO XI\n\nUPON the utmost verge of a high bank,\nBy craggy rocks environ\'d round, we came,\nWhere woes beneath more cruel yet were stow\'d:\nAnd here to shun the horrible excess\nOf fetid exhalation, upward cast\nFrom the profound abyss, behind the lid\nOf a great monument we stood retir\'d,\nWhereon this scroll I mark\'d:  \"I have in charge\nPope Anastasius, whom Photinus drew\nFrom the right path.--Ere our descent behooves\nWe make delay, that somewhat first the sense,\nTo the dire breath accustom\'d, afterward\nRegard it not.\"  My master thus; to whom\nAnswering I spake:  \"Some compensation find\nThat the time past not wholly lost.\"  He then:\n\"Lo! how my thoughts e\'en to thy wishes tend!\nMy son! within these rocks,\" he thus began,\n\"Are three close circles in gradation plac\'d,\nAs these which now thou leav\'st. Each one is full\nOf spirits accurs\'d; but that the sight alone\nHereafter may suffice thee, listen how\nAnd for what cause in durance they abide.\n     \"Of all malicious act abhorr\'d in heaven,\nThe end is injury; and all such end\nEither by force or fraud works other\'s woe\nBut fraud, because of man peculiar evil,\nTo God is more displeasing; and beneath\nThe fraudulent are therefore doom\'d to\' endure\nSeverer pang.  The violent occupy\nAll the first circle; and because to force\nThree persons are obnoxious, in three roun");
    strcat(expected_filecontent, "ds\nHach within other sep\'rate is it fram\'d.\nTo God, his neighbour, and himself, by man\nForce may be offer\'d; to himself I say\nAnd his possessions, as thou soon shalt hear\nAt full.  Death, violent death, and painful wounds\nUpon his neigh");

                struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "SEVEN.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 12766, file);
                test_error(size == 12521, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 12521 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 12521);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 12521);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 18: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST18(void)
{
    // informacje o teście
    test_start(18, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(7471, 1);
                char expected_filecontent[7472] = "";

                strcat(expected_filecontent, "t it out of the\nkingdom, because it was the land of the church, and that it was\nburied by the river Verde, on the borders of the kingdom and of\nCarapagna. this, however, we do not affirm.\"  G. Villani, Hist.\nl. vii.  c. 9.\n\nv. 111.  Costanza.]  See Paradise Canto III.  v. 121.\n\nv. 112.  My fair daughter.]  Costanza, the daughter of Manfredi,\nand wife of Peter III.  King of Arragon, by whom she was mother\nto  Frederick, King of Sicily and James, King of Arragon With the\nlatter of these she was at Rome 1296. See G. Villani, 1. viii. c.\n18. and notes to Canto VII.\n\nv. 122.  Clement.]  Pope Clement IV.\n\nv. 127.  The stream of Verde.]  A river near Ascoli, that falls\ninto he Toronto. The \"xtinguished lights \" formed part of the\nceremony t the interment of one excommunicated.\n\nv. 130.  Hope.]\nMentre che la speranza ha fior del verde.\nTasso, G. L. c. xix. st. 53.\n--infin che verde e fior di speme.\n\nCANTO IV\n\nv. 1.  When.] It must be owned the beginning of this Canto is\nsomewhat obscure. Bellutello refers, for an elucidation of it, to\nthe reasoning of Statius in the twenty-fifth canto. Perhaps some\nillustration may be derived from the following, passage in\nSouth\'s Sermons, in which I have ventured to supply the words\nbetween crotchets that seemed to be wanting to complete\nthe sense. Now whether these three, judgement memory, and\ninvention, are three distinct things, both in being distinguished\nfrom one another, and likewise from the substance of the soul\nitself, considered without any such faculties, (or whether the\nsoul be one individual substance) but only receiving these\nseveral denominations rom the several respects arising from the\nseveral actions exerted immediately by itself upon several\nobjects, or several qualities of the same object, I say whether\nof these it is, is not easy to decide, and it is well that it is\nnot necessary Aquinas, and most with him, affirm the former, and\nScotus with his followers the latter.\" Vol. iv. Serm. 1.\n\nv. 23.  Sanleo.]  A fortress on the summit of Montefeltro.\n\nv. 24.  Noli.]  In the Genoese territory, between Finale and\nSavona.\n\nv. 25.  Bismantua.]  A steep mountain in the territory of Reggio.\n\nv. 55.  From the left.]  Vellutello observes an imitation of\nLucan in this passage:\n\nIgnotum vobis, Arabes, venistis in orbem,\nUmbras mirati nemornm non ire sinistras.\nPhars.  s. 1.  iii. 248\n\nv. 69 Thou wilt see.]  \"If you consider that this mountain of\nPurgatory and that of Sion are antipodal to each other, you will\nperceive that the sun must rise on opposite sides of the\nrespective eminences.\"\n\nv. 119.  Belacqua.]  Concerning this man, the commentators afford\nno information.\n\nCANTO V\n\nv. 14.  Be as a tower.]  Sta  ome torre ferma\n\nBerni, Orl.  Inn. 1. 1. c. xvi. st. 48:\nIn quei due piedi sta fermo il gigante\nCom\' una torre in mezzo d\'un castello.\n\nAnd Milton, P. L. b. i.  591.\nStood like a tower.\n\nv. 36.  Ne\'er saw I fiery vapours.]  Imitated by Tasso, G. L, c.\nxix t. 62:\nTal suol fendendo liquido sereno\nStella cader della gran madre in seno.\n\nAnd by Milton, P. L. b. iv. 558:\nSwift as a shooting star\nIn autumn thwarts the night, when vapours fir\'d\nImpress the air.\n\nv. 67.  That land.]  The Marca d\'Ancona, between Romagna and\nApulia, the kingdom of Charles of Anjou.\n\nv. 76.  From thence I came.]  Giacopo del Cassero, a citizen of\nFano who having spoken ill of Azzo da Este, Marquis of Ferrara,\nwas by his orders put to death.  Giacopo, was overtaken by the\nassassins at Oriaco a place near the Brenta, from whence, if he\nhad fled towards Mira, higher up on that river, instead of making\nfor the marsh on the sea shore, he might have escaped.\n\nv. 75.  Antenor\'s land.]  The city of Padua, said to be founded\nby Antenor.\n\nv. 87.  Of Montefeltro I.]  Buonconte (son of Guido da\nMontefeltro, whom we have had in the twenty-seventh Canto of\nHell) fell in the battle of Campaldino (1289), fighting on the\nside of the Aretini.\n\nv. 88.  Giovanna.]  Either the wife, or kinswoman, of Buonconte.\n\nv. 91.  The hermit\'s seat.]  The hermitage of Camaldoli.\n\nv. 95.  Where its name is cancel\'d.]  That is, between Bibbiena\na");
    strcat(expected_filecontent, "nd Poppi, where the Archiano falls into the Arno.\n\nv. 115.  From Pratomagno to the mountain range.]  From Pratomagno\nnow called Prato Vecchio (which divides the Valdarno from\nCasentino) as far as to the Apennine.\n\nv. 131.  Pia.] She is said to have been a Siennese lady, of the\nfamily of Tolommei, secretly made away with by her husband, Nello\ndella Pietra, of the same city, in Maremma, where he had some\npossessions.\n\nCANTO VI\n\nv. 14.  Of Arezzo him.]  Benincasa of Arezzo, eminent for his\nskill in jurisprudence, who, having condemned to death Turrino da\nTurrita brother of Ghino di Tacco, for his robberies in Maremma,\nwas murdered by Ghino, in an apartment of his own house, in the\npresence of many witnesses. Ghino was not only suffered to escape\nin safety, but (as the commentators inform us) obtained so high a\nreputation by the liberality with which he was accustomed to\ndispense the fruits of his plunder, and treated those who fell\ninto his hands with so much courtesy, that he was afterwards\ninvited to Rome, and knighted by Boniface VIII. A story is told\nof him by Boccaccio, G. x. N. 2.\n\nv. 15.  Him beside.]  Ciacco de\' Tariatti of Arezzo.  He is said\nto have been carried by his horse into the Arno, and there\ndrowned, while he was in pursuit of certain of his enemies.\n\nv. 17.  Frederic Novello.]  Son of the Conte Guido da Battifolle,\nand slain by one of the family of Bostoli.\n\nv. 18.  Of Pisa he.]  Farinata de\' Scornigiani of Pisa.  His\nfather Marzuco, who had entered the order of the Frati Minori, so\nentirely overcame the feelings of resentment, that he even kissed\nthe hands of the slayer of his son, and, as he was following the\nfuneral, exhorted his kinsmen to reconciliation.\n\nv. 20.  Count 0rso.]  Son of Napoleone da Cerbaia, slain by\nAlberto da Mangona, his uncle.\n\nv. 23.  Peter de la Brosse.]  Secretary of Philip III  of France.\nThe courtiers, envying the high place which he held in the king\'s\nfavour, prevailed on Mary of Brabant to charge him falsely with\nan attempt upon her person for which supposed crime he suffered\ndeath. So say the Italian commentators.  Henault represents the\nmatter very differently: \"Pierre de la Brosse, formerly barber to\nSt. Louis, afterwards the favorite of Philip, fearing the too\ngreat attachment of the king for his wife Mary, accuses this\nprincess of having poisoned Louis, eldest son of Philip, by his\nfirst marriage. This calumny is discovered by a nun of Nivelle in\nFlanders.  La Brosse is hung.\" Abrege Chron. t. 275, &c.\n\nv. 30.  In thy text.]  He refers to Virgil, Aen. 1, vi.  376.\nDesine fata deum flecti sperare precando, 37. The sacred height\nOf judgment. Shakespeare, Measure for Measure, a. ii. s. 2.\nIf he, which is the top of judgment\n\nv. 66.  Eyeing us as a lion on his watch.]\nA guisa di Leon quando si posa.\nA line taken by Tasso, G.  L. c. x. st. 56.\n\nv. 76.  Sordello.]  The history of Sordello\'s life is wrapt in\nthe obscurity of romance.  That he distinguished himself by his\nskill in Provencal poetry is certain. It is probable that he was\nborn towards the end of the twelfth, and died about the middle of\nthe succeeding century.  Tiraboschi has taken much pains to sift\nall the notices he could collect relating to him.  Honourable\nmention of his name is made by our Poet in the Treatise de Vulg.\nEloq.  1. i. c. 15.\n\nv. 76.  Thou inn of grief.]\nThou most beauteous inn\nWhy should h");

                struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "QUESTION.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 7658, file);
                test_error(size == 7471, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 7471 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 7471);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 7471);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 19: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST19(void)
{
    // informacje o teście
    test_start(19, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char *filecontent = (char *)calloc(11807, 1);
                char expected_filecontent[11808] = "";

                strcat(expected_filecontent, "ucca: and that face beyond him, pierc\'d\nUnto a leaner fineness than the rest,\nHad keeping of the church: he was of Tours,\nAnd purges by wan abstinence away\nBolsena\'s eels and cups of muscadel.\"\n     He show\'d me many others, one by one,\nAnd all, as they were nam\'d, seem\'d well content;\nFor no dark gesture I discern\'d in any.\nI saw through hunger Ubaldino grind\nHis teeth on emptiness; and Boniface,\nThat wav\'d the crozier o\'er a num\'rous flock.\nI saw the Marquis, who tad time erewhile\nTo swill at Forli with less drought, yet so\nWas one ne\'er sated.  I howe\'er, like him,\nThat gazing \'midst a crowd, singles out one,\nSo singled him of Lucca; for methought\nWas none amongst them took such note of me.\nSomewhat I heard him whisper of Gentucca:\nThe sound was indistinct, and murmur\'d there,\nWhere justice, that so strips them, fix\'d her sting.\n     \"Spirit!\" said I, \"it seems as thou wouldst fain\nSpeak with me.  Let me hear thee.  Mutual wish\nTo converse prompts, which let us both indulge.\"\n     He, answ\'ring, straight began: \"Woman is born,\nWhose brow no wimple shades yet, that shall make\nMy city please thee, blame it as they may.\nGo then with this forewarning.  If aught false\nMy whisper too implied, th\' event shall tell\nBut say, if of a  truth I see the man\nOf that new lay th\' inventor, which begins\nWith \'Ladies, ye that con the lore of love\'.\"\n     To whom I thus:  \"Count of me but as one\nWho am the scribe of love; that, when he breathes,\nTake up my pen, and, as he dictates, write.\"\n     \"Brother!\" said he, \"the hind\'rance which once held\nThe notary with Guittone and myself,\nShort of that new and sweeter style I hear,\nIs now disclos\'d.  I see how ye your plumes\nStretch, as th\' inditer guides them; which, no question,\nOurs did not.  He that seeks a grace beyond,\nSees not the distance parts one style from other.\"\nAnd, as contented, here he held his peace.\n     Like as the bird, that winter near the Nile,\nIn squared regiment direct their course,\nThen stretch themselves in file for speedier flight;\nThus all the tribe of spirits, as they turn\'d\nTheir visage, faster deaf, nimble alike\nThrough leanness and desire.  And as a man,\nTir\'d With the motion of a trotting steed,\nSlacks pace, and stays behind his company,\nTill his o\'erbreathed lungs keep temperate time;\nE\'en so Forese let that holy crew\nProceed, behind them lingering at my side,\nAnd saying: \"When shall I again behold thee?\"\n     \"How long my life may last,\" said I, \"I know not;\nThis know, how soon soever I return,\nMy wishes will before me have arriv\'d.\nSithence the place, where I am set to live,\nIs, day by day, more scoop\'d of all its good,\nAnd dismal ruin seems to threaten it.\"\n     \"Go now,\" he cried:  \"lo!  he, whose guilt is most,\nPasses before my vision, dragg\'d at heels\nOf an infuriate beast.  Toward the vale,\nWhere guilt hath no redemption, on it speeds,\nEach step increasing swiftness on the last;\nUntil a blow it strikes, that leaveth him\nA corse most vilely shatter\'d.  No long space\nThose wheels have yet to roll\"  (therewith his eyes\nLook\'d up to heav\'n) \"ere thou shalt plainly see\nThat which my words may not more plainly tell.\nI quit thee: time is precious here: I lose\nToo much, thus measuring my pace with shine.\"\n     As from a troop of well-rank\'d chivalry\nOne knight, more enterprising than the rest,\nPricks forth at gallop, eager to display\nHis prowess in the first encounter prov\'d\nSo parted he from us with lengthen\'d strides,\nAnd left me on the way with those twain spirits,\nWho were such mighty marshals of the world.\n     When he beyond us had so fled mine eyes\nNo nearer reach\'d him, than my thought his words,\nThe branches of another fruit, thick hung,\nAnd blooming fresh, appear\'d.  E\'en as our steps\nTurn\'d thither, not far off it rose to view.\nBeneath it were a multitude, that rais\'d\nTheir hands, and shouted forth I know not What\nUnto the boughs; like greedy and fond brats,\nThat beg, and answer none obtain from him,\nOf whom they beg; but more to draw them on,\nHe at arm\'s length the object of their wish\nAbove them holds aloft, and hides it not.\n     At length, as un");
    strcat(expected_filecontent, "deceiv\'d they went their way:\nAnd we approach the tree, who vows and tears\nSue to in vain, the mighty tree.  \"Pass on,\nAnd come not near.  Stands higher up the wood,\nWhereof Eve tasted, and from it was ta\'en\n\'this plant.\" Such sounds from midst the thickets came.\nWhence I, with either bard, close to the side\nThat rose, pass\'d forth beyond.  \"Remember,\" next\nWe heard, \"those noblest creatures of the clouds,\nHow they their twofold bosoms overgorg\'d\nOppos\'d in fight to Theseus:  call to mind\nThe Hebrews, how effeminate they stoop\'d\nTo ease their thirst; whence Gideon\'s ranks were thinn\'d,\nAs he to Midian march\'d adown the hills.\"\n     Thus near one border coasting, still we heard\nThe sins of gluttony, with woe erewhile\nReguerdon\'d.  Then along the lonely path,\nOnce more at large, full thousand paces on\nWe travel\'d, each contemplative and mute.\n     \"Why pensive journey thus ye three alone?\"\nThus suddenly a voice exclaim\'d: whereat\nI shook, as doth a scar\'d and paltry beast;\nThen rais\'d my head to look from whence it came.\n     Was ne\'er, in furnace, glass, or metal seen\nSo bright and glowing red, as was the shape\nI now beheld.  \"If ye desire to mount,\"\nHe cried, \"here must ye turn.  This way he goes,\nWho goes in quest of peace.\"  His countenance\nHad dazzled me; and to my guides I fac\'d\nBackward, like one who walks, as sound directs.\n     As when, to harbinger the dawn, springs up\nOn freshen\'d wing the air of May, and breathes\nOf fragrance, all impregn\'d with herb and flowers,\nE\'en such a wind I felt upon my front\nBlow gently, and the moving of a wing\nPerceiv\'d, that moving shed ambrosial smell;\nAnd then a voice:  \"Blessed are they, whom grace\nDoth so illume, that appetite in them\nExhaleth no inordinate desire,\nStill hung\'ring as the rule of temperance wills.\"\n\n\n\nCANTO XXV\n\nIt was an hour, when he who climbs, had need\nTo walk uncrippled: for the sun had now\nTo Taurus the meridian circle left,\nAnd to the Scorpion left the night.  As one\nThat makes no pause, but presses on his road,\nWhate\'er betide him, if some urgent need\nImpel: so enter\'d we upon our way,\nOne before other; for, but singly, none\nThat steep and narrow scale admits to climb.\n     E\'en as the young stork lifteth up his wing\nThrough wish to fly, yet ventures not to quit\nThe nest, and drops it; so in me desire\nOf questioning my guide arose, and fell,\nArriving even to the act, that marks\nA man prepar\'d for speech.  Him all our haste\nRestrain\'d not, but thus spake the sire belov\'d:\nFear not to speed the shaft, that on thy lip\nStands trembling for its flight.\"  Encourag\'d thus\nI straight began:  \"How there can leanness come,\nWhere is no want of nourishment to feed?\"\n     \"If thou,\" he answer\'d, \"hadst remember\'d thee,\nHow Meleager with the wasting brand\nWasted alike, by equal fires consm\'d,\nThis would not trouble thee: and hadst thou thought,\nHow in the mirror your reflected form\nWith mimic motion vibrates, what now seems\nHard, had appear\'d no harder than the pulp\nOf summer fruit mature.  But that thy will\nIn certainty may find its full repose,\nLo Statius here!  on him I call, and pray\nThat he would now be healer of thy wound.\"\n     \"If in thy presence I unfold to him\nThe secrets of heaven\'s vengeance, let me plead\nThine own injunction, to exculpate me.\"\nSo Statius answer\'d, and forthwith began:\n\"Attend my words, O son, and in thy mind\nReceive them: so shall they be light to clear\nThe doubt thou offer\'st. Blood, concocted well,\nWhich by the thirsty veins is ne\'er imbib\'d,\nAnd rests as food superfluous, to be ta\'en\nFrom the replenish\'d table, in the heart\nDerives effectual virtue, that informs\nThe several human limbs, as being that,\nWhich passes through the veins itself to make them.\nYet more concocted it descends, where shame\nForbids to mention: and from thence distils\nIn natural vessel on another\'s blood.\nThen each unite together, one dispos\'d\nT\' endure, to act the other, through meet frame\nOf its recipient mould: that being reach\'d,\nIt \'gins to work, coagulating first;\nThen vivifies what its own substance caus\'d\nTo bear.  With animation now indued,\nThe active virt");
    strcat(expected_filecontent, "ue (differing from a plant\nNo further, than that this is on the way\nAnd at its limit that) continues yet\nTo operate, that now it moves, and feels,\nAs sea sponge clinging to the rock: and there\nAssumes th\' organic powers its seed convey\'d.\n\'This is the period, son!  at which the virtue,\nThat from the generating heart proceeds,\nIs pliant and expansive; for each limb\nIs in the heart by forgeful nature plann\'d.\nHow babe of animal becomes, remains\nFor thy consid\'ring.  At this point, more wise,\nThan thou hast err\'d, making the soul disjoin\'d\nFrom passive intellect, because he saw\nNo organ for the latter\'s use assign\'d.\n     \"Open thy bosom to the truth that comes.\nKnow soon as in the embryo, to the brain,\nArticulation is complete, then turns\nThe primal Mover with a smile of joy\nOn such great work of nature, and imbreathes\nNew spirit replete with virtue, that what here\nActive it finds, to its own substance draws,\nAnd forms an individual soul, that lives,\nAnd feels, and bends reflective on itself.\nAnd that thou less mayst marvel at the word,\nMark the sun\'s heat, how that to wine doth change,\nMix\'d with the moisture filter\'d through the vine.\n     \"When Lachesis hath spun the thread, the soul\nTakes with her both the human and divine,\nMemory, intelligence, and will, in act\nFar keener than before, the other powers\nInactive all and mute.  No pause allow\'d,\nIn wond\'rous sort self-moving, to one strand\nOf those, where the departed roam, she falls,\nHere learns her destin\'d path.  Soon as the place\nReceives her, round the plastic virtue beams,\nDistinct as in the living limbs before:\nAnd as the air, when saturate with showers,\nThe casual beam refracting, decks itself\nWith many a hue; so here the ambient air\nWeareth that form, which influence of the soul\nImprints on it; and like the flame, that where\nThe fire moves, thither follows, so henceforth\nThe new form on the spirit follows still:\nHence hath it semblance, and is shadow call\'d,\nWith each sense even to the sight endued:\nHence speech is ours, hence laughter, tears, and sighs\nWhich thou mayst oft have witness\'d on the mount\nTh\' obedient shadow fails not to present\nWhatever varying passion moves within us.\nAnd this the cause of what thou marvel\'st at.\"\n     Now the last flexure of our way we reach\'d,\nAnd to the right hand turning, other care\nAwaits us.  Here the rocky precipice\nHurls forth redundant flames, and from the rim\nA blast upblown, with forcible rebuff\nDriveth them back, sequester\'d from its bound.\n     Behoov\'d us, one by one, along the side,\nThat border\'d on the void, to pass; and I\nFear\'d on one hand the fire, on th\' other fear\'d\nHeadlong to fall: when thus th\' instructor warn\'d:\n\"Strict rein must in this place direct the eyes.\nA little swerving and the way is lost.\"\n     Then from the bosom of the burning mass,\n\"O God of mercy!\" heard I sung; and felt\nNo less desire to turn.  And when I saw\nSpirits along the flame proceeding, I\nBetween their footsteps and mine own was fain\nTo share by turns my view.  At the hymn\'s close\nThey shouted loud, \"I do not know a man;\"\nThen in low voice again took up the strain,\nWhich once more ended, \"To the wood,\" they cried,\n\"Ran Dian, and drave forth Callisto, stung\nWith Cytherea\'s poison:\" then return\'d\nUnto their song; then marry a pair extoll\'d,\nWho liv\'d in virtue chastely, and the bands\nOf wedded love.  Nor from that task, I ween,\nSurcease they; whilesoe\'er the scorching fire\nEnclasps them.  Of such skill appliance needs\nTo medicine the wound, that healeth last.\n\n\n\nCANTO XXVI\n\nWhile singly thus along the rim we walk\'d,\nOft the good master warn\'d me:  \"Look thou well.\nA");

                struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "TOUCH.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                size_t size = file_read(filecontent, 1, 12090, file);
                test_error(size == 11807, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 11807 bajtów, a wczytała %lu", size);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 11807);

                // jeśli jest, to raportuj błąd
                test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

                onerror_compare_memory(expected_filecontent, filecontent, 11807);


                free(filecontent);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 20: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST20(void)
{
    // informacje o teście
    test_start(20, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[10241] = "";

                strcat(expected_filecontent, "ator, and remains\nEver between the sun and winter) for the cause\nThou hast assign\'d, from hence toward the north\nDeparts, when those who in the Hebrew land\nInhabit, see it tow\'rds the warmer part.\nBut if it please thee, I would gladly know,\nHow far we have to journey: for the hill\nMounts higher, than this sight of mine can mount.\"\n     He thus to me:  \"Such is this steep ascent,\nThat it is ever difficult at first,\nBut, more a man proceeds, less evil grows.\nWhen pleasant it shall seem to thee, so much\nThat upward going shall be easy to thee.\nAs in a vessel to go down the tide,\nThen of this path thou wilt have reach\'d the end.\nThere hope to rest thee from thy toil.  No more\nI answer, and thus far for certain know.\"\nAs he his words had spoken, near to us\nA voice there sounded:  \"Yet ye first perchance\nMay to repose you by constraint be led.\"\nAt sound thereof each turn\'d, and on the left\nA huge stone we beheld, of which nor I\nNor he before was ware.  Thither we drew,\nfind there were some, who in the shady place\nBehind the rock were standing, as a man\nThru\' idleness might stand.  Among them one,\nWho seem\'d to me much wearied, sat him down,\nAnd with his arms did fold his knees about,\nHolding his face between them downward bent.\n     \"Sweet Sir!\"  I cry\'d, \"behold that man, who shows\nHimself more idle, than if laziness\nWere sister to him.\"  Straight he turn\'d to us,\nAnd, o\'er the thigh lifting his face, observ\'d,\nThen in these accents spake:  \"Up then, proceed\nThou valiant one.\"  Straight who it was I knew;\nNor could the pain I felt (for want of breath\nStill somewhat urg\'d me) hinder my approach.\nAnd when I came to him, he scarce his head\nUplifted, saying \"Well hast thou discern\'d,\nHow from the left the sun his chariot leads.\"\n     His lazy acts and broken words my lips\nTo laughter somewhat mov\'d; when I began:\n\"Belacqua, now for thee I grieve no more.\nBut tell, why thou art seated upright there?\nWaitest thou escort to conduct thee hence?\nOr blame I only shine accustom\'d ways?\"\nThen he:  \"My brother, of what use to mount,\nWhen to my suffering would not let me pass\nThe bird of God, who at the portal sits?\nBehooves so long that heav\'n first bear me round\nWithout its limits, as in life it bore,\nBecause I to the end repentant Sighs\nDelay\'d, if prayer do not aid me first,\nThat riseth up from heart which lives in grace.\nWhat other kind avails, not heard in heaven?\"\'\n     Before me now the Poet up the mount\nAscending, cried:  \"Haste thee, for see the sun\nHas touch\'d the point meridian, and the night\nNow covers with her foot Marocco\'s shore.\"\n\n\n\nCANTO V\n\nNow had I left those spirits, and pursued\nThe steps of my Conductor, when beheld\nPointing the finger at me one exclaim\'d:\n\"See how it seems as if the light not shone\nFrom the left hand of him beneath, and he,\nAs living, seems to be led on.\"  Mine eyes\nI at that sound reverting, saw them gaze\nThrough wonder first at me, and then at me\nAnd the light broken underneath, by turns.\n\"Why are thy thoughts thus riveted?\"  my guide\nExclaim\'d, \"that thou hast slack\'d thy pace?  or how\nImports it thee, what thing is whisper\'d here?\nCome after me, and to their babblings leave\nThe crowd. Be as a tower, that, firmly set,\nShakes not its top for any blast that blows!\nHe, in whose bosom thought on thought shoots out,\nStill of his aim is wide, in that the one\nSicklies and wastes to nought the other\'s strength.\"\n     What other could I answer save \"I come?\"\nI said it, somewhat with that colour ting\'d\nWhich ofttimes pardon meriteth for man.\n     Meanwhile traverse along the hill there came,\nA little way before us, some who sang\nThe \"Miserere\" in responsive Strains.\nWhen they perceiv\'d that through my body I\nGave way not for the rays to pass, their song\nStraight to a long and hoarse exclaim they chang\'d;\nAnd two of them, in guise of messengers,\nRan on to meet us, and inquiring ask\'d:\nOf your condition we would gladly learn.\"\n     To them my guide.  \"Ye may return, and bear\nTidings to them who sent you, that his frame\nIs real flesh.  If, as I deem, to view\nHis shade they paus\'d, enough is answer\'d them.\nHim");
    strcat(expected_filecontent, " let them honour, they may prize him well.\"\n     Ne\'er saw I fiery vapours with such speed\nCut through the serene air at fall of night,\nNor August\'s clouds athwart the setting sun,\nThat upward these did not in shorter space\nReturn; and, there arriving, with the rest\nWheel back on us, as with loose rein a troop.\n     \"Many,\" exclaim\'d the bard, \"are these, who throng\nAround us: to petition thee they come.\nGo therefore on, and listen as thou go\'st.\"\n     \"O spirit!  who go\'st on to blessedness\nWith the same limbs, that clad thee at thy birth.\"\nShouting they came, \"a little rest thy step.\nLook if thou any one amongst our tribe\nHast e\'er beheld, that tidings of him there\nThou mayst report.  Ah, wherefore go\'st thou on?\nAh wherefore tarriest thou not?  We all\nBy violence died, and to our latest hour\nWere sinners, but then warn\'d by light from heav\'n,\nSo that, repenting and forgiving, we\nDid issue out of life at peace with God,\nWho with desire to see him fills our heart.\"\n     Then I:  \"The visages of all I scan\nYet none of ye remember.  But if aught,\nThat I can do, may please you, gentle spirits!\nSpeak; and I will perform it, by that peace,\nWhich on the steps of guide so excellent\nFollowing from world to world intent I seek.\"\n     In answer he began:  \"None here distrusts\nThy kindness, though not promis\'d with an oath;\nSo as the will fail not for want of power.\nWhence I, who sole before the others speak,\nEntreat thee, if thou ever see that land,\nWhich lies between Romagna and the realm\nOf Charles, that of thy courtesy thou pray\nThose who inhabit Fano, that for me\nTheir adorations duly be put up,\nBy which I may purge off my grievous sins.\nFrom thence I came.  But the deep passages,\nWhence issued out the blood wherein I dwelt,\nUpon my bosom in Antenor\'s land\nWere made, where to be more secure I thought.\nThe author of the deed was Este\'s prince,\nWho, more than right could warrant, with his wrath\nPursued me.  Had I towards Mira fled,\nWhen overta\'en at Oriaco, still\nMight I have breath\'d. But to the marsh I sped,\nAnd in the mire and rushes tangled there\nFell, and beheld my life-blood float the plain.\"\n     Then said another:  \"Ah! so may the wish,\nThat takes thee o\'er the mountain, be fulfill\'d,\nAs thou shalt graciously give aid to mine.\nOf Montefeltro I; Buonconte I:\nGiovanna nor none else have care for me,\nSorrowing with these I therefore go.\"  I thus:\n\"From Campaldino\'s field what force or chance\nDrew thee, that ne\'er thy sepulture was known?\"\n     \"Oh!\"  answer\'d he, \"at Casentino\'s foot\nA stream there courseth, nam\'d Archiano, sprung\nIn Apennine above the Hermit\'s seat.\nE\'en where its name is cancel\'d, there came I,\nPierc\'d in the heart, fleeing away on foot,\nAnd bloodying the plain.  Here sight and speech\nFail\'d me, and finishing with Mary\'s name\nI fell, and tenantless my flesh remain\'d.\nI will report the truth; which thou again0\nTell to the living.  Me God\'s angel took,\nWhilst he of hell exclaim\'d:  \"O thou from heav\'n!\nSay wherefore hast thou robb\'d me?  Thou of him\nTh\' eternal portion bear\'st with thee away\nFor one poor tear that he deprives me of.\nBut of the other, other rule I make.\"\n     \"Thou knowest how in the atmosphere collects\nThat vapour dank, returning into water,\nSoon as it mounts where cold condenses it.\nThat evil will, which in his intellect\nStill follows evil, came, and rais\'d the wind\nAnd smoky mist, by virtue of the power\nGiven by his nature.  Thence the valley, soon\nAs day was spent, he cover\'d o\'er with cloud\nFrom Pratomagno to the mountain range,\nAnd stretch\'d the sky above, so that the air\nImpregnate chang\'d to water.  Fell the rain,\nAnd to the fosses came all that the land\nContain\'d not; and, as mightiest streams are wont,\nTo the great river with such headlong sweep\nRush\'d, that nought stay\'d its course.  My stiffen\'d frame\nLaid at his mouth the fell Archiano found,\nAnd dash\'d it into Arno, from my breast\nLoos\'ning the cross, that of myself I made\nWhen overcome with pain.  He hurl\'d me on,\nAlong the banks and bottom of his course;\nThen in his muddy spoils encircling wrapt.\"\n     \"Ah!  when thou to th");
    strcat(expected_filecontent, "e world shalt be return\'d,\nAnd rested after thy long road,\" so spake\nNext the third spirit; \"then remember me.\nI once was Pia.  Sienna gave me life,\nMaremma took it from me.  That he knows,\nWho me with jewell\'d ring had first espous\'d.\"\n\n\n\nCANTO VI\n\nWhen from their game of dice men separate,\nHe, who hath lost, remains in sadness fix\'d,\nRevolving in his mind, what luckless throws\nHe cast: but meanwhile all the company\nGo with the other; one before him runs,\nAnd one behind his mantle twitches, one\nFast by his side bids him remember him.\nHe stops not; and each one, to whom his hand\nIs stretch\'d, well knows he bids him stand aside;\nAnd thus he from the press defends himself.\nE\'en such was I in that close-crowding throng;\nAnd turning so my face around to all,\nAnd promising, I \'scap\'d from it with pains.\n     Here of Arezzo him I saw, who fell\nBy Ghino\'s cruel arm; and him beside,\nWho in his chase was swallow\'d by the stream.\nHere Frederic Novello, with his hand\nStretch\'d forth, entreated; and of Pisa he,\nWho put the good Marzuco to such proof\nOf constancy.  Count Orso I beheld;\nAnd from its frame a soul dismiss\'d for spite\nAnd envy, as it said, but for no crime:\nI speak of Peter de la Brosse; and here,\nWhile she yet lives, that Lady of Brabant\nLet her beware; lest for so false a deed\nShe herd with worse than these. When I was freed\nFrom all those spirits, who pray\'d for others\' prayers\nTo hasten on their state of blessedness;\nStraight I began:  \"O thou, my luminary!\nIt seems expressly in thy text denied,\nThat heaven\'s supreme decree can never bend\nTo supplication; yet with this design\nDo these entreat.  Can then their hope be vain,\nOr is thy saying not to me reveal\'d?\"\n     He thus to me:  \"Both what I write is plain,\nAnd these deceiv\'d not in their hope, if well\nThy mind consider, that the sacred height\nOf judgment doth not stoop, because love\'s flame\nIn a short moment all fulfils, which he\nWho sojourns here, in right should satisfy.\nBesides, when I this point concluded thus,\nBy praying no defect could be supplied;\nBec");

                struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "WISH.TXT");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 10240; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 21: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST21(void)
{
    // informacje o teście
    test_start(21, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[9689] = "";

                strcat(expected_filecontent, "e?\nHe hath in sooth good cause for endless grief,\nWho, for the love of thing that lasteth not,\nDespoils himself forever of that love.\n     As oft along the still and pure serene,\nAt nightfall, glides a sudden trail of fire,\nAttracting with involuntary heed\nThe eye to follow it, erewhile at rest,\nAnd seems some star that shifted place in heav\'n,\nOnly that, whence it kindles, none is lost,\nAnd it is soon extinct; thus from the horn,\nThat on the dexter of the cross extends,\nDown to its foot, one luminary ran\nFrom mid the cluster shone there; yet no gem\nDropp\'d from its foil; and through the beamy list\nLike flame in alabaster, glow\'d its course.\n     So forward stretch\'d him (if of credence aught\nOur greater muse may claim) the pious ghost\nOf old Anchises, in the\' Elysian bower,\nWhen he perceiv\'d his son.  \"O thou, my blood!\nO most exceeding grace divine!  to whom,\nAs now to thee, hath twice the heav\'nly gate\nBeen e\'er unclos\'d?\" so spake the light; whence I\nTurn\'d me toward him; then unto my dame\nMy sight directed, and on either side\nAmazement waited me; for in her eyes\nWas lighted such a smile, I thought that mine\nHad div\'d unto the bottom of my grace\nAnd of my bliss in Paradise.  Forthwith\nTo hearing and to sight grateful alike,\nThe spirit to his proem added things\nI understood not, so profound he spake;\nYet not of choice but through necessity\nMysterious; for his high conception scar\'d\nBeyond the mark of mortals.  When the flight\nOf holy transport had so spent its rage,\nThat nearer to the level of our thought\nThe speech descended, the first sounds I heard\nWere, \"Best he thou, Triunal Deity!\nThat hast such favour in my seed vouchsaf\'d!\"\nThen follow\'d:  \"No unpleasant thirst, tho\' long,\nWhich took me reading in the sacred book,\nWhose leaves or white or dusky never change,\nThou hast allay\'d, my son, within this light,\nFrom whence my voice thou hear\'st; more thanks to her.\nWho for such lofty mounting has with plumes\nBegirt thee.  Thou dost deem thy thoughts to me\nFrom him transmitted, who is first of all,\nE\'en as all numbers ray from unity;\nAnd therefore dost not ask me who I am,\nOr why to thee more joyous I appear,\nThan any other in this gladsome throng.\nThe truth is as thou deem\'st; for in this hue\nBoth less and greater in that mirror look,\nIn which thy thoughts, or ere thou think\'st, are shown.\nBut, that the love, which keeps me wakeful ever,\nUrging with sacred thirst of sweet desire,\nMay be contended fully, let thy voice,\nFearless, and frank and jocund, utter forth\nThy will distinctly, utter forth the wish,\nWhereto my ready answer stands decreed.\"\n     I turn\'d me to Beatrice; and she heard\nEre I had spoken, smiling, an assent,\nThat to my will gave wings; and I began\n\"To each among your tribe, what time ye kenn\'d\nThe nature, in whom naught unequal dwells,\nWisdom and love were in one measure dealt;\nFor that they are so equal in the sun,\nFrom whence ye drew your radiance and your heat,\nAs makes all likeness scant.  But will and means,\nIn mortals, for the cause ye well discern,\nWith unlike wings are fledge.  A mortal I\nExperience inequality like this,\nAnd therefore give no thanks, but in the heart,\nFor thy paternal greeting.  This howe\'er\nI pray thee, living topaz!  that ingemm\'st\nThis precious jewel, let me hear thy name.\"\n     \"I am thy root, O leaf!  whom to expect\nEven, hath pleas\'d me:  \"thus the prompt reply\nPrefacing, next it added;  \"he, of whom\nThy kindred appellation comes, and who,\nThese hundred years and more, on its first ledge\nHath circuited the mountain, was my son\nAnd thy great grandsire.  Well befits, his long\nEndurance should he shorten\'d by thy deeds.\n     \"Florence, within her ancient limit-mark,\nWhich calls her still to matin prayers and noon,\nWas chaste and sober, and abode in peace.\nShe had no armlets and no head-tires then,\nNo purfled dames, no zone, that caught the eye\nMore than the person did.  Time was not yet,\nWhen at his daughter\'s birth the sire grew pale.\nFor fear the age and dowry should exceed\nOn each side just proportion.  House was none\nVoid of its family; nor yet had come\nHardanapalus, to");
    strcat(expected_filecontent, " exhibit feats\nOf chamber prowess.  Montemalo yet\nO\'er our suburban turret rose; as much\nTo be surpass in fall, as in its rising.\nI saw Bellincione Berti walk abroad\nIn leathern girdle and a clasp of bone;\nAnd, with no artful colouring on her cheeks,\nHis lady leave the glass.  The sons I saw\nOf Nerli and of Vecchio well content\nWith unrob\'d jerkin; and their good dames handling\nThe spindle and the flax; O happy they!\nEach sure of burial in her native land,\nAnd none left desolate a-bed for France!\nOne wak\'d to tend the cradle, hushing it\nWith sounds that lull\'d the parent\'s infancy:\nAnother, with her maidens, drawing off\nThe tresses from the distaff, lectur\'d them\nOld tales of Troy and Fesole and Rome.\nA Salterello and Cianghella we\nHad held as strange a marvel, as ye would\nA Cincinnatus or Cornelia now.\n     \"In such compos\'d and seemly fellowship,\nSuch faithful and such fair equality,\nIn so sweet household, Mary at my birth\nBestow\'d me, call\'d on with loud cries; and there\nIn your old baptistery, I was made\nChristian at once and Cacciaguida; as were\nMy brethren, Eliseo and Moronto.\n     \"From Valdipado came to me my spouse,\nAnd hence thy surname grew.  I follow\'d then\nThe Emperor Conrad; and his knighthood he\nDid gird on me; in such good part he took\nMy valiant service.  After him I went\nTo testify against that evil law,\nWhose people, by the shepherd\'s fault, possess\nYour right, usurping.  There, by that foul crew\nWas I releas\'d from the deceitful world,\nWhose base affection many a spirit soils,\nAnd from the martyrdom came to this peace.\"\n\n\n\nCANTO XVI\n\nO slight respect of man\'s nobility!\nI never shall account it marvelous,\nThat our infirm affection here below\nThou mov\'st to boasting, when I could not choose,\nE\'en in that region of unwarp\'d desire,\nIn heav\'n itself, but make my vaunt in thee!\nYet cloak thou art soon shorten\'d, for that time,\nUnless thou be eked out from day to day,\nGoes round thee with his shears.  Resuming then\nWith greeting such, as Rome, was first to bear,\nBut since hath disaccustom\'d I began;\nAnd Beatrice, that a little space\nWas sever\'d, smil\'d reminding me of her,\nWhose cough embolden\'d (as the story holds)\nTo first offence the doubting Guenever.\n     \"You are my sire,\" said I, \"you give me heart\nFreely to speak my thought: above myself\nYou raise me.  Through so many streams with joy\nMy soul is fill\'d, that gladness wells from it;\nSo that it bears the mighty tide, and bursts not\nSay then, my honour\'d stem!  what ancestors\nWhere those you sprang from, and what years were mark\'d\nIn your first childhood?  Tell me of the fold,\nThat hath Saint John for guardian, what was then\nIts state, and who in it were highest seated?\"\n     As embers, at the breathing of the wind,\nTheir flame enliven, so that light I saw\nShine at my blandishments; and, as it grew\nMore fair to look on, so with voice more sweet,\nYet not in this our modern phrase, forthwith\nIt answer\'d:  \"From the day, when it was said\n\' Hail Virgin!\' to the throes, by which my mother,\nWho now is sainted, lighten\'d her of me\nWhom she was heavy with, this fire had come,\nFive hundred fifty times and thrice, its beams\nTo reilumine underneath the foot\nOf its own lion.  They, of whom I sprang,\nAnd I, had there our birth-place, where the last\nPartition of our city first is reach\'d\nBy him, that runs her annual game.  Thus much\nSuffice of my forefathers: who they were,\nAnd whence they hither came, more honourable\nIt is to pass in silence than to tell.\nAll those, who in that time were there from Mars\nUntil the Baptist, fit to carry arms,\nWere but the fifth of them this day alive.\nBut then the citizen\'s blood, that now is mix\'d\nFrom Campi and Certaldo and Fighine,\nRan purely through the last mechanic\'s veins.\nO how much better were it, that these people\nWere neighbours to you, and that at Galluzzo\nAnd at Trespiano, ye should have your bound\'ry,\nThan to have them within, and bear the stench\nOf Aguglione\'s hind, and Signa\'s, him,\nThat hath his eye already keen for bart\'ring!\nHad not the people, which of all the world\nDegenerates most, been stepdame unto Caesar,\nBu");
    strcat(expected_filecontent, "t, as a mother, gracious to her son;\nSuch one, as hath become a Florentine,\nAnd trades and traffics, had been turn\'d adrift\nTo Simifonte, where his grandsire ply\'d\nThe beggar\'s craft.  The Conti were possess\'d\nOf Montemurlo still: the Cerchi still\nWere in Acone\'s parish; nor had haply\nFrom Valdigrieve past the Buondelmonte.\nThe city\'s malady hath ever source\nIn the confusion of its persons, as\nThe body\'s, in variety of food:\nAnd the blind bull falls with a steeper plunge,\nThan the blind lamb; and oftentimes one sword\nDoth more and better execution,\nThan five.  Mark Luni, Urbisaglia mark,\nHow they are gone, and after them how go\nChiusi and Sinigaglia; and \'t will seem\nNo longer new or strange to thee to hear,\nThat families fail, when cities have their end.\nAll things, that appertain t\' ye, like yourselves,\nAre mortal: but mortality in some\nYe mark not, they endure so long, and you\nPass by so suddenly.  And as the moon\nDoth, by the rolling of her heav\'nly sphere,\nHide and reveal the strand unceasingly;\nSo fortune deals with Florence.  Hence admire not\nAt what of them I tell thee, whose renown\nTime covers, the first Florentines.  I saw\nThe Ughi, Catilini and Filippi,\nThe Alberichi, Greci and Ormanni,\nNow in their wane, illustrious citizens:\nAnd great as ancient, of Sannella him,\nWith him of Arca saw, and Soldanieri\nAnd Ardinghi, and Bostichi.  At the poop,\nThat now is laden with new felony,\nSo cumb\'rous it may speedily sink the bark,\nThe Ravignani sat, of whom is sprung\nThe Co");

                struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "LEARN.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 9688; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 22: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST22(void)
{
    // informacje o teście
    test_start(22, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[10314] = "";

                strcat(expected_filecontent, "rtue guides not; that if aught of good\nMy gentle star, or something better gave me,\nI envy not myself the precious boon.\n     As in that season, when the sun least veils\nHis face that lightens all, what time the fly\nGives way to the shrill gnat, the peasant then\nUpon some cliff reclin\'d, beneath him sees\nFire-flies innumerous spangling o\'er the vale,\nVineyard or tilth, where his day-labour lies:\nWith flames so numberless throughout its space\nShone the eighth chasm, apparent, when the depth\nWas to my view expos\'d. As he, whose wrongs\nThe bears aveng\'d, at its departure saw\nElijah\'s chariot, when the steeds erect\nRais\'d their steep flight for heav\'n; his eyes meanwhile,\nStraining pursu\'d them, till the flame alone\nUpsoaring like a misty speck he kenn\'d;\nE\'en thus along the gulf moves every flame,\nA sinner so enfolded close in each,\nThat none exhibits token of the theft.\n     Upon the bridge I forward bent to look,\nAnd grasp\'d a flinty mass, or else had fall\'n,\nThough push\'d not from the height.  The guide, who mark d\nHow I did gaze attentive, thus began:\n\"Within these ardours are the spirits, each\nSwath\'d in confining fire.\"--\"Master, thy word,\"\nI answer\'d, \"hath assur\'d me; yet I deem\'d\nAlready of the truth, already wish\'d\nTo ask thee, who is in yon fire, that comes\nSo parted at the summit, as it seem\'d\nAscending from that funeral pile, where lay\nThe Theban brothers?\"  He replied:  \"Within\nUlysses there and Diomede endure\nTheir penal tortures, thus to vengeance now\nTogether hasting, as erewhile to wrath.\nThese in the flame with ceaseless groans deplore\nThe ambush of the horse, that open\'d wide\nA portal for that goodly seed to pass,\nWhich sow\'d imperial Rome; nor less the guile\nLament they, whence of her Achilles \'reft\nDeidamia yet in death complains.\nAnd there is rued the stratagem, that Troy\nOf her Palladium spoil\'d.\"--\"If they have power\nOf utt\'rance from within these sparks,\" said I,\n\"O master!  think my prayer a thousand fold\nIn repetition urg\'d, that thou vouchsafe\nTo pause, till here the horned flame arrive.\nSee, how toward it with desire I bend.\"\n     He thus:  \"Thy prayer is worthy of much praise,\nAnd I accept it therefore:  but do thou\nThy tongue refrain:  to question them be mine,\nFor I divine thy wish:  and they perchance,\nFor they were Greeks, might shun discourse with thee.\"\n     When there the flame had come, where time and place\nSeem\'d fitting to my guide, he thus began:\n\"O ye, who dwell two spirits in one fire!\nIf living I of you did merit aught,\nWhate\'er the measure were of that desert,\nWhen in the world my lofty strain I pour\'d,\nMove ye not on, till one of you unfold\nIn what clime death o\'ertook him self-destroy\'d.\"\n     Of the old flame forthwith the greater horn\nBegan to roll, murmuring, as a fire\nThat labours with the wind, then to and fro\nWagging the top, as a tongue uttering sounds,\nThrew out its voice, and spake:  \"When I escap\'d\nFrom Circe, who beyond a circling year\nHad held me near Caieta, by her charms,\nEre thus Aeneas yet had nam\'d the shore,\nNor fondness for my son, nor reverence\nOf my old father, nor return of love,\nThat should have crown\'d Penelope with joy,\nCould overcome in me the zeal I had\nT\' explore the world, and search the ways of life,\nMan\'s evil and his virtue.  Forth I sail\'d\nInto the deep illimitable main,\nWith but one bark, and the small faithful band\nThat yet cleav\'d to me.  As Iberia far,\nFar as Morocco either shore I saw,\nAnd the Sardinian and each isle beside\nWhich round that ocean bathes.  Tardy with age\nWere I and my companions, when we came\nTo the strait pass, where Hercules ordain\'d\nThe bound\'ries not to be o\'erstepp\'d by man.\nThe walls of Seville to my right I left,\nOn the\' other hand already Ceuta past.\n\"O brothers!\"  I began, \"who to the west\nThrough perils without number now have reach\'d,\nTo this the short remaining watch, that yet\nOur senses have to wake, refuse not proof\nOf the unpeopled world, following the track\nOf Phoebus. Call to mind from whence we sprang:\nYe were not form\'d to live the life of brutes\nBut virtue to pursue and knowledge high.\nWith these few wo");
    strcat(expected_filecontent, "rds I sharpen\'d for the voyage\nThe mind of my associates, that I then\nCould scarcely have withheld them.  To the dawn\nOur poop we turn\'d, and for the witless flight\nMade our oars wings, still gaining on the left.\nEach star of the\' other pole night now beheld,\nAnd ours so low, that from the ocean-floor\nIt rose not.  Five times re-illum\'d, as oft\nVanish\'d the light from underneath the moon\nSince the deep way we enter\'d, when from far\nAppear\'d a mountain dim, loftiest methought\nOf all I e\'er beheld.  Joy seiz\'d us straight,\nBut soon to mourning changed.  From the new land\nA whirlwind sprung, and at her foremost side\nDid strike the vessel.  Thrice it whirl\'d her round\nWith all the waves, the fourth time lifted up\nThe poop, and sank the prow: so fate decreed:\nAnd over us the booming billow clos\'d.\"\n\n\n\nCANTO XXVII\n\nNOW upward rose the flame, and still\'d its light\nTo speak no more, and now pass\'d on with leave\nFrom the mild poet gain\'d, when following came\nAnother, from whose top a sound confus\'d,\nForth issuing, drew our eyes that way to look.\n     As the Sicilian bull, that rightfully\nHis cries first echoed, who had shap\'d its mould,\nDid so rebellow, with the voice of him\nTormented, that the brazen monster seem\'d\nPierc\'d through with pain; thus while no way they found\nNor avenue immediate through the flame,\nInto its language turn\'d the dismal words:\nBut soon as they had won their passage forth,\nUp from the point, which vibrating obey\'d\nTheir motion at the tongue, these sounds we heard:\n\"O thou!  to whom I now direct my voice!\nThat lately didst exclaim in Lombard phrase,\n     Depart thou, I solicit thee no more,\'\nThough somewhat tardy I perchance arrive\nLet it not irk thee here to pause awhile,\nAnd with me parley:  lo! it irks not me\nAnd yet I burn.  If but e\'en now thou fall\ninto this blind world, from that pleasant land\nOf Latium, whence I draw my sum of guilt,\nTell me if those, who in Romagna dwell,\nHave peace or war.  For of the mountains there\nWas I, betwixt Urbino and the height,\nWhence Tyber first unlocks his mighty flood.\"\n     Leaning I listen\'d yet with heedful ear,\nWhen, as he touch\'d my side, the leader thus:\n\"Speak thou: he is a Latian.\"  My reply\nWas ready, and I spake without delay:\n     \"O spirit!  who art hidden here below!\nNever was thy Romagna without war\nIn her proud tyrants\' bosoms, nor is now:\nBut open war there left I none.  The state,\nRavenna hath maintain\'d this many a year,\nIs steadfast.  There Polenta\'s eagle broods,\nAnd in his broad circumference of plume\nO\'ershadows Cervia. The green talons grasp\nThe land, that stood erewhile the proof so long,\nAnd pil\'d in bloody heap the host of France.\n     \"The\' old mastiff of Verruchio and the young,\nThat tore Montagna in their wrath, still make,\nWhere they are wont, an augre of their fangs.\n     \"Lamone\'s city and Santerno\'s range\nUnder the lion of the snowy lair.\nInconstant partisan! that changeth sides,\nOr ever summer yields to winter\'s frost.\nAnd she, whose flank is wash\'d of Savio\'s wave,\nAs \'twixt the level and the steep she lies,\nLives so \'twixt tyrant power and liberty.\n     \"Now tell us, I entreat thee, who art thou?\nBe not more hard than others.  In the world,\nSo may thy name still rear its forehead high.\"\n     Then roar\'d awhile the fire, its sharpen\'d point\nOn either side wav\'d, and thus breath\'d at last:\n\"If I did think, my answer were to one,\nWho ever could return unto the world,\nThis flame should rest unshaken.  But since ne\'er,\nIf true be told me, any from this depth\nHas found his upward way, I answer thee,\nNor fear lest infamy record the words.\n     \"A man of arms at first, I cloth\'d me then\nIn good Saint Francis\' girdle, hoping so\nT\' have made amends.  And certainly my hope\nHad fail\'d not, but that he, whom curses light on,\nThe\' high priest again seduc\'d me into sin.\nAnd how and wherefore listen while I tell.\nLong as this spirit mov\'d the bones and pulp\nMy mother gave me, less my deeds bespake\nThe nature of the lion than the fox.\nAll ways of winding subtlety I knew,\nAnd with such art conducted, that the sound\nReach\'d the world\'s limit.  Soon ");
    strcat(expected_filecontent, "as to that part\nOf life I found me come, when each behoves\nTo lower sails and gather in the lines;\nThat which before had pleased me then I rued,\nAnd to repentance and confession turn\'d;\nWretch that I was! and well it had bested me!\nThe chief of the new Pharisees meantime,\nWaging his warfare near the Lateran,\nNot with the Saracens or Jews (his foes\nAll Christians were, nor against Acre one\nHad fought, nor traffic\'d in the Soldan\'s land),\nHe his great charge nor sacred ministry\nIn himself, rev\'renc\'d, nor in me that cord,\nWhich us\'d to mark with leanness whom it girded.\nAs in Socrate, Constantine besought\nTo cure his leprosy Sylvester\'s aid,\nSo me to cure the fever of his pride\nThis man besought: my counsel to that end\nHe ask\'d:  and I was silent:  for his words\nSeem\'d drunken:  but forthwith he thus resum\'d:\n\"From thy heart banish fear:  of all offence\nI hitherto absolve thee.  In return,\nTeach me my purpose so to execute,\nThat Penestrino cumber earth no more.\nHeav\'n, as thou knowest, I have power to shut\nAnd open:  and the keys are therefore twain,\nThe which my predecessor meanly priz\'d.\"\n     Then, yielding to the forceful arguments,\nOf silence as more perilous I deem\'d,\nAnd answer\'d:  \"Father! since thou washest me\nClear of that guilt wherein I now must fall,\nLarge promise with performance scant, be sure,\nShall make thee triumph in thy lofty seat.\"\n     \"When I was number\'d with the dead, then came\nSaint Francis for me; but a cherub dark\nHe met, who cried: \"\'Wrong me not; he is mine,\nAnd must below to join the wretched crew,\nFor the deceitful counsel which he gave.\nE\'er since I watch\'d him, hov\'ring at his hair,\nNo power can the impenitent absolve;\nNor to repent and will at once consist,\nBy contradiction absolute forbid.\"\nOh mis\'ry! how I shook myself, when he\nSeiz\'d me, and cried, \"Thou haply thought\'st me not\nA disputant in logic so exact.\"\nTo Minos down he bore me, and the judge\nTwin\'d eight times round his callous back the tail,\nWhich biting with excess of rage, he spake:\n\"This is a guilty soul, that in the fire\nMust vanish.\'  Hence perdition-doom\'d I rove\nA prey to rankling sorro");

                struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "DRINK.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 10313; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 23: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST23(void)
{
    // informacje o teście
    test_start(23, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[1545] = "";

                strcat(expected_filecontent, "males to\ndeath.\n\nv. 120.  Alessio.]  Alessio, of an ancient and considerable\nfamily in Lucca, called the Interminei.\n\nv. 130.  Thais.]  He alludes to that passage in the Eunuchus of\nTerence where Thraso asks if Thais was obliged to him for the\npresent he had sent her, and Gnatho replies, that she had\nexpressed her obligation in the most forcible terms.\n        T.  Magnas vero agere gratias Thais mihi?\n        G.  Ingentes.\n               Eun. a. iii. s. i.\n\nCANTO XIX\n\nv. 18.  Saint John\'s fair dome.]  The apertures in the  rock were\nof the same dimensions as the fonts of St. John the Baptist at\nFlorence, one of which, Dante says he had broken, to rescue a\nchild  that was playing near and fell in. He intimates that the\nmotive of his  breaking the font had been maliciously represented\nby his enemies.\n\nv. 55.  O Boniface!]  The spirit mistakes Dante for  Boniface\nVIII. who was then alive, and who he did not expect would have\narrived so soon, in consequence, as it should seem, of a\nprophecy, which  predicted the death of that Pope at a later\nperiod. Boniface died in  1303.\n\nv. 58.  In guile.]  \"Thou didst presume to arrive by fraudulent\nmeans at the papal power, and afterwards to abuse it.\"\n\nv. 71.  In the mighty mantle I was rob\'d.]  Nicholas III, of the\nOrsini family, whom the poet therefore calls \"figliuol dell\'\norsa,\" \"son of the she-bear.\"  He died in 1281.\n\nv. 86.  From forth the west, a shepherd without law.]   Bertrand\nde Got Archbishop of Bordeaux, who succeeded to the pontificate\nin 1305, and assumed the title of");

                struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "COME");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 1544; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 24: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST24(void)
{
    // informacje o teście
    test_start(24, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[12522] = "";

                strcat(expected_filecontent, "h, conjur\'d by fell\nErictho, sorceress, who compell\'d the shades\nBack to their bodies.  No long space my flesh\nWas naked of me, when within these walls\nShe made me enter, to draw forth a spirit\nFrom out of Judas\' circle.  Lowest place\nIs that of all, obscurest, and remov\'d\nFarthest from heav\'n\'s all-circling orb.  The road\nFull well I know:  thou therefore rest secure.\nThat lake, the noisome stench exhaling, round\nThe city\' of grief encompasses, which now\nWe may not enter without rage.\"  Yet more\nHe added:  but I hold it not in mind,\nFor that mine eye toward the lofty tower\nHad drawn me wholly, to its burning top.\nWhere in an instant I beheld uprisen\nAt once three hellish furies stain\'d with blood:\nIn limb and motion feminine they seem\'d;\nAround them greenest hydras twisting roll\'d\nTheir volumes; adders and cerastes crept\nInstead of hair, and their fierce temples bound.\n     He knowing well the miserable hags\nWho tend the queen of endless woe, thus spake:\n\"Mark thou each dire Erinnys. To the left\nThis is Megaera; on the right hand she,\nWho wails, Alecto; and Tisiphone\nI\' th\' midst.\"  This said, in silence he remain\'d\nTheir breast they each one clawing tore; themselves\nSmote with their palms, and such shrill clamour rais\'d,\nThat to the bard I clung, suspicion-bound.\n\"Hasten Medusa: so to adamant\nHim shall we change;\" all looking down exclaim\'d.\n\"E\'en when by Theseus\' might assail\'d, we took\nNo ill revenge.\"  \"Turn thyself round, and keep\nThy count\'nance hid; for if the Gorgon dire\nBe shown, and thou shouldst view it, thy return\nUpwards would be for ever lost.\"  This said,\nHimself my gentle master turn\'d me round,\nNor trusted he my hands, but with his own\nHe also hid me.  Ye of intellect\nSound and entire, mark well the lore conceal\'d\nUnder close texture of the mystic strain!\n     And now there came o\'er the perturbed waves\nLoud-crashing, terrible, a sound that made\nEither shore tremble, as if of a wind\nImpetuous, from conflicting vapours sprung,\nThat \'gainst some forest driving all its might,\nPlucks off the branches, beats them down and hurls\nAfar; then onward passing proudly sweeps\nIts whirlwind rage, while beasts and shepherds fly.\n     Mine eyes he loos\'d, and spake: \"And now direct\nThy visual nerve along that ancient foam,\nThere, thickest where the smoke ascends.\" As frogs\nBefore their foe the serpent, through the wave\nPly swiftly all, till at the ground each one\nLies on a heap; more than a thousand spirits\nDestroy\'d, so saw I fleeing before one\nWho pass\'d with unwet feet the Stygian sound.\nHe, from his face removing the gross air,\nOft his left hand forth stretch\'d, and seem\'d alone\nBy that annoyance wearied.  I perceiv\'d\nThat he was sent from heav\'n, and to my guide\nTurn\'d me, who signal made that I should stand\nQuiet, and bend to him. Ah me!  how full\nOf noble anger seem\'d he!  To the gate\nHe came, and with his wand touch\'d it, whereat\nOpen without impediment it flew.\n     \"Outcasts of heav\'n!  O abject race and scorn\'d!\"\nBegan he on the horrid grunsel standing,\n\"Whence doth this wild excess of insolence\nLodge in you? wherefore kick you \'gainst that will\nNe\'er frustrate of its end, and which so oft\nHath laid on you enforcement of your pangs?\nWhat profits at the fays to but the horn?\nYour Cerberus, if ye remember, hence\nBears still, peel\'d of their hair, his throat and maw.\"\n     This said, he turn\'d back o\'er the filthy way,\nAnd syllable to us spake none, but wore\nThe semblance of a man by other care\nBeset, and keenly press\'d, than thought of him\nWho in his presence stands.  Then we our steps\nToward that territory mov\'d, secure\nAfter the hallow\'d words.  We unoppos\'d\nThere enter\'d; and my mind eager to learn\nWhat state a fortress like to that might hold,\nI soon as enter\'d throw mine eye around,\nAnd see on every part wide-stretching space\nReplete with bitter pain and torment ill.\n     As where Rhone stagnates on the plains of Arles,\nOr as at Pola, near Quarnaro\'s gulf,\nThat closes Italy and laves her bounds,\nThe place is all thick spread with sepulchres;\nSo was it here, save what in horror here\nExcell\'d:  for \'midst ");
    strcat(expected_filecontent, "the graves were scattered flames,\nWherewith intensely all throughout they burn\'d,\nThat iron for no craft there hotter needs.\n     Their lids all hung suspended, and beneath\nFrom them forth issu\'d lamentable moans,\nSuch as the sad and tortur\'d well might raise.\n     I thus:  \"Master! say who are these, interr\'d\nWithin these vaults, of whom distinct we hear\nThe dolorous sighs?\"  He answer thus return\'d:\n     \"The arch-heretics are here, accompanied\nBy every sect their followers; and much more,\nThan thou believest, tombs are freighted:  like\nWith like is buried; and the monuments\nAre different in degrees of heat. \"This said,\nHe to the right hand turning, on we pass\'d\nBetwixt the afflicted and the ramparts high.\n\n\n\nCANTO X\n\nNOW by a secret pathway we proceed,\nBetween the walls, that hem the region round,\nAnd the tormented souls:  my master first,\nI close behind his steps.  \"Virtue supreme!\"\nI thus began; \"who through these ample orbs\nIn circuit lead\'st me, even as thou will\'st,\nSpeak thou, and satisfy my wish.  May those,\nWho lie within these sepulchres, be seen?\nAlready all the lids are rais\'d, and none\nO\'er them keeps watch.\"  He thus in answer spake\n\"They shall be closed all, what-time they here\nFrom Josaphat return\'d shall come, and bring\nTheir bodies, which above they now have left.\nThe cemetery on this part obtain\nWith Epicurus all his followers,\nWho with the body make the spirit die.\nHere therefore satisfaction shall be soon\nBoth to the question ask\'d, and to the wish,\nWhich thou conceal\'st in silence.\"  I replied:\n\"I keep not, guide belov\'d! from thee my heart\nSecreted, but to shun vain length of words,\nA lesson erewhile taught me by thyself.\"\n     \"O Tuscan! thou who through the city of fire\nAlive art passing, so discreet of speech!\nHere please thee stay awhile. Thy utterance\nDeclares the place of thy nativity\nTo be that noble land, with which perchance\nI too severely dealt.\"  Sudden that sound\nForth issu\'d from a vault, whereat in fear\nI somewhat closer to my leader\'s side\nApproaching, he thus spake:  \"What dost thou?  Turn.\nLo, Farinata, there! who hath himself\nUplifted:  from his girdle upwards all\nExpos\'d behold him.\"  On his face was mine\nAlready fix\'d; his breast and forehead there\nErecting, seem\'d as in high scorn he held\nE\'en hell.  Between the sepulchres to him\nMy guide thrust me with fearless hands and prompt,\nThis warning added:  \"See thy words be clear!\"\n     He, soon as there I stood at the tomb\'s foot,\nEy\'d me a space, then in disdainful mood\nAddress\'d me:  \"Say, what ancestors were thine?\"\n     I, willing to obey him, straight reveal\'d\nThe whole, nor kept back aught: whence he, his brow\nSomewhat uplifting, cried:  \"Fiercely were they\nAdverse to me, my party, and the blood\nFrom whence I sprang:  twice therefore I abroad\nScatter\'d them.\"  \"Though driv\'n out, yet they each time\nFrom all parts,\" answer\'d I, \"return\'d; an art\nWhich yours have shown, they are not skill\'d to learn.\"\n     Then, peering forth from the unclosed jaw,\nRose from his side a shade, high as the chin,\nLeaning, methought, upon its knees uprais\'d.\nIt look\'d around, as eager to explore\nIf there were other with me; but perceiving\nThat fond imagination quench\'d, with tears\nThus spake:  \"If thou through this blind prison go\'st.\nLed by thy lofty genius and profound,\nWhere is my son? and wherefore not with thee?\"\n     I straight replied:  \"Not of myself I come,\nBy him, who there expects me, through this clime\nConducted, whom perchance Guido thy son\nHad in contempt.\"  Already had his words\nAnd mode of punishment read me his name,\nWhence I so fully answer\'d.  He at once\nExclaim\'d, up starting, \"How! said\'st thou he HAD?\nNo longer lives he?  Strikes not on his eye\nThe blessed daylight?\"  Then of some delay\nI made ere my reply aware, down fell\nSupine, not after forth appear\'d he more.\n     Meanwhile the other, great of soul, near whom\nI yet was station\'d, chang\'d not count\'nance stern,\nNor mov\'d the neck, nor bent his ribbed side.\n\"And if,\" continuing the first discourse,\n\"They in this art,\" he cried, \"small skill have shown,\nThat doth torment m");
    strcat(expected_filecontent, "e more e\'en than this bed.\nBut not yet fifty times shall be relum\'d\nHer aspect, who reigns here Queen of this realm,\nEre thou shalt know the full weight of that art.\nSo to the pleasant world mayst thou return,\nAs thou shalt tell me, why in all their laws,\nAgainst my kin this people is so fell?\"\n     \"The slaughter and great havoc,\" I replied,\n\"That colour\'d Arbia\'s flood with crimson stain--\nTo these impute, that in our hallow\'d dome\nSuch orisons ascend.\"  Sighing he shook\nThe head, then thus resum\'d:  \"In that affray\nI stood not singly, nor without just cause\nAssuredly should with the rest have stirr\'d;\nBut singly there I stood, when by consent\nOf all, Florence had to the ground been raz\'d,\nThe one who openly forbad the deed.\"\n     \"So may thy lineage find at last repose,\"\nI thus adjur\'d him, \"as thou solve this knot,\nWhich now involves my mind.  If right I hear,\nYe seem to view beforehand, that which time\nLeads with him, of the present uninform\'d.\"\n     \"We view, as one who hath an evil sight,\"\nHe answer\'d, \"plainly, objects far remote:\nSo much of his large spendour yet imparts\nThe\' Almighty Ruler; but when they approach\nOr actually exist, our intellect\nThen wholly fails, nor of your human state\nExcept what others bring us know we aught.\nHence therefore mayst thou understand, that all\nOur knowledge in that instant shall expire,\nWhen on futurity the portals close.\"\n     Then conscious of my fault, and by remorse\nSmitten, I added thus:  \"Now shalt thou say\nTo him there fallen, that his offspring still\nIs to the living join\'d; and bid him know,\nThat if from answer silent I abstain\'d,\n\'Twas that my thought was occupied intent\nUpon that error, which thy help hath solv\'d.\"\n     But now my master summoning me back\nI heard, and with more eager haste besought\nThe spirit to inform me, who with him\nPartook his lot.  He answer thus return\'d:\n     \"More than a thousand with me here are laid\nWithin is Frederick, second of that name,\nAnd the Lord Cardinal, and of the rest\nI speak not.\"  He, this said, from sight withdrew.\nBut I my steps towards the ancient bard\nReverting, ruminated on the words\nBetokening me such ill.  Onward he mov\'d,\nAnd thus in going question\'d:  \"Whence the\' amaze\nThat holds thy senses wrapt?\"  I satisfied\nThe\' inquiry, and the sage enjoin\'d me straight:\n\"Let thy safe memory store what thou hast heard\nTo thee importing harm; and note thou this,\"\nWith his rais\'d finger bidding me take heed,\n     \"When thou shalt stand before her gracious beam,\nWhose bright eye all surveys, she of thy life\nThe future tenour will to thee unfold.\"\n     Forthwith he to the left hand turn\'d his feet:\nWe left the wall, and tow\'rds the middle space\nWent by a path, that to a valley strikes;\nWhich e\'en thus high exhal\'d its noisome steam.\n\n\n\nCANTO XI\n\nUPON the utmost verge of a high bank,\nBy craggy rocks environ\'d round, we came,\nWhere woes beneath more cruel yet were stow\'d:\nAnd here to shun the horrible excess\nOf fetid exhalation, upward cast\nFrom the profound abyss, behind the lid\nOf a great monument we stood retir\'d,\nWhereon this scroll I mark\'d:  \"I have in charge\nPope Anastasius, whom Photinus drew\nFrom the right path.--Ere our descent behooves\nWe make delay, that somewhat first the sense,\nTo the dire breath accustom\'d, afterward\nRegard it not.\"  My master thus; to whom\nAnswering I spake:  \"Some compensation find\nThat the time past not wholly lost.\"  He then:\n\"Lo! how my thoughts e\'en to thy wishes tend!\nMy son! within these rocks,\" he thus began,\n\"Are three close circles in gradation plac\'d,\nAs these which now thou leav\'st. Each one is full\nOf spirits accurs\'d; but that the sight alone\nHereafter may suffice thee, listen how\nAnd for what cause in durance they abide.\n     \"Of all malicious act abhorr\'d in heaven,\nThe end is injury; and all such end\nEither by force or fraud works other\'s woe\nBut fraud, because of man peculiar evil,\nTo God is more displeasing; and beneath\nThe fraudulent are therefore doom\'d to\' endure\nSeverer pang.  The violent occupy\nAll the first circle; and because to force\nThree persons are obnoxious, in three roun");
    strcat(expected_filecontent, "ds\nHach within other sep\'rate is it fram\'d.\nTo God, his neighbour, and himself, by man\nForce may be offer\'d; to himself I say\nAnd his possessions, as thou soon shalt hear\nAt full.  Death, violent death, and painful wounds\nUpon his neigh");

                struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "SEVEN.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 12521; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 25: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST25(void)
{
    // informacje o teście
    test_start(25, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[7472] = "";

                strcat(expected_filecontent, "t it out of the\nkingdom, because it was the land of the church, and that it was\nburied by the river Verde, on the borders of the kingdom and of\nCarapagna. this, however, we do not affirm.\"  G. Villani, Hist.\nl. vii.  c. 9.\n\nv. 111.  Costanza.]  See Paradise Canto III.  v. 121.\n\nv. 112.  My fair daughter.]  Costanza, the daughter of Manfredi,\nand wife of Peter III.  King of Arragon, by whom she was mother\nto  Frederick, King of Sicily and James, King of Arragon With the\nlatter of these she was at Rome 1296. See G. Villani, 1. viii. c.\n18. and notes to Canto VII.\n\nv. 122.  Clement.]  Pope Clement IV.\n\nv. 127.  The stream of Verde.]  A river near Ascoli, that falls\ninto he Toronto. The \"xtinguished lights \" formed part of the\nceremony t the interment of one excommunicated.\n\nv. 130.  Hope.]\nMentre che la speranza ha fior del verde.\nTasso, G. L. c. xix. st. 53.\n--infin che verde e fior di speme.\n\nCANTO IV\n\nv. 1.  When.] It must be owned the beginning of this Canto is\nsomewhat obscure. Bellutello refers, for an elucidation of it, to\nthe reasoning of Statius in the twenty-fifth canto. Perhaps some\nillustration may be derived from the following, passage in\nSouth\'s Sermons, in which I have ventured to supply the words\nbetween crotchets that seemed to be wanting to complete\nthe sense. Now whether these three, judgement memory, and\ninvention, are three distinct things, both in being distinguished\nfrom one another, and likewise from the substance of the soul\nitself, considered without any such faculties, (or whether the\nsoul be one individual substance) but only receiving these\nseveral denominations rom the several respects arising from the\nseveral actions exerted immediately by itself upon several\nobjects, or several qualities of the same object, I say whether\nof these it is, is not easy to decide, and it is well that it is\nnot necessary Aquinas, and most with him, affirm the former, and\nScotus with his followers the latter.\" Vol. iv. Serm. 1.\n\nv. 23.  Sanleo.]  A fortress on the summit of Montefeltro.\n\nv. 24.  Noli.]  In the Genoese territory, between Finale and\nSavona.\n\nv. 25.  Bismantua.]  A steep mountain in the territory of Reggio.\n\nv. 55.  From the left.]  Vellutello observes an imitation of\nLucan in this passage:\n\nIgnotum vobis, Arabes, venistis in orbem,\nUmbras mirati nemornm non ire sinistras.\nPhars.  s. 1.  iii. 248\n\nv. 69 Thou wilt see.]  \"If you consider that this mountain of\nPurgatory and that of Sion are antipodal to each other, you will\nperceive that the sun must rise on opposite sides of the\nrespective eminences.\"\n\nv. 119.  Belacqua.]  Concerning this man, the commentators afford\nno information.\n\nCANTO V\n\nv. 14.  Be as a tower.]  Sta  ome torre ferma\n\nBerni, Orl.  Inn. 1. 1. c. xvi. st. 48:\nIn quei due piedi sta fermo il gigante\nCom\' una torre in mezzo d\'un castello.\n\nAnd Milton, P. L. b. i.  591.\nStood like a tower.\n\nv. 36.  Ne\'er saw I fiery vapours.]  Imitated by Tasso, G. L, c.\nxix t. 62:\nTal suol fendendo liquido sereno\nStella cader della gran madre in seno.\n\nAnd by Milton, P. L. b. iv. 558:\nSwift as a shooting star\nIn autumn thwarts the night, when vapours fir\'d\nImpress the air.\n\nv. 67.  That land.]  The Marca d\'Ancona, between Romagna and\nApulia, the kingdom of Charles of Anjou.\n\nv. 76.  From thence I came.]  Giacopo del Cassero, a citizen of\nFano who having spoken ill of Azzo da Este, Marquis of Ferrara,\nwas by his orders put to death.  Giacopo, was overtaken by the\nassassins at Oriaco a place near the Brenta, from whence, if he\nhad fled towards Mira, higher up on that river, instead of making\nfor the marsh on the sea shore, he might have escaped.\n\nv. 75.  Antenor\'s land.]  The city of Padua, said to be founded\nby Antenor.\n\nv. 87.  Of Montefeltro I.]  Buonconte (son of Guido da\nMontefeltro, whom we have had in the twenty-seventh Canto of\nHell) fell in the battle of Campaldino (1289), fighting on the\nside of the Aretini.\n\nv. 88.  Giovanna.]  Either the wife, or kinswoman, of Buonconte.\n\nv. 91.  The hermit\'s seat.]  The hermitage of Camaldoli.\n\nv. 95.  Where its name is cancel\'d.]  That is, between Bibbiena\na");
    strcat(expected_filecontent, "nd Poppi, where the Archiano falls into the Arno.\n\nv. 115.  From Pratomagno to the mountain range.]  From Pratomagno\nnow called Prato Vecchio (which divides the Valdarno from\nCasentino) as far as to the Apennine.\n\nv. 131.  Pia.] She is said to have been a Siennese lady, of the\nfamily of Tolommei, secretly made away with by her husband, Nello\ndella Pietra, of the same city, in Maremma, where he had some\npossessions.\n\nCANTO VI\n\nv. 14.  Of Arezzo him.]  Benincasa of Arezzo, eminent for his\nskill in jurisprudence, who, having condemned to death Turrino da\nTurrita brother of Ghino di Tacco, for his robberies in Maremma,\nwas murdered by Ghino, in an apartment of his own house, in the\npresence of many witnesses. Ghino was not only suffered to escape\nin safety, but (as the commentators inform us) obtained so high a\nreputation by the liberality with which he was accustomed to\ndispense the fruits of his plunder, and treated those who fell\ninto his hands with so much courtesy, that he was afterwards\ninvited to Rome, and knighted by Boniface VIII. A story is told\nof him by Boccaccio, G. x. N. 2.\n\nv. 15.  Him beside.]  Ciacco de\' Tariatti of Arezzo.  He is said\nto have been carried by his horse into the Arno, and there\ndrowned, while he was in pursuit of certain of his enemies.\n\nv. 17.  Frederic Novello.]  Son of the Conte Guido da Battifolle,\nand slain by one of the family of Bostoli.\n\nv. 18.  Of Pisa he.]  Farinata de\' Scornigiani of Pisa.  His\nfather Marzuco, who had entered the order of the Frati Minori, so\nentirely overcame the feelings of resentment, that he even kissed\nthe hands of the slayer of his son, and, as he was following the\nfuneral, exhorted his kinsmen to reconciliation.\n\nv. 20.  Count 0rso.]  Son of Napoleone da Cerbaia, slain by\nAlberto da Mangona, his uncle.\n\nv. 23.  Peter de la Brosse.]  Secretary of Philip III  of France.\nThe courtiers, envying the high place which he held in the king\'s\nfavour, prevailed on Mary of Brabant to charge him falsely with\nan attempt upon her person for which supposed crime he suffered\ndeath. So say the Italian commentators.  Henault represents the\nmatter very differently: \"Pierre de la Brosse, formerly barber to\nSt. Louis, afterwards the favorite of Philip, fearing the too\ngreat attachment of the king for his wife Mary, accuses this\nprincess of having poisoned Louis, eldest son of Philip, by his\nfirst marriage. This calumny is discovered by a nun of Nivelle in\nFlanders.  La Brosse is hung.\" Abrege Chron. t. 275, &c.\n\nv. 30.  In thy text.]  He refers to Virgil, Aen. 1, vi.  376.\nDesine fata deum flecti sperare precando, 37. The sacred height\nOf judgment. Shakespeare, Measure for Measure, a. ii. s. 2.\nIf he, which is the top of judgment\n\nv. 66.  Eyeing us as a lion on his watch.]\nA guisa di Leon quando si posa.\nA line taken by Tasso, G.  L. c. x. st. 56.\n\nv. 76.  Sordello.]  The history of Sordello\'s life is wrapt in\nthe obscurity of romance.  That he distinguished himself by his\nskill in Provencal poetry is certain. It is probable that he was\nborn towards the end of the twelfth, and died about the middle of\nthe succeeding century.  Tiraboschi has taken much pains to sift\nall the notices he could collect relating to him.  Honourable\nmention of his name is made by our Poet in the Treatise de Vulg.\nEloq.  1. i. c. 15.\n\nv. 76.  Thou inn of grief.]\nThou most beauteous inn\nWhy should h");

                struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "QUESTION.TX");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 7471; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 26: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST26(void)
{
    // informacje o teście
    test_start(26, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                char expected_filecontent[11808] = "";

                strcat(expected_filecontent, "ucca: and that face beyond him, pierc\'d\nUnto a leaner fineness than the rest,\nHad keeping of the church: he was of Tours,\nAnd purges by wan abstinence away\nBolsena\'s eels and cups of muscadel.\"\n     He show\'d me many others, one by one,\nAnd all, as they were nam\'d, seem\'d well content;\nFor no dark gesture I discern\'d in any.\nI saw through hunger Ubaldino grind\nHis teeth on emptiness; and Boniface,\nThat wav\'d the crozier o\'er a num\'rous flock.\nI saw the Marquis, who tad time erewhile\nTo swill at Forli with less drought, yet so\nWas one ne\'er sated.  I howe\'er, like him,\nThat gazing \'midst a crowd, singles out one,\nSo singled him of Lucca; for methought\nWas none amongst them took such note of me.\nSomewhat I heard him whisper of Gentucca:\nThe sound was indistinct, and murmur\'d there,\nWhere justice, that so strips them, fix\'d her sting.\n     \"Spirit!\" said I, \"it seems as thou wouldst fain\nSpeak with me.  Let me hear thee.  Mutual wish\nTo converse prompts, which let us both indulge.\"\n     He, answ\'ring, straight began: \"Woman is born,\nWhose brow no wimple shades yet, that shall make\nMy city please thee, blame it as they may.\nGo then with this forewarning.  If aught false\nMy whisper too implied, th\' event shall tell\nBut say, if of a  truth I see the man\nOf that new lay th\' inventor, which begins\nWith \'Ladies, ye that con the lore of love\'.\"\n     To whom I thus:  \"Count of me but as one\nWho am the scribe of love; that, when he breathes,\nTake up my pen, and, as he dictates, write.\"\n     \"Brother!\" said he, \"the hind\'rance which once held\nThe notary with Guittone and myself,\nShort of that new and sweeter style I hear,\nIs now disclos\'d.  I see how ye your plumes\nStretch, as th\' inditer guides them; which, no question,\nOurs did not.  He that seeks a grace beyond,\nSees not the distance parts one style from other.\"\nAnd, as contented, here he held his peace.\n     Like as the bird, that winter near the Nile,\nIn squared regiment direct their course,\nThen stretch themselves in file for speedier flight;\nThus all the tribe of spirits, as they turn\'d\nTheir visage, faster deaf, nimble alike\nThrough leanness and desire.  And as a man,\nTir\'d With the motion of a trotting steed,\nSlacks pace, and stays behind his company,\nTill his o\'erbreathed lungs keep temperate time;\nE\'en so Forese let that holy crew\nProceed, behind them lingering at my side,\nAnd saying: \"When shall I again behold thee?\"\n     \"How long my life may last,\" said I, \"I know not;\nThis know, how soon soever I return,\nMy wishes will before me have arriv\'d.\nSithence the place, where I am set to live,\nIs, day by day, more scoop\'d of all its good,\nAnd dismal ruin seems to threaten it.\"\n     \"Go now,\" he cried:  \"lo!  he, whose guilt is most,\nPasses before my vision, dragg\'d at heels\nOf an infuriate beast.  Toward the vale,\nWhere guilt hath no redemption, on it speeds,\nEach step increasing swiftness on the last;\nUntil a blow it strikes, that leaveth him\nA corse most vilely shatter\'d.  No long space\nThose wheels have yet to roll\"  (therewith his eyes\nLook\'d up to heav\'n) \"ere thou shalt plainly see\nThat which my words may not more plainly tell.\nI quit thee: time is precious here: I lose\nToo much, thus measuring my pace with shine.\"\n     As from a troop of well-rank\'d chivalry\nOne knight, more enterprising than the rest,\nPricks forth at gallop, eager to display\nHis prowess in the first encounter prov\'d\nSo parted he from us with lengthen\'d strides,\nAnd left me on the way with those twain spirits,\nWho were such mighty marshals of the world.\n     When he beyond us had so fled mine eyes\nNo nearer reach\'d him, than my thought his words,\nThe branches of another fruit, thick hung,\nAnd blooming fresh, appear\'d.  E\'en as our steps\nTurn\'d thither, not far off it rose to view.\nBeneath it were a multitude, that rais\'d\nTheir hands, and shouted forth I know not What\nUnto the boughs; like greedy and fond brats,\nThat beg, and answer none obtain from him,\nOf whom they beg; but more to draw them on,\nHe at arm\'s length the object of their wish\nAbove them holds aloft, and hides it not.\n     At length, as un");
    strcat(expected_filecontent, "deceiv\'d they went their way:\nAnd we approach the tree, who vows and tears\nSue to in vain, the mighty tree.  \"Pass on,\nAnd come not near.  Stands higher up the wood,\nWhereof Eve tasted, and from it was ta\'en\n\'this plant.\" Such sounds from midst the thickets came.\nWhence I, with either bard, close to the side\nThat rose, pass\'d forth beyond.  \"Remember,\" next\nWe heard, \"those noblest creatures of the clouds,\nHow they their twofold bosoms overgorg\'d\nOppos\'d in fight to Theseus:  call to mind\nThe Hebrews, how effeminate they stoop\'d\nTo ease their thirst; whence Gideon\'s ranks were thinn\'d,\nAs he to Midian march\'d adown the hills.\"\n     Thus near one border coasting, still we heard\nThe sins of gluttony, with woe erewhile\nReguerdon\'d.  Then along the lonely path,\nOnce more at large, full thousand paces on\nWe travel\'d, each contemplative and mute.\n     \"Why pensive journey thus ye three alone?\"\nThus suddenly a voice exclaim\'d: whereat\nI shook, as doth a scar\'d and paltry beast;\nThen rais\'d my head to look from whence it came.\n     Was ne\'er, in furnace, glass, or metal seen\nSo bright and glowing red, as was the shape\nI now beheld.  \"If ye desire to mount,\"\nHe cried, \"here must ye turn.  This way he goes,\nWho goes in quest of peace.\"  His countenance\nHad dazzled me; and to my guides I fac\'d\nBackward, like one who walks, as sound directs.\n     As when, to harbinger the dawn, springs up\nOn freshen\'d wing the air of May, and breathes\nOf fragrance, all impregn\'d with herb and flowers,\nE\'en such a wind I felt upon my front\nBlow gently, and the moving of a wing\nPerceiv\'d, that moving shed ambrosial smell;\nAnd then a voice:  \"Blessed are they, whom grace\nDoth so illume, that appetite in them\nExhaleth no inordinate desire,\nStill hung\'ring as the rule of temperance wills.\"\n\n\n\nCANTO XXV\n\nIt was an hour, when he who climbs, had need\nTo walk uncrippled: for the sun had now\nTo Taurus the meridian circle left,\nAnd to the Scorpion left the night.  As one\nThat makes no pause, but presses on his road,\nWhate\'er betide him, if some urgent need\nImpel: so enter\'d we upon our way,\nOne before other; for, but singly, none\nThat steep and narrow scale admits to climb.\n     E\'en as the young stork lifteth up his wing\nThrough wish to fly, yet ventures not to quit\nThe nest, and drops it; so in me desire\nOf questioning my guide arose, and fell,\nArriving even to the act, that marks\nA man prepar\'d for speech.  Him all our haste\nRestrain\'d not, but thus spake the sire belov\'d:\nFear not to speed the shaft, that on thy lip\nStands trembling for its flight.\"  Encourag\'d thus\nI straight began:  \"How there can leanness come,\nWhere is no want of nourishment to feed?\"\n     \"If thou,\" he answer\'d, \"hadst remember\'d thee,\nHow Meleager with the wasting brand\nWasted alike, by equal fires consm\'d,\nThis would not trouble thee: and hadst thou thought,\nHow in the mirror your reflected form\nWith mimic motion vibrates, what now seems\nHard, had appear\'d no harder than the pulp\nOf summer fruit mature.  But that thy will\nIn certainty may find its full repose,\nLo Statius here!  on him I call, and pray\nThat he would now be healer of thy wound.\"\n     \"If in thy presence I unfold to him\nThe secrets of heaven\'s vengeance, let me plead\nThine own injunction, to exculpate me.\"\nSo Statius answer\'d, and forthwith began:\n\"Attend my words, O son, and in thy mind\nReceive them: so shall they be light to clear\nThe doubt thou offer\'st. Blood, concocted well,\nWhich by the thirsty veins is ne\'er imbib\'d,\nAnd rests as food superfluous, to be ta\'en\nFrom the replenish\'d table, in the heart\nDerives effectual virtue, that informs\nThe several human limbs, as being that,\nWhich passes through the veins itself to make them.\nYet more concocted it descends, where shame\nForbids to mention: and from thence distils\nIn natural vessel on another\'s blood.\nThen each unite together, one dispos\'d\nT\' endure, to act the other, through meet frame\nOf its recipient mould: that being reach\'d,\nIt \'gins to work, coagulating first;\nThen vivifies what its own substance caus\'d\nTo bear.  With animation now indued,\nThe active virt");
    strcat(expected_filecontent, "ue (differing from a plant\nNo further, than that this is on the way\nAnd at its limit that) continues yet\nTo operate, that now it moves, and feels,\nAs sea sponge clinging to the rock: and there\nAssumes th\' organic powers its seed convey\'d.\n\'This is the period, son!  at which the virtue,\nThat from the generating heart proceeds,\nIs pliant and expansive; for each limb\nIs in the heart by forgeful nature plann\'d.\nHow babe of animal becomes, remains\nFor thy consid\'ring.  At this point, more wise,\nThan thou hast err\'d, making the soul disjoin\'d\nFrom passive intellect, because he saw\nNo organ for the latter\'s use assign\'d.\n     \"Open thy bosom to the truth that comes.\nKnow soon as in the embryo, to the brain,\nArticulation is complete, then turns\nThe primal Mover with a smile of joy\nOn such great work of nature, and imbreathes\nNew spirit replete with virtue, that what here\nActive it finds, to its own substance draws,\nAnd forms an individual soul, that lives,\nAnd feels, and bends reflective on itself.\nAnd that thou less mayst marvel at the word,\nMark the sun\'s heat, how that to wine doth change,\nMix\'d with the moisture filter\'d through the vine.\n     \"When Lachesis hath spun the thread, the soul\nTakes with her both the human and divine,\nMemory, intelligence, and will, in act\nFar keener than before, the other powers\nInactive all and mute.  No pause allow\'d,\nIn wond\'rous sort self-moving, to one strand\nOf those, where the departed roam, she falls,\nHere learns her destin\'d path.  Soon as the place\nReceives her, round the plastic virtue beams,\nDistinct as in the living limbs before:\nAnd as the air, when saturate with showers,\nThe casual beam refracting, decks itself\nWith many a hue; so here the ambient air\nWeareth that form, which influence of the soul\nImprints on it; and like the flame, that where\nThe fire moves, thither follows, so henceforth\nThe new form on the spirit follows still:\nHence hath it semblance, and is shadow call\'d,\nWith each sense even to the sight endued:\nHence speech is ours, hence laughter, tears, and sighs\nWhich thou mayst oft have witness\'d on the mount\nTh\' obedient shadow fails not to present\nWhatever varying passion moves within us.\nAnd this the cause of what thou marvel\'st at.\"\n     Now the last flexure of our way we reach\'d,\nAnd to the right hand turning, other care\nAwaits us.  Here the rocky precipice\nHurls forth redundant flames, and from the rim\nA blast upblown, with forcible rebuff\nDriveth them back, sequester\'d from its bound.\n     Behoov\'d us, one by one, along the side,\nThat border\'d on the void, to pass; and I\nFear\'d on one hand the fire, on th\' other fear\'d\nHeadlong to fall: when thus th\' instructor warn\'d:\n\"Strict rein must in this place direct the eyes.\nA little swerving and the way is lost.\"\n     Then from the bosom of the burning mass,\n\"O God of mercy!\" heard I sung; and felt\nNo less desire to turn.  And when I saw\nSpirits along the flame proceeding, I\nBetween their footsteps and mine own was fain\nTo share by turns my view.  At the hymn\'s close\nThey shouted loud, \"I do not know a man;\"\nThen in low voice again took up the strain,\nWhich once more ended, \"To the wood,\" they cried,\n\"Ran Dian, and drave forth Callisto, stung\nWith Cytherea\'s poison:\" then return\'d\nUnto their song; then marry a pair extoll\'d,\nWho liv\'d in virtue chastely, and the bands\nOf wedded love.  Nor from that task, I ween,\nSurcease they; whilesoe\'er the scorching fire\nEnclasps them.  Of such skill appliance needs\nTo medicine the wound, that healeth last.\n\n\n\nCANTO XXVI\n\nWhile singly thus along the rim we walk\'d,\nOft the good master warn\'d me:  \"Look thou well.\nA");

                struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct file_t* file = file_open(volume, "TOUCH.BIN");
                test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                for (int i = 0; i < 11807; ++i)
                {
                    char c;
                    int res = file_read(&c, 1, 1, file);
                    test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                    test_error(c == expected_filecontent[i], "Funkcja file_read() powinna odczytać w kroku %d znak %c, a odczytała znak %c", i, expected_filecontent[i], c);
                }

                char c;
                int res = file_read(&c, 1, 1, file);
                test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);

                file_close(file);
                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 27: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST27(void)
{
    // informacje o teście
    test_start(27, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(10240, 1);
            char expected_filecontent[10241] = "";

            strcat(expected_filecontent, "ator, and remains\nEver between the sun and winter) for the cause\nThou hast assign\'d, from hence toward the north\nDeparts, when those who in the Hebrew land\nInhabit, see it tow\'rds the warmer part.\nBut if it please thee, I would gladly know,\nHow far we have to journey: for the hill\nMounts higher, than this sight of mine can mount.\"\n     He thus to me:  \"Such is this steep ascent,\nThat it is ever difficult at first,\nBut, more a man proceeds, less evil grows.\nWhen pleasant it shall seem to thee, so much\nThat upward going shall be easy to thee.\nAs in a vessel to go down the tide,\nThen of this path thou wilt have reach\'d the end.\nThere hope to rest thee from thy toil.  No more\nI answer, and thus far for certain know.\"\nAs he his words had spoken, near to us\nA voice there sounded:  \"Yet ye first perchance\nMay to repose you by constraint be led.\"\nAt sound thereof each turn\'d, and on the left\nA huge stone we beheld, of which nor I\nNor he before was ware.  Thither we drew,\nfind there were some, who in the shady place\nBehind the rock were standing, as a man\nThru\' idleness might stand.  Among them one,\nWho seem\'d to me much wearied, sat him down,\nAnd with his arms did fold his knees about,\nHolding his face between them downward bent.\n     \"Sweet Sir!\"  I cry\'d, \"behold that man, who shows\nHimself more idle, than if laziness\nWere sister to him.\"  Straight he turn\'d to us,\nAnd, o\'er the thigh lifting his face, observ\'d,\nThen in these accents spake:  \"Up then, proceed\nThou valiant one.\"  Straight who it was I knew;\nNor could the pain I felt (for want of breath\nStill somewhat urg\'d me) hinder my approach.\nAnd when I came to him, he scarce his head\nUplifted, saying \"Well hast thou discern\'d,\nHow from the left the sun his chariot leads.\"\n     His lazy acts and broken words my lips\nTo laughter somewhat mov\'d; when I began:\n\"Belacqua, now for thee I grieve no more.\nBut tell, why thou art seated upright there?\nWaitest thou escort to conduct thee hence?\nOr blame I only shine accustom\'d ways?\"\nThen he:  \"My brother, of what use to mount,\nWhen to my suffering would not let me pass\nThe bird of God, who at the portal sits?\nBehooves so long that heav\'n first bear me round\nWithout its limits, as in life it bore,\nBecause I to the end repentant Sighs\nDelay\'d, if prayer do not aid me first,\nThat riseth up from heart which lives in grace.\nWhat other kind avails, not heard in heaven?\"\'\n     Before me now the Poet up the mount\nAscending, cried:  \"Haste thee, for see the sun\nHas touch\'d the point meridian, and the night\nNow covers with her foot Marocco\'s shore.\"\n\n\n\nCANTO V\n\nNow had I left those spirits, and pursued\nThe steps of my Conductor, when beheld\nPointing the finger at me one exclaim\'d:\n\"See how it seems as if the light not shone\nFrom the left hand of him beneath, and he,\nAs living, seems to be led on.\"  Mine eyes\nI at that sound reverting, saw them gaze\nThrough wonder first at me, and then at me\nAnd the light broken underneath, by turns.\n\"Why are thy thoughts thus riveted?\"  my guide\nExclaim\'d, \"that thou hast slack\'d thy pace?  or how\nImports it thee, what thing is whisper\'d here?\nCome after me, and to their babblings leave\nThe crowd. Be as a tower, that, firmly set,\nShakes not its top for any blast that blows!\nHe, in whose bosom thought on thought shoots out,\nStill of his aim is wide, in that the one\nSicklies and wastes to nought the other\'s strength.\"\n     What other could I answer save \"I come?\"\nI said it, somewhat with that colour ting\'d\nWhich ofttimes pardon meriteth for man.\n     Meanwhile traverse along the hill there came,\nA little way before us, some who sang\nThe \"Miserere\" in responsive Strains.\nWhen they perceiv\'d that through my body I\nGave way not for the rays to pass, their song\nStraight to a long and hoarse exclaim they chang\'d;\nAnd two of them, in guise of messengers,\nRan on to meet us, and inquiring ask\'d:\nOf your condition we would gladly learn.\"\n     To them my guide.  \"Ye may return, and bear\nTidings to them who sent you, that his frame\nIs real flesh.  If, as I deem, to view\nHis shade they paus\'d, enough is answer\'d them.\nHim");
    strcat(expected_filecontent, " let them honour, they may prize him well.\"\n     Ne\'er saw I fiery vapours with such speed\nCut through the serene air at fall of night,\nNor August\'s clouds athwart the setting sun,\nThat upward these did not in shorter space\nReturn; and, there arriving, with the rest\nWheel back on us, as with loose rein a troop.\n     \"Many,\" exclaim\'d the bard, \"are these, who throng\nAround us: to petition thee they come.\nGo therefore on, and listen as thou go\'st.\"\n     \"O spirit!  who go\'st on to blessedness\nWith the same limbs, that clad thee at thy birth.\"\nShouting they came, \"a little rest thy step.\nLook if thou any one amongst our tribe\nHast e\'er beheld, that tidings of him there\nThou mayst report.  Ah, wherefore go\'st thou on?\nAh wherefore tarriest thou not?  We all\nBy violence died, and to our latest hour\nWere sinners, but then warn\'d by light from heav\'n,\nSo that, repenting and forgiving, we\nDid issue out of life at peace with God,\nWho with desire to see him fills our heart.\"\n     Then I:  \"The visages of all I scan\nYet none of ye remember.  But if aught,\nThat I can do, may please you, gentle spirits!\nSpeak; and I will perform it, by that peace,\nWhich on the steps of guide so excellent\nFollowing from world to world intent I seek.\"\n     In answer he began:  \"None here distrusts\nThy kindness, though not promis\'d with an oath;\nSo as the will fail not for want of power.\nWhence I, who sole before the others speak,\nEntreat thee, if thou ever see that land,\nWhich lies between Romagna and the realm\nOf Charles, that of thy courtesy thou pray\nThose who inhabit Fano, that for me\nTheir adorations duly be put up,\nBy which I may purge off my grievous sins.\nFrom thence I came.  But the deep passages,\nWhence issued out the blood wherein I dwelt,\nUpon my bosom in Antenor\'s land\nWere made, where to be more secure I thought.\nThe author of the deed was Este\'s prince,\nWho, more than right could warrant, with his wrath\nPursued me.  Had I towards Mira fled,\nWhen overta\'en at Oriaco, still\nMight I have breath\'d. But to the marsh I sped,\nAnd in the mire and rushes tangled there\nFell, and beheld my life-blood float the plain.\"\n     Then said another:  \"Ah! so may the wish,\nThat takes thee o\'er the mountain, be fulfill\'d,\nAs thou shalt graciously give aid to mine.\nOf Montefeltro I; Buonconte I:\nGiovanna nor none else have care for me,\nSorrowing with these I therefore go.\"  I thus:\n\"From Campaldino\'s field what force or chance\nDrew thee, that ne\'er thy sepulture was known?\"\n     \"Oh!\"  answer\'d he, \"at Casentino\'s foot\nA stream there courseth, nam\'d Archiano, sprung\nIn Apennine above the Hermit\'s seat.\nE\'en where its name is cancel\'d, there came I,\nPierc\'d in the heart, fleeing away on foot,\nAnd bloodying the plain.  Here sight and speech\nFail\'d me, and finishing with Mary\'s name\nI fell, and tenantless my flesh remain\'d.\nI will report the truth; which thou again0\nTell to the living.  Me God\'s angel took,\nWhilst he of hell exclaim\'d:  \"O thou from heav\'n!\nSay wherefore hast thou robb\'d me?  Thou of him\nTh\' eternal portion bear\'st with thee away\nFor one poor tear that he deprives me of.\nBut of the other, other rule I make.\"\n     \"Thou knowest how in the atmosphere collects\nThat vapour dank, returning into water,\nSoon as it mounts where cold condenses it.\nThat evil will, which in his intellect\nStill follows evil, came, and rais\'d the wind\nAnd smoky mist, by virtue of the power\nGiven by his nature.  Thence the valley, soon\nAs day was spent, he cover\'d o\'er with cloud\nFrom Pratomagno to the mountain range,\nAnd stretch\'d the sky above, so that the air\nImpregnate chang\'d to water.  Fell the rain,\nAnd to the fosses came all that the land\nContain\'d not; and, as mightiest streams are wont,\nTo the great river with such headlong sweep\nRush\'d, that nought stay\'d its course.  My stiffen\'d frame\nLaid at his mouth the fell Archiano found,\nAnd dash\'d it into Arno, from my breast\nLoos\'ning the cross, that of myself I made\nWhen overcome with pain.  He hurl\'d me on,\nAlong the banks and bottom of his course;\nThen in his muddy spoils encircling wrapt.\"\n     \"Ah!  when thou to th");
    strcat(expected_filecontent, "e world shalt be return\'d,\nAnd rested after thy long road,\" so spake\nNext the third spirit; \"then remember me.\nI once was Pia.  Sienna gave me life,\nMaremma took it from me.  That he knows,\nWho me with jewell\'d ring had first espous\'d.\"\n\n\n\nCANTO VI\n\nWhen from their game of dice men separate,\nHe, who hath lost, remains in sadness fix\'d,\nRevolving in his mind, what luckless throws\nHe cast: but meanwhile all the company\nGo with the other; one before him runs,\nAnd one behind his mantle twitches, one\nFast by his side bids him remember him.\nHe stops not; and each one, to whom his hand\nIs stretch\'d, well knows he bids him stand aside;\nAnd thus he from the press defends himself.\nE\'en such was I in that close-crowding throng;\nAnd turning so my face around to all,\nAnd promising, I \'scap\'d from it with pains.\n     Here of Arezzo him I saw, who fell\nBy Ghino\'s cruel arm; and him beside,\nWho in his chase was swallow\'d by the stream.\nHere Frederic Novello, with his hand\nStretch\'d forth, entreated; and of Pisa he,\nWho put the good Marzuco to such proof\nOf constancy.  Count Orso I beheld;\nAnd from its frame a soul dismiss\'d for spite\nAnd envy, as it said, but for no crime:\nI speak of Peter de la Brosse; and here,\nWhile she yet lives, that Lady of Brabant\nLet her beware; lest for so false a deed\nShe herd with worse than these. When I was freed\nFrom all those spirits, who pray\'d for others\' prayers\nTo hasten on their state of blessedness;\nStraight I began:  \"O thou, my luminary!\nIt seems expressly in thy text denied,\nThat heaven\'s supreme decree can never bend\nTo supplication; yet with this design\nDo these entreat.  Can then their hope be vain,\nOr is thy saying not to me reveal\'d?\"\n     He thus to me:  \"Both what I write is plain,\nAnd these deceiv\'d not in their hope, if well\nThy mind consider, that the sacred height\nOf judgment doth not stoop, because love\'s flame\nIn a short moment all fulfils, which he\nWho sojourns here, in right should satisfy.\nBesides, when I this point concluded thus,\nBy praying no defect could be supplied;\nBec");

            struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "WISH.TXT");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int i;
            for (i = 0; i < 2560; ++i)
            {
                int res = file_read(filecontent + 4 * i, 4, 1, file);
                test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            }

            int res = file_read(filecontent + 4 * i, 4, 1, file);
            test_error(res == 0, "Funkcja file_read() powinna zwrócić wartość 0, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int diff_pos = mem_find_first_difference(filecontent, expected_filecontent, 10240);

            // jeśli jest, to raportuj błąd
            test_error(diff_pos == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                diff_pos, mem_get_byte(filecontent, diff_pos), mem_get_byte(expected_filecontent, diff_pos));

            onerror_compare_memory(expected_filecontent, filecontent, 10240);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 28: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST28(void)
{
    // informacje o teście
    test_start(28, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char *filecontent0 = (char *)calloc(10240, 1);
    char *filecontent1 = (char *)calloc(9688, 1);
    char *filecontent2 = (char *)calloc(10313, 1);
    char *filecontent3 = (char *)calloc(1544, 1);
    char *filecontent4 = (char *)calloc(12521, 1);
    char *filecontent5 = (char *)calloc(7471, 1);
    char *filecontent6 = (char *)calloc(11807, 1);

            char expected_filecontent0[10241] = "";
    char expected_filecontent1[9689] = "";
    char expected_filecontent2[10314] = "";
    char expected_filecontent3[1545] = "";
    char expected_filecontent4[12522] = "";
    char expected_filecontent5[7472] = "";
    char expected_filecontent6[11808] = "";

            strcat(expected_filecontent0, "ator, and remains\nEver between the sun and winter) for the cause\nThou hast assign\'d, from hence toward the north\nDeparts, when those who in the Hebrew land\nInhabit, see it tow\'rds the warmer part.\nBut if it please thee, I would gladly know,\nHow far we have to journey: for the hill\nMounts higher, than this sight of mine can mount.\"\n     He thus to me:  \"Such is this steep ascent,\nThat it is ever difficult at first,\nBut, more a man proceeds, less evil grows.\nWhen pleasant it shall seem to thee, so much\nThat upward going shall be easy to thee.\nAs in a vessel to go down the tide,\nThen of this path thou wilt have reach\'d the end.\nThere hope to rest thee from thy toil.  No more\nI answer, and thus far for certain know.\"\nAs he his words had spoken, near to us\nA voice there sounded:  \"Yet ye first perchance\nMay to repose you by constraint be led.\"\nAt sound thereof each turn\'d, and on the left\nA huge stone we beheld, of which nor I\nNor he before was ware.  Thither we drew,\nfind there were some, who in the shady place\nBehind the rock were standing, as a man\nThru\' idleness might stand.  Among them one,\nWho seem\'d to me much wearied, sat him down,\nAnd with his arms did fold his knees about,\nHolding his face between them downward bent.\n     \"Sweet Sir!\"  I cry\'d, \"behold that man, who shows\nHimself more idle, than if laziness\nWere sister to him.\"  Straight he turn\'d to us,\nAnd, o\'er the thigh lifting his face, observ\'d,\nThen in these accents spake:  \"Up then, proceed\nThou valiant one.\"  Straight who it was I knew;\nNor could the pain I felt (for want of breath\nStill somewhat urg\'d me) hinder my approach.\nAnd when I came to him, he scarce his head\nUplifted, saying \"Well hast thou discern\'d,\nHow from the left the sun his chariot leads.\"\n     His lazy acts and broken words my lips\nTo laughter somewhat mov\'d; when I began:\n\"Belacqua, now for thee I grieve no more.\nBut tell, why thou art seated upright there?\nWaitest thou escort to conduct thee hence?\nOr blame I only shine accustom\'d ways?\"\nThen he:  \"My brother, of what use to mount,\nWhen to my suffering would not let me pass\nThe bird of God, who at the portal sits?\nBehooves so long that heav\'n first bear me round\nWithout its limits, as in life it bore,\nBecause I to the end repentant Sighs\nDelay\'d, if prayer do not aid me first,\nThat riseth up from heart which lives in grace.\nWhat other kind avails, not heard in heaven?\"\'\n     Before me now the Poet up the mount\nAscending, cried:  \"Haste thee, for see the sun\nHas touch\'d the point meridian, and the night\nNow covers with her foot Marocco\'s shore.\"\n\n\n\nCANTO V\n\nNow had I left those spirits, and pursued\nThe steps of my Conductor, when beheld\nPointing the finger at me one exclaim\'d:\n\"See how it seems as if the light not shone\nFrom the left hand of him beneath, and he,\nAs living, seems to be led on.\"  Mine eyes\nI at that sound reverting, saw them gaze\nThrough wonder first at me, and then at me\nAnd the light broken underneath, by turns.\n\"Why are thy thoughts thus riveted?\"  my guide\nExclaim\'d, \"that thou hast slack\'d thy pace?  or how\nImports it thee, what thing is whisper\'d here?\nCome after me, and to their babblings leave\nThe crowd. Be as a tower, that, firmly set,\nShakes not its top for any blast that blows!\nHe, in whose bosom thought on thought shoots out,\nStill of his aim is wide, in that the one\nSicklies and wastes to nought the other\'s strength.\"\n     What other could I answer save \"I come?\"\nI said it, somewhat with that colour ting\'d\nWhich ofttimes pardon meriteth for man.\n     Meanwhile traverse along the hill there came,\nA little way before us, some who sang\nThe \"Miserere\" in responsive Strains.\nWhen they perceiv\'d that through my body I\nGave way not for the rays to pass, their song\nStraight to a long and hoarse exclaim they chang\'d;\nAnd two of them, in guise of messengers,\nRan on to meet us, and inquiring ask\'d:\nOf your condition we would gladly learn.\"\n     To them my guide.  \"Ye may return, and bear\nTidings to them who sent you, that his frame\nIs real flesh.  If, as I deem, to view\nHis shade they paus\'d, enough is answer\'d them.\nHim");
    strcat(expected_filecontent0, " let them honour, they may prize him well.\"\n     Ne\'er saw I fiery vapours with such speed\nCut through the serene air at fall of night,\nNor August\'s clouds athwart the setting sun,\nThat upward these did not in shorter space\nReturn; and, there arriving, with the rest\nWheel back on us, as with loose rein a troop.\n     \"Many,\" exclaim\'d the bard, \"are these, who throng\nAround us: to petition thee they come.\nGo therefore on, and listen as thou go\'st.\"\n     \"O spirit!  who go\'st on to blessedness\nWith the same limbs, that clad thee at thy birth.\"\nShouting they came, \"a little rest thy step.\nLook if thou any one amongst our tribe\nHast e\'er beheld, that tidings of him there\nThou mayst report.  Ah, wherefore go\'st thou on?\nAh wherefore tarriest thou not?  We all\nBy violence died, and to our latest hour\nWere sinners, but then warn\'d by light from heav\'n,\nSo that, repenting and forgiving, we\nDid issue out of life at peace with God,\nWho with desire to see him fills our heart.\"\n     Then I:  \"The visages of all I scan\nYet none of ye remember.  But if aught,\nThat I can do, may please you, gentle spirits!\nSpeak; and I will perform it, by that peace,\nWhich on the steps of guide so excellent\nFollowing from world to world intent I seek.\"\n     In answer he began:  \"None here distrusts\nThy kindness, though not promis\'d with an oath;\nSo as the will fail not for want of power.\nWhence I, who sole before the others speak,\nEntreat thee, if thou ever see that land,\nWhich lies between Romagna and the realm\nOf Charles, that of thy courtesy thou pray\nThose who inhabit Fano, that for me\nTheir adorations duly be put up,\nBy which I may purge off my grievous sins.\nFrom thence I came.  But the deep passages,\nWhence issued out the blood wherein I dwelt,\nUpon my bosom in Antenor\'s land\nWere made, where to be more secure I thought.\nThe author of the deed was Este\'s prince,\nWho, more than right could warrant, with his wrath\nPursued me.  Had I towards Mira fled,\nWhen overta\'en at Oriaco, still\nMight I have breath\'d. But to the marsh I sped,\nAnd in the mire and rushes tangled there\nFell, and beheld my life-blood float the plain.\"\n     Then said another:  \"Ah! so may the wish,\nThat takes thee o\'er the mountain, be fulfill\'d,\nAs thou shalt graciously give aid to mine.\nOf Montefeltro I; Buonconte I:\nGiovanna nor none else have care for me,\nSorrowing with these I therefore go.\"  I thus:\n\"From Campaldino\'s field what force or chance\nDrew thee, that ne\'er thy sepulture was known?\"\n     \"Oh!\"  answer\'d he, \"at Casentino\'s foot\nA stream there courseth, nam\'d Archiano, sprung\nIn Apennine above the Hermit\'s seat.\nE\'en where its name is cancel\'d, there came I,\nPierc\'d in the heart, fleeing away on foot,\nAnd bloodying the plain.  Here sight and speech\nFail\'d me, and finishing with Mary\'s name\nI fell, and tenantless my flesh remain\'d.\nI will report the truth; which thou again0\nTell to the living.  Me God\'s angel took,\nWhilst he of hell exclaim\'d:  \"O thou from heav\'n!\nSay wherefore hast thou robb\'d me?  Thou of him\nTh\' eternal portion bear\'st with thee away\nFor one poor tear that he deprives me of.\nBut of the other, other rule I make.\"\n     \"Thou knowest how in the atmosphere collects\nThat vapour dank, returning into water,\nSoon as it mounts where cold condenses it.\nThat evil will, which in his intellect\nStill follows evil, came, and rais\'d the wind\nAnd smoky mist, by virtue of the power\nGiven by his nature.  Thence the valley, soon\nAs day was spent, he cover\'d o\'er with cloud\nFrom Pratomagno to the mountain range,\nAnd stretch\'d the sky above, so that the air\nImpregnate chang\'d to water.  Fell the rain,\nAnd to the fosses came all that the land\nContain\'d not; and, as mightiest streams are wont,\nTo the great river with such headlong sweep\nRush\'d, that nought stay\'d its course.  My stiffen\'d frame\nLaid at his mouth the fell Archiano found,\nAnd dash\'d it into Arno, from my breast\nLoos\'ning the cross, that of myself I made\nWhen overcome with pain.  He hurl\'d me on,\nAlong the banks and bottom of his course;\nThen in his muddy spoils encircling wrapt.\"\n     \"Ah!  when thou to th");
    strcat(expected_filecontent0, "e world shalt be return\'d,\nAnd rested after thy long road,\" so spake\nNext the third spirit; \"then remember me.\nI once was Pia.  Sienna gave me life,\nMaremma took it from me.  That he knows,\nWho me with jewell\'d ring had first espous\'d.\"\n\n\n\nCANTO VI\n\nWhen from their game of dice men separate,\nHe, who hath lost, remains in sadness fix\'d,\nRevolving in his mind, what luckless throws\nHe cast: but meanwhile all the company\nGo with the other; one before him runs,\nAnd one behind his mantle twitches, one\nFast by his side bids him remember him.\nHe stops not; and each one, to whom his hand\nIs stretch\'d, well knows he bids him stand aside;\nAnd thus he from the press defends himself.\nE\'en such was I in that close-crowding throng;\nAnd turning so my face around to all,\nAnd promising, I \'scap\'d from it with pains.\n     Here of Arezzo him I saw, who fell\nBy Ghino\'s cruel arm; and him beside,\nWho in his chase was swallow\'d by the stream.\nHere Frederic Novello, with his hand\nStretch\'d forth, entreated; and of Pisa he,\nWho put the good Marzuco to such proof\nOf constancy.  Count Orso I beheld;\nAnd from its frame a soul dismiss\'d for spite\nAnd envy, as it said, but for no crime:\nI speak of Peter de la Brosse; and here,\nWhile she yet lives, that Lady of Brabant\nLet her beware; lest for so false a deed\nShe herd with worse than these. When I was freed\nFrom all those spirits, who pray\'d for others\' prayers\nTo hasten on their state of blessedness;\nStraight I began:  \"O thou, my luminary!\nIt seems expressly in thy text denied,\nThat heaven\'s supreme decree can never bend\nTo supplication; yet with this design\nDo these entreat.  Can then their hope be vain,\nOr is thy saying not to me reveal\'d?\"\n     He thus to me:  \"Both what I write is plain,\nAnd these deceiv\'d not in their hope, if well\nThy mind consider, that the sacred height\nOf judgment doth not stoop, because love\'s flame\nIn a short moment all fulfils, which he\nWho sojourns here, in right should satisfy.\nBesides, when I this point concluded thus,\nBy praying no defect could be supplied;\nBec");strcat(expected_filecontent1, "e?\nHe hath in sooth good cause for endless grief,\nWho, for the love of thing that lasteth not,\nDespoils himself forever of that love.\n     As oft along the still and pure serene,\nAt nightfall, glides a sudden trail of fire,\nAttracting with involuntary heed\nThe eye to follow it, erewhile at rest,\nAnd seems some star that shifted place in heav\'n,\nOnly that, whence it kindles, none is lost,\nAnd it is soon extinct; thus from the horn,\nThat on the dexter of the cross extends,\nDown to its foot, one luminary ran\nFrom mid the cluster shone there; yet no gem\nDropp\'d from its foil; and through the beamy list\nLike flame in alabaster, glow\'d its course.\n     So forward stretch\'d him (if of credence aught\nOur greater muse may claim) the pious ghost\nOf old Anchises, in the\' Elysian bower,\nWhen he perceiv\'d his son.  \"O thou, my blood!\nO most exceeding grace divine!  to whom,\nAs now to thee, hath twice the heav\'nly gate\nBeen e\'er unclos\'d?\" so spake the light; whence I\nTurn\'d me toward him; then unto my dame\nMy sight directed, and on either side\nAmazement waited me; for in her eyes\nWas lighted such a smile, I thought that mine\nHad div\'d unto the bottom of my grace\nAnd of my bliss in Paradise.  Forthwith\nTo hearing and to sight grateful alike,\nThe spirit to his proem added things\nI understood not, so profound he spake;\nYet not of choice but through necessity\nMysterious; for his high conception scar\'d\nBeyond the mark of mortals.  When the flight\nOf holy transport had so spent its rage,\nThat nearer to the level of our thought\nThe speech descended, the first sounds I heard\nWere, \"Best he thou, Triunal Deity!\nThat hast such favour in my seed vouchsaf\'d!\"\nThen follow\'d:  \"No unpleasant thirst, tho\' long,\nWhich took me reading in the sacred book,\nWhose leaves or white or dusky never change,\nThou hast allay\'d, my son, within this light,\nFrom whence my voice thou hear\'st; more thanks to her.\nWho for such lofty mounting has with plumes\nBegirt thee.  Thou dost deem thy thoughts to me\nFrom him transmitted, who is first of all,\nE\'en as all numbers ray from unity;\nAnd therefore dost not ask me who I am,\nOr why to thee more joyous I appear,\nThan any other in this gladsome throng.\nThe truth is as thou deem\'st; for in this hue\nBoth less and greater in that mirror look,\nIn which thy thoughts, or ere thou think\'st, are shown.\nBut, that the love, which keeps me wakeful ever,\nUrging with sacred thirst of sweet desire,\nMay be contended fully, let thy voice,\nFearless, and frank and jocund, utter forth\nThy will distinctly, utter forth the wish,\nWhereto my ready answer stands decreed.\"\n     I turn\'d me to Beatrice; and she heard\nEre I had spoken, smiling, an assent,\nThat to my will gave wings; and I began\n\"To each among your tribe, what time ye kenn\'d\nThe nature, in whom naught unequal dwells,\nWisdom and love were in one measure dealt;\nFor that they are so equal in the sun,\nFrom whence ye drew your radiance and your heat,\nAs makes all likeness scant.  But will and means,\nIn mortals, for the cause ye well discern,\nWith unlike wings are fledge.  A mortal I\nExperience inequality like this,\nAnd therefore give no thanks, but in the heart,\nFor thy paternal greeting.  This howe\'er\nI pray thee, living topaz!  that ingemm\'st\nThis precious jewel, let me hear thy name.\"\n     \"I am thy root, O leaf!  whom to expect\nEven, hath pleas\'d me:  \"thus the prompt reply\nPrefacing, next it added;  \"he, of whom\nThy kindred appellation comes, and who,\nThese hundred years and more, on its first ledge\nHath circuited the mountain, was my son\nAnd thy great grandsire.  Well befits, his long\nEndurance should he shorten\'d by thy deeds.\n     \"Florence, within her ancient limit-mark,\nWhich calls her still to matin prayers and noon,\nWas chaste and sober, and abode in peace.\nShe had no armlets and no head-tires then,\nNo purfled dames, no zone, that caught the eye\nMore than the person did.  Time was not yet,\nWhen at his daughter\'s birth the sire grew pale.\nFor fear the age and dowry should exceed\nOn each side just proportion.  House was none\nVoid of its family; nor yet had come\nHardanapalus, to");
    strcat(expected_filecontent1, " exhibit feats\nOf chamber prowess.  Montemalo yet\nO\'er our suburban turret rose; as much\nTo be surpass in fall, as in its rising.\nI saw Bellincione Berti walk abroad\nIn leathern girdle and a clasp of bone;\nAnd, with no artful colouring on her cheeks,\nHis lady leave the glass.  The sons I saw\nOf Nerli and of Vecchio well content\nWith unrob\'d jerkin; and their good dames handling\nThe spindle and the flax; O happy they!\nEach sure of burial in her native land,\nAnd none left desolate a-bed for France!\nOne wak\'d to tend the cradle, hushing it\nWith sounds that lull\'d the parent\'s infancy:\nAnother, with her maidens, drawing off\nThe tresses from the distaff, lectur\'d them\nOld tales of Troy and Fesole and Rome.\nA Salterello and Cianghella we\nHad held as strange a marvel, as ye would\nA Cincinnatus or Cornelia now.\n     \"In such compos\'d and seemly fellowship,\nSuch faithful and such fair equality,\nIn so sweet household, Mary at my birth\nBestow\'d me, call\'d on with loud cries; and there\nIn your old baptistery, I was made\nChristian at once and Cacciaguida; as were\nMy brethren, Eliseo and Moronto.\n     \"From Valdipado came to me my spouse,\nAnd hence thy surname grew.  I follow\'d then\nThe Emperor Conrad; and his knighthood he\nDid gird on me; in such good part he took\nMy valiant service.  After him I went\nTo testify against that evil law,\nWhose people, by the shepherd\'s fault, possess\nYour right, usurping.  There, by that foul crew\nWas I releas\'d from the deceitful world,\nWhose base affection many a spirit soils,\nAnd from the martyrdom came to this peace.\"\n\n\n\nCANTO XVI\n\nO slight respect of man\'s nobility!\nI never shall account it marvelous,\nThat our infirm affection here below\nThou mov\'st to boasting, when I could not choose,\nE\'en in that region of unwarp\'d desire,\nIn heav\'n itself, but make my vaunt in thee!\nYet cloak thou art soon shorten\'d, for that time,\nUnless thou be eked out from day to day,\nGoes round thee with his shears.  Resuming then\nWith greeting such, as Rome, was first to bear,\nBut since hath disaccustom\'d I began;\nAnd Beatrice, that a little space\nWas sever\'d, smil\'d reminding me of her,\nWhose cough embolden\'d (as the story holds)\nTo first offence the doubting Guenever.\n     \"You are my sire,\" said I, \"you give me heart\nFreely to speak my thought: above myself\nYou raise me.  Through so many streams with joy\nMy soul is fill\'d, that gladness wells from it;\nSo that it bears the mighty tide, and bursts not\nSay then, my honour\'d stem!  what ancestors\nWhere those you sprang from, and what years were mark\'d\nIn your first childhood?  Tell me of the fold,\nThat hath Saint John for guardian, what was then\nIts state, and who in it were highest seated?\"\n     As embers, at the breathing of the wind,\nTheir flame enliven, so that light I saw\nShine at my blandishments; and, as it grew\nMore fair to look on, so with voice more sweet,\nYet not in this our modern phrase, forthwith\nIt answer\'d:  \"From the day, when it was said\n\' Hail Virgin!\' to the throes, by which my mother,\nWho now is sainted, lighten\'d her of me\nWhom she was heavy with, this fire had come,\nFive hundred fifty times and thrice, its beams\nTo reilumine underneath the foot\nOf its own lion.  They, of whom I sprang,\nAnd I, had there our birth-place, where the last\nPartition of our city first is reach\'d\nBy him, that runs her annual game.  Thus much\nSuffice of my forefathers: who they were,\nAnd whence they hither came, more honourable\nIt is to pass in silence than to tell.\nAll those, who in that time were there from Mars\nUntil the Baptist, fit to carry arms,\nWere but the fifth of them this day alive.\nBut then the citizen\'s blood, that now is mix\'d\nFrom Campi and Certaldo and Fighine,\nRan purely through the last mechanic\'s veins.\nO how much better were it, that these people\nWere neighbours to you, and that at Galluzzo\nAnd at Trespiano, ye should have your bound\'ry,\nThan to have them within, and bear the stench\nOf Aguglione\'s hind, and Signa\'s, him,\nThat hath his eye already keen for bart\'ring!\nHad not the people, which of all the world\nDegenerates most, been stepdame unto Caesar,\nBu");
    strcat(expected_filecontent1, "t, as a mother, gracious to her son;\nSuch one, as hath become a Florentine,\nAnd trades and traffics, had been turn\'d adrift\nTo Simifonte, where his grandsire ply\'d\nThe beggar\'s craft.  The Conti were possess\'d\nOf Montemurlo still: the Cerchi still\nWere in Acone\'s parish; nor had haply\nFrom Valdigrieve past the Buondelmonte.\nThe city\'s malady hath ever source\nIn the confusion of its persons, as\nThe body\'s, in variety of food:\nAnd the blind bull falls with a steeper plunge,\nThan the blind lamb; and oftentimes one sword\nDoth more and better execution,\nThan five.  Mark Luni, Urbisaglia mark,\nHow they are gone, and after them how go\nChiusi and Sinigaglia; and \'t will seem\nNo longer new or strange to thee to hear,\nThat families fail, when cities have their end.\nAll things, that appertain t\' ye, like yourselves,\nAre mortal: but mortality in some\nYe mark not, they endure so long, and you\nPass by so suddenly.  And as the moon\nDoth, by the rolling of her heav\'nly sphere,\nHide and reveal the strand unceasingly;\nSo fortune deals with Florence.  Hence admire not\nAt what of them I tell thee, whose renown\nTime covers, the first Florentines.  I saw\nThe Ughi, Catilini and Filippi,\nThe Alberichi, Greci and Ormanni,\nNow in their wane, illustrious citizens:\nAnd great as ancient, of Sannella him,\nWith him of Arca saw, and Soldanieri\nAnd Ardinghi, and Bostichi.  At the poop,\nThat now is laden with new felony,\nSo cumb\'rous it may speedily sink the bark,\nThe Ravignani sat, of whom is sprung\nThe Co");strcat(expected_filecontent2, "rtue guides not; that if aught of good\nMy gentle star, or something better gave me,\nI envy not myself the precious boon.\n     As in that season, when the sun least veils\nHis face that lightens all, what time the fly\nGives way to the shrill gnat, the peasant then\nUpon some cliff reclin\'d, beneath him sees\nFire-flies innumerous spangling o\'er the vale,\nVineyard or tilth, where his day-labour lies:\nWith flames so numberless throughout its space\nShone the eighth chasm, apparent, when the depth\nWas to my view expos\'d. As he, whose wrongs\nThe bears aveng\'d, at its departure saw\nElijah\'s chariot, when the steeds erect\nRais\'d their steep flight for heav\'n; his eyes meanwhile,\nStraining pursu\'d them, till the flame alone\nUpsoaring like a misty speck he kenn\'d;\nE\'en thus along the gulf moves every flame,\nA sinner so enfolded close in each,\nThat none exhibits token of the theft.\n     Upon the bridge I forward bent to look,\nAnd grasp\'d a flinty mass, or else had fall\'n,\nThough push\'d not from the height.  The guide, who mark d\nHow I did gaze attentive, thus began:\n\"Within these ardours are the spirits, each\nSwath\'d in confining fire.\"--\"Master, thy word,\"\nI answer\'d, \"hath assur\'d me; yet I deem\'d\nAlready of the truth, already wish\'d\nTo ask thee, who is in yon fire, that comes\nSo parted at the summit, as it seem\'d\nAscending from that funeral pile, where lay\nThe Theban brothers?\"  He replied:  \"Within\nUlysses there and Diomede endure\nTheir penal tortures, thus to vengeance now\nTogether hasting, as erewhile to wrath.\nThese in the flame with ceaseless groans deplore\nThe ambush of the horse, that open\'d wide\nA portal for that goodly seed to pass,\nWhich sow\'d imperial Rome; nor less the guile\nLament they, whence of her Achilles \'reft\nDeidamia yet in death complains.\nAnd there is rued the stratagem, that Troy\nOf her Palladium spoil\'d.\"--\"If they have power\nOf utt\'rance from within these sparks,\" said I,\n\"O master!  think my prayer a thousand fold\nIn repetition urg\'d, that thou vouchsafe\nTo pause, till here the horned flame arrive.\nSee, how toward it with desire I bend.\"\n     He thus:  \"Thy prayer is worthy of much praise,\nAnd I accept it therefore:  but do thou\nThy tongue refrain:  to question them be mine,\nFor I divine thy wish:  and they perchance,\nFor they were Greeks, might shun discourse with thee.\"\n     When there the flame had come, where time and place\nSeem\'d fitting to my guide, he thus began:\n\"O ye, who dwell two spirits in one fire!\nIf living I of you did merit aught,\nWhate\'er the measure were of that desert,\nWhen in the world my lofty strain I pour\'d,\nMove ye not on, till one of you unfold\nIn what clime death o\'ertook him self-destroy\'d.\"\n     Of the old flame forthwith the greater horn\nBegan to roll, murmuring, as a fire\nThat labours with the wind, then to and fro\nWagging the top, as a tongue uttering sounds,\nThrew out its voice, and spake:  \"When I escap\'d\nFrom Circe, who beyond a circling year\nHad held me near Caieta, by her charms,\nEre thus Aeneas yet had nam\'d the shore,\nNor fondness for my son, nor reverence\nOf my old father, nor return of love,\nThat should have crown\'d Penelope with joy,\nCould overcome in me the zeal I had\nT\' explore the world, and search the ways of life,\nMan\'s evil and his virtue.  Forth I sail\'d\nInto the deep illimitable main,\nWith but one bark, and the small faithful band\nThat yet cleav\'d to me.  As Iberia far,\nFar as Morocco either shore I saw,\nAnd the Sardinian and each isle beside\nWhich round that ocean bathes.  Tardy with age\nWere I and my companions, when we came\nTo the strait pass, where Hercules ordain\'d\nThe bound\'ries not to be o\'erstepp\'d by man.\nThe walls of Seville to my right I left,\nOn the\' other hand already Ceuta past.\n\"O brothers!\"  I began, \"who to the west\nThrough perils without number now have reach\'d,\nTo this the short remaining watch, that yet\nOur senses have to wake, refuse not proof\nOf the unpeopled world, following the track\nOf Phoebus. Call to mind from whence we sprang:\nYe were not form\'d to live the life of brutes\nBut virtue to pursue and knowledge high.\nWith these few wo");
    strcat(expected_filecontent2, "rds I sharpen\'d for the voyage\nThe mind of my associates, that I then\nCould scarcely have withheld them.  To the dawn\nOur poop we turn\'d, and for the witless flight\nMade our oars wings, still gaining on the left.\nEach star of the\' other pole night now beheld,\nAnd ours so low, that from the ocean-floor\nIt rose not.  Five times re-illum\'d, as oft\nVanish\'d the light from underneath the moon\nSince the deep way we enter\'d, when from far\nAppear\'d a mountain dim, loftiest methought\nOf all I e\'er beheld.  Joy seiz\'d us straight,\nBut soon to mourning changed.  From the new land\nA whirlwind sprung, and at her foremost side\nDid strike the vessel.  Thrice it whirl\'d her round\nWith all the waves, the fourth time lifted up\nThe poop, and sank the prow: so fate decreed:\nAnd over us the booming billow clos\'d.\"\n\n\n\nCANTO XXVII\n\nNOW upward rose the flame, and still\'d its light\nTo speak no more, and now pass\'d on with leave\nFrom the mild poet gain\'d, when following came\nAnother, from whose top a sound confus\'d,\nForth issuing, drew our eyes that way to look.\n     As the Sicilian bull, that rightfully\nHis cries first echoed, who had shap\'d its mould,\nDid so rebellow, with the voice of him\nTormented, that the brazen monster seem\'d\nPierc\'d through with pain; thus while no way they found\nNor avenue immediate through the flame,\nInto its language turn\'d the dismal words:\nBut soon as they had won their passage forth,\nUp from the point, which vibrating obey\'d\nTheir motion at the tongue, these sounds we heard:\n\"O thou!  to whom I now direct my voice!\nThat lately didst exclaim in Lombard phrase,\n     Depart thou, I solicit thee no more,\'\nThough somewhat tardy I perchance arrive\nLet it not irk thee here to pause awhile,\nAnd with me parley:  lo! it irks not me\nAnd yet I burn.  If but e\'en now thou fall\ninto this blind world, from that pleasant land\nOf Latium, whence I draw my sum of guilt,\nTell me if those, who in Romagna dwell,\nHave peace or war.  For of the mountains there\nWas I, betwixt Urbino and the height,\nWhence Tyber first unlocks his mighty flood.\"\n     Leaning I listen\'d yet with heedful ear,\nWhen, as he touch\'d my side, the leader thus:\n\"Speak thou: he is a Latian.\"  My reply\nWas ready, and I spake without delay:\n     \"O spirit!  who art hidden here below!\nNever was thy Romagna without war\nIn her proud tyrants\' bosoms, nor is now:\nBut open war there left I none.  The state,\nRavenna hath maintain\'d this many a year,\nIs steadfast.  There Polenta\'s eagle broods,\nAnd in his broad circumference of plume\nO\'ershadows Cervia. The green talons grasp\nThe land, that stood erewhile the proof so long,\nAnd pil\'d in bloody heap the host of France.\n     \"The\' old mastiff of Verruchio and the young,\nThat tore Montagna in their wrath, still make,\nWhere they are wont, an augre of their fangs.\n     \"Lamone\'s city and Santerno\'s range\nUnder the lion of the snowy lair.\nInconstant partisan! that changeth sides,\nOr ever summer yields to winter\'s frost.\nAnd she, whose flank is wash\'d of Savio\'s wave,\nAs \'twixt the level and the steep she lies,\nLives so \'twixt tyrant power and liberty.\n     \"Now tell us, I entreat thee, who art thou?\nBe not more hard than others.  In the world,\nSo may thy name still rear its forehead high.\"\n     Then roar\'d awhile the fire, its sharpen\'d point\nOn either side wav\'d, and thus breath\'d at last:\n\"If I did think, my answer were to one,\nWho ever could return unto the world,\nThis flame should rest unshaken.  But since ne\'er,\nIf true be told me, any from this depth\nHas found his upward way, I answer thee,\nNor fear lest infamy record the words.\n     \"A man of arms at first, I cloth\'d me then\nIn good Saint Francis\' girdle, hoping so\nT\' have made amends.  And certainly my hope\nHad fail\'d not, but that he, whom curses light on,\nThe\' high priest again seduc\'d me into sin.\nAnd how and wherefore listen while I tell.\nLong as this spirit mov\'d the bones and pulp\nMy mother gave me, less my deeds bespake\nThe nature of the lion than the fox.\nAll ways of winding subtlety I knew,\nAnd with such art conducted, that the sound\nReach\'d the world\'s limit.  Soon ");
    strcat(expected_filecontent2, "as to that part\nOf life I found me come, when each behoves\nTo lower sails and gather in the lines;\nThat which before had pleased me then I rued,\nAnd to repentance and confession turn\'d;\nWretch that I was! and well it had bested me!\nThe chief of the new Pharisees meantime,\nWaging his warfare near the Lateran,\nNot with the Saracens or Jews (his foes\nAll Christians were, nor against Acre one\nHad fought, nor traffic\'d in the Soldan\'s land),\nHe his great charge nor sacred ministry\nIn himself, rev\'renc\'d, nor in me that cord,\nWhich us\'d to mark with leanness whom it girded.\nAs in Socrate, Constantine besought\nTo cure his leprosy Sylvester\'s aid,\nSo me to cure the fever of his pride\nThis man besought: my counsel to that end\nHe ask\'d:  and I was silent:  for his words\nSeem\'d drunken:  but forthwith he thus resum\'d:\n\"From thy heart banish fear:  of all offence\nI hitherto absolve thee.  In return,\nTeach me my purpose so to execute,\nThat Penestrino cumber earth no more.\nHeav\'n, as thou knowest, I have power to shut\nAnd open:  and the keys are therefore twain,\nThe which my predecessor meanly priz\'d.\"\n     Then, yielding to the forceful arguments,\nOf silence as more perilous I deem\'d,\nAnd answer\'d:  \"Father! since thou washest me\nClear of that guilt wherein I now must fall,\nLarge promise with performance scant, be sure,\nShall make thee triumph in thy lofty seat.\"\n     \"When I was number\'d with the dead, then came\nSaint Francis for me; but a cherub dark\nHe met, who cried: \"\'Wrong me not; he is mine,\nAnd must below to join the wretched crew,\nFor the deceitful counsel which he gave.\nE\'er since I watch\'d him, hov\'ring at his hair,\nNo power can the impenitent absolve;\nNor to repent and will at once consist,\nBy contradiction absolute forbid.\"\nOh mis\'ry! how I shook myself, when he\nSeiz\'d me, and cried, \"Thou haply thought\'st me not\nA disputant in logic so exact.\"\nTo Minos down he bore me, and the judge\nTwin\'d eight times round his callous back the tail,\nWhich biting with excess of rage, he spake:\n\"This is a guilty soul, that in the fire\nMust vanish.\'  Hence perdition-doom\'d I rove\nA prey to rankling sorro");strcat(expected_filecontent3, "males to\ndeath.\n\nv. 120.  Alessio.]  Alessio, of an ancient and considerable\nfamily in Lucca, called the Interminei.\n\nv. 130.  Thais.]  He alludes to that passage in the Eunuchus of\nTerence where Thraso asks if Thais was obliged to him for the\npresent he had sent her, and Gnatho replies, that she had\nexpressed her obligation in the most forcible terms.\n        T.  Magnas vero agere gratias Thais mihi?\n        G.  Ingentes.\n               Eun. a. iii. s. i.\n\nCANTO XIX\n\nv. 18.  Saint John\'s fair dome.]  The apertures in the  rock were\nof the same dimensions as the fonts of St. John the Baptist at\nFlorence, one of which, Dante says he had broken, to rescue a\nchild  that was playing near and fell in. He intimates that the\nmotive of his  breaking the font had been maliciously represented\nby his enemies.\n\nv. 55.  O Boniface!]  The spirit mistakes Dante for  Boniface\nVIII. who was then alive, and who he did not expect would have\narrived so soon, in consequence, as it should seem, of a\nprophecy, which  predicted the death of that Pope at a later\nperiod. Boniface died in  1303.\n\nv. 58.  In guile.]  \"Thou didst presume to arrive by fraudulent\nmeans at the papal power, and afterwards to abuse it.\"\n\nv. 71.  In the mighty mantle I was rob\'d.]  Nicholas III, of the\nOrsini family, whom the poet therefore calls \"figliuol dell\'\norsa,\" \"son of the she-bear.\"  He died in 1281.\n\nv. 86.  From forth the west, a shepherd without law.]   Bertrand\nde Got Archbishop of Bordeaux, who succeeded to the pontificate\nin 1305, and assumed the title of");strcat(expected_filecontent4, "h, conjur\'d by fell\nErictho, sorceress, who compell\'d the shades\nBack to their bodies.  No long space my flesh\nWas naked of me, when within these walls\nShe made me enter, to draw forth a spirit\nFrom out of Judas\' circle.  Lowest place\nIs that of all, obscurest, and remov\'d\nFarthest from heav\'n\'s all-circling orb.  The road\nFull well I know:  thou therefore rest secure.\nThat lake, the noisome stench exhaling, round\nThe city\' of grief encompasses, which now\nWe may not enter without rage.\"  Yet more\nHe added:  but I hold it not in mind,\nFor that mine eye toward the lofty tower\nHad drawn me wholly, to its burning top.\nWhere in an instant I beheld uprisen\nAt once three hellish furies stain\'d with blood:\nIn limb and motion feminine they seem\'d;\nAround them greenest hydras twisting roll\'d\nTheir volumes; adders and cerastes crept\nInstead of hair, and their fierce temples bound.\n     He knowing well the miserable hags\nWho tend the queen of endless woe, thus spake:\n\"Mark thou each dire Erinnys. To the left\nThis is Megaera; on the right hand she,\nWho wails, Alecto; and Tisiphone\nI\' th\' midst.\"  This said, in silence he remain\'d\nTheir breast they each one clawing tore; themselves\nSmote with their palms, and such shrill clamour rais\'d,\nThat to the bard I clung, suspicion-bound.\n\"Hasten Medusa: so to adamant\nHim shall we change;\" all looking down exclaim\'d.\n\"E\'en when by Theseus\' might assail\'d, we took\nNo ill revenge.\"  \"Turn thyself round, and keep\nThy count\'nance hid; for if the Gorgon dire\nBe shown, and thou shouldst view it, thy return\nUpwards would be for ever lost.\"  This said,\nHimself my gentle master turn\'d me round,\nNor trusted he my hands, but with his own\nHe also hid me.  Ye of intellect\nSound and entire, mark well the lore conceal\'d\nUnder close texture of the mystic strain!\n     And now there came o\'er the perturbed waves\nLoud-crashing, terrible, a sound that made\nEither shore tremble, as if of a wind\nImpetuous, from conflicting vapours sprung,\nThat \'gainst some forest driving all its might,\nPlucks off the branches, beats them down and hurls\nAfar; then onward passing proudly sweeps\nIts whirlwind rage, while beasts and shepherds fly.\n     Mine eyes he loos\'d, and spake: \"And now direct\nThy visual nerve along that ancient foam,\nThere, thickest where the smoke ascends.\" As frogs\nBefore their foe the serpent, through the wave\nPly swiftly all, till at the ground each one\nLies on a heap; more than a thousand spirits\nDestroy\'d, so saw I fleeing before one\nWho pass\'d with unwet feet the Stygian sound.\nHe, from his face removing the gross air,\nOft his left hand forth stretch\'d, and seem\'d alone\nBy that annoyance wearied.  I perceiv\'d\nThat he was sent from heav\'n, and to my guide\nTurn\'d me, who signal made that I should stand\nQuiet, and bend to him. Ah me!  how full\nOf noble anger seem\'d he!  To the gate\nHe came, and with his wand touch\'d it, whereat\nOpen without impediment it flew.\n     \"Outcasts of heav\'n!  O abject race and scorn\'d!\"\nBegan he on the horrid grunsel standing,\n\"Whence doth this wild excess of insolence\nLodge in you? wherefore kick you \'gainst that will\nNe\'er frustrate of its end, and which so oft\nHath laid on you enforcement of your pangs?\nWhat profits at the fays to but the horn?\nYour Cerberus, if ye remember, hence\nBears still, peel\'d of their hair, his throat and maw.\"\n     This said, he turn\'d back o\'er the filthy way,\nAnd syllable to us spake none, but wore\nThe semblance of a man by other care\nBeset, and keenly press\'d, than thought of him\nWho in his presence stands.  Then we our steps\nToward that territory mov\'d, secure\nAfter the hallow\'d words.  We unoppos\'d\nThere enter\'d; and my mind eager to learn\nWhat state a fortress like to that might hold,\nI soon as enter\'d throw mine eye around,\nAnd see on every part wide-stretching space\nReplete with bitter pain and torment ill.\n     As where Rhone stagnates on the plains of Arles,\nOr as at Pola, near Quarnaro\'s gulf,\nThat closes Italy and laves her bounds,\nThe place is all thick spread with sepulchres;\nSo was it here, save what in horror here\nExcell\'d:  for \'midst ");
    strcat(expected_filecontent4, "the graves were scattered flames,\nWherewith intensely all throughout they burn\'d,\nThat iron for no craft there hotter needs.\n     Their lids all hung suspended, and beneath\nFrom them forth issu\'d lamentable moans,\nSuch as the sad and tortur\'d well might raise.\n     I thus:  \"Master! say who are these, interr\'d\nWithin these vaults, of whom distinct we hear\nThe dolorous sighs?\"  He answer thus return\'d:\n     \"The arch-heretics are here, accompanied\nBy every sect their followers; and much more,\nThan thou believest, tombs are freighted:  like\nWith like is buried; and the monuments\nAre different in degrees of heat. \"This said,\nHe to the right hand turning, on we pass\'d\nBetwixt the afflicted and the ramparts high.\n\n\n\nCANTO X\n\nNOW by a secret pathway we proceed,\nBetween the walls, that hem the region round,\nAnd the tormented souls:  my master first,\nI close behind his steps.  \"Virtue supreme!\"\nI thus began; \"who through these ample orbs\nIn circuit lead\'st me, even as thou will\'st,\nSpeak thou, and satisfy my wish.  May those,\nWho lie within these sepulchres, be seen?\nAlready all the lids are rais\'d, and none\nO\'er them keeps watch.\"  He thus in answer spake\n\"They shall be closed all, what-time they here\nFrom Josaphat return\'d shall come, and bring\nTheir bodies, which above they now have left.\nThe cemetery on this part obtain\nWith Epicurus all his followers,\nWho with the body make the spirit die.\nHere therefore satisfaction shall be soon\nBoth to the question ask\'d, and to the wish,\nWhich thou conceal\'st in silence.\"  I replied:\n\"I keep not, guide belov\'d! from thee my heart\nSecreted, but to shun vain length of words,\nA lesson erewhile taught me by thyself.\"\n     \"O Tuscan! thou who through the city of fire\nAlive art passing, so discreet of speech!\nHere please thee stay awhile. Thy utterance\nDeclares the place of thy nativity\nTo be that noble land, with which perchance\nI too severely dealt.\"  Sudden that sound\nForth issu\'d from a vault, whereat in fear\nI somewhat closer to my leader\'s side\nApproaching, he thus spake:  \"What dost thou?  Turn.\nLo, Farinata, there! who hath himself\nUplifted:  from his girdle upwards all\nExpos\'d behold him.\"  On his face was mine\nAlready fix\'d; his breast and forehead there\nErecting, seem\'d as in high scorn he held\nE\'en hell.  Between the sepulchres to him\nMy guide thrust me with fearless hands and prompt,\nThis warning added:  \"See thy words be clear!\"\n     He, soon as there I stood at the tomb\'s foot,\nEy\'d me a space, then in disdainful mood\nAddress\'d me:  \"Say, what ancestors were thine?\"\n     I, willing to obey him, straight reveal\'d\nThe whole, nor kept back aught: whence he, his brow\nSomewhat uplifting, cried:  \"Fiercely were they\nAdverse to me, my party, and the blood\nFrom whence I sprang:  twice therefore I abroad\nScatter\'d them.\"  \"Though driv\'n out, yet they each time\nFrom all parts,\" answer\'d I, \"return\'d; an art\nWhich yours have shown, they are not skill\'d to learn.\"\n     Then, peering forth from the unclosed jaw,\nRose from his side a shade, high as the chin,\nLeaning, methought, upon its knees uprais\'d.\nIt look\'d around, as eager to explore\nIf there were other with me; but perceiving\nThat fond imagination quench\'d, with tears\nThus spake:  \"If thou through this blind prison go\'st.\nLed by thy lofty genius and profound,\nWhere is my son? and wherefore not with thee?\"\n     I straight replied:  \"Not of myself I come,\nBy him, who there expects me, through this clime\nConducted, whom perchance Guido thy son\nHad in contempt.\"  Already had his words\nAnd mode of punishment read me his name,\nWhence I so fully answer\'d.  He at once\nExclaim\'d, up starting, \"How! said\'st thou he HAD?\nNo longer lives he?  Strikes not on his eye\nThe blessed daylight?\"  Then of some delay\nI made ere my reply aware, down fell\nSupine, not after forth appear\'d he more.\n     Meanwhile the other, great of soul, near whom\nI yet was station\'d, chang\'d not count\'nance stern,\nNor mov\'d the neck, nor bent his ribbed side.\n\"And if,\" continuing the first discourse,\n\"They in this art,\" he cried, \"small skill have shown,\nThat doth torment m");
    strcat(expected_filecontent4, "e more e\'en than this bed.\nBut not yet fifty times shall be relum\'d\nHer aspect, who reigns here Queen of this realm,\nEre thou shalt know the full weight of that art.\nSo to the pleasant world mayst thou return,\nAs thou shalt tell me, why in all their laws,\nAgainst my kin this people is so fell?\"\n     \"The slaughter and great havoc,\" I replied,\n\"That colour\'d Arbia\'s flood with crimson stain--\nTo these impute, that in our hallow\'d dome\nSuch orisons ascend.\"  Sighing he shook\nThe head, then thus resum\'d:  \"In that affray\nI stood not singly, nor without just cause\nAssuredly should with the rest have stirr\'d;\nBut singly there I stood, when by consent\nOf all, Florence had to the ground been raz\'d,\nThe one who openly forbad the deed.\"\n     \"So may thy lineage find at last repose,\"\nI thus adjur\'d him, \"as thou solve this knot,\nWhich now involves my mind.  If right I hear,\nYe seem to view beforehand, that which time\nLeads with him, of the present uninform\'d.\"\n     \"We view, as one who hath an evil sight,\"\nHe answer\'d, \"plainly, objects far remote:\nSo much of his large spendour yet imparts\nThe\' Almighty Ruler; but when they approach\nOr actually exist, our intellect\nThen wholly fails, nor of your human state\nExcept what others bring us know we aught.\nHence therefore mayst thou understand, that all\nOur knowledge in that instant shall expire,\nWhen on futurity the portals close.\"\n     Then conscious of my fault, and by remorse\nSmitten, I added thus:  \"Now shalt thou say\nTo him there fallen, that his offspring still\nIs to the living join\'d; and bid him know,\nThat if from answer silent I abstain\'d,\n\'Twas that my thought was occupied intent\nUpon that error, which thy help hath solv\'d.\"\n     But now my master summoning me back\nI heard, and with more eager haste besought\nThe spirit to inform me, who with him\nPartook his lot.  He answer thus return\'d:\n     \"More than a thousand with me here are laid\nWithin is Frederick, second of that name,\nAnd the Lord Cardinal, and of the rest\nI speak not.\"  He, this said, from sight withdrew.\nBut I my steps towards the ancient bard\nReverting, ruminated on the words\nBetokening me such ill.  Onward he mov\'d,\nAnd thus in going question\'d:  \"Whence the\' amaze\nThat holds thy senses wrapt?\"  I satisfied\nThe\' inquiry, and the sage enjoin\'d me straight:\n\"Let thy safe memory store what thou hast heard\nTo thee importing harm; and note thou this,\"\nWith his rais\'d finger bidding me take heed,\n     \"When thou shalt stand before her gracious beam,\nWhose bright eye all surveys, she of thy life\nThe future tenour will to thee unfold.\"\n     Forthwith he to the left hand turn\'d his feet:\nWe left the wall, and tow\'rds the middle space\nWent by a path, that to a valley strikes;\nWhich e\'en thus high exhal\'d its noisome steam.\n\n\n\nCANTO XI\n\nUPON the utmost verge of a high bank,\nBy craggy rocks environ\'d round, we came,\nWhere woes beneath more cruel yet were stow\'d:\nAnd here to shun the horrible excess\nOf fetid exhalation, upward cast\nFrom the profound abyss, behind the lid\nOf a great monument we stood retir\'d,\nWhereon this scroll I mark\'d:  \"I have in charge\nPope Anastasius, whom Photinus drew\nFrom the right path.--Ere our descent behooves\nWe make delay, that somewhat first the sense,\nTo the dire breath accustom\'d, afterward\nRegard it not.\"  My master thus; to whom\nAnswering I spake:  \"Some compensation find\nThat the time past not wholly lost.\"  He then:\n\"Lo! how my thoughts e\'en to thy wishes tend!\nMy son! within these rocks,\" he thus began,\n\"Are three close circles in gradation plac\'d,\nAs these which now thou leav\'st. Each one is full\nOf spirits accurs\'d; but that the sight alone\nHereafter may suffice thee, listen how\nAnd for what cause in durance they abide.\n     \"Of all malicious act abhorr\'d in heaven,\nThe end is injury; and all such end\nEither by force or fraud works other\'s woe\nBut fraud, because of man peculiar evil,\nTo God is more displeasing; and beneath\nThe fraudulent are therefore doom\'d to\' endure\nSeverer pang.  The violent occupy\nAll the first circle; and because to force\nThree persons are obnoxious, in three roun");
    strcat(expected_filecontent4, "ds\nHach within other sep\'rate is it fram\'d.\nTo God, his neighbour, and himself, by man\nForce may be offer\'d; to himself I say\nAnd his possessions, as thou soon shalt hear\nAt full.  Death, violent death, and painful wounds\nUpon his neigh");strcat(expected_filecontent5, "t it out of the\nkingdom, because it was the land of the church, and that it was\nburied by the river Verde, on the borders of the kingdom and of\nCarapagna. this, however, we do not affirm.\"  G. Villani, Hist.\nl. vii.  c. 9.\n\nv. 111.  Costanza.]  See Paradise Canto III.  v. 121.\n\nv. 112.  My fair daughter.]  Costanza, the daughter of Manfredi,\nand wife of Peter III.  King of Arragon, by whom she was mother\nto  Frederick, King of Sicily and James, King of Arragon With the\nlatter of these she was at Rome 1296. See G. Villani, 1. viii. c.\n18. and notes to Canto VII.\n\nv. 122.  Clement.]  Pope Clement IV.\n\nv. 127.  The stream of Verde.]  A river near Ascoli, that falls\ninto he Toronto. The \"xtinguished lights \" formed part of the\nceremony t the interment of one excommunicated.\n\nv. 130.  Hope.]\nMentre che la speranza ha fior del verde.\nTasso, G. L. c. xix. st. 53.\n--infin che verde e fior di speme.\n\nCANTO IV\n\nv. 1.  When.] It must be owned the beginning of this Canto is\nsomewhat obscure. Bellutello refers, for an elucidation of it, to\nthe reasoning of Statius in the twenty-fifth canto. Perhaps some\nillustration may be derived from the following, passage in\nSouth\'s Sermons, in which I have ventured to supply the words\nbetween crotchets that seemed to be wanting to complete\nthe sense. Now whether these three, judgement memory, and\ninvention, are three distinct things, both in being distinguished\nfrom one another, and likewise from the substance of the soul\nitself, considered without any such faculties, (or whether the\nsoul be one individual substance) but only receiving these\nseveral denominations rom the several respects arising from the\nseveral actions exerted immediately by itself upon several\nobjects, or several qualities of the same object, I say whether\nof these it is, is not easy to decide, and it is well that it is\nnot necessary Aquinas, and most with him, affirm the former, and\nScotus with his followers the latter.\" Vol. iv. Serm. 1.\n\nv. 23.  Sanleo.]  A fortress on the summit of Montefeltro.\n\nv. 24.  Noli.]  In the Genoese territory, between Finale and\nSavona.\n\nv. 25.  Bismantua.]  A steep mountain in the territory of Reggio.\n\nv. 55.  From the left.]  Vellutello observes an imitation of\nLucan in this passage:\n\nIgnotum vobis, Arabes, venistis in orbem,\nUmbras mirati nemornm non ire sinistras.\nPhars.  s. 1.  iii. 248\n\nv. 69 Thou wilt see.]  \"If you consider that this mountain of\nPurgatory and that of Sion are antipodal to each other, you will\nperceive that the sun must rise on opposite sides of the\nrespective eminences.\"\n\nv. 119.  Belacqua.]  Concerning this man, the commentators afford\nno information.\n\nCANTO V\n\nv. 14.  Be as a tower.]  Sta  ome torre ferma\n\nBerni, Orl.  Inn. 1. 1. c. xvi. st. 48:\nIn quei due piedi sta fermo il gigante\nCom\' una torre in mezzo d\'un castello.\n\nAnd Milton, P. L. b. i.  591.\nStood like a tower.\n\nv. 36.  Ne\'er saw I fiery vapours.]  Imitated by Tasso, G. L, c.\nxix t. 62:\nTal suol fendendo liquido sereno\nStella cader della gran madre in seno.\n\nAnd by Milton, P. L. b. iv. 558:\nSwift as a shooting star\nIn autumn thwarts the night, when vapours fir\'d\nImpress the air.\n\nv. 67.  That land.]  The Marca d\'Ancona, between Romagna and\nApulia, the kingdom of Charles of Anjou.\n\nv. 76.  From thence I came.]  Giacopo del Cassero, a citizen of\nFano who having spoken ill of Azzo da Este, Marquis of Ferrara,\nwas by his orders put to death.  Giacopo, was overtaken by the\nassassins at Oriaco a place near the Brenta, from whence, if he\nhad fled towards Mira, higher up on that river, instead of making\nfor the marsh on the sea shore, he might have escaped.\n\nv. 75.  Antenor\'s land.]  The city of Padua, said to be founded\nby Antenor.\n\nv. 87.  Of Montefeltro I.]  Buonconte (son of Guido da\nMontefeltro, whom we have had in the twenty-seventh Canto of\nHell) fell in the battle of Campaldino (1289), fighting on the\nside of the Aretini.\n\nv. 88.  Giovanna.]  Either the wife, or kinswoman, of Buonconte.\n\nv. 91.  The hermit\'s seat.]  The hermitage of Camaldoli.\n\nv. 95.  Where its name is cancel\'d.]  That is, between Bibbiena\na");
    strcat(expected_filecontent5, "nd Poppi, where the Archiano falls into the Arno.\n\nv. 115.  From Pratomagno to the mountain range.]  From Pratomagno\nnow called Prato Vecchio (which divides the Valdarno from\nCasentino) as far as to the Apennine.\n\nv. 131.  Pia.] She is said to have been a Siennese lady, of the\nfamily of Tolommei, secretly made away with by her husband, Nello\ndella Pietra, of the same city, in Maremma, where he had some\npossessions.\n\nCANTO VI\n\nv. 14.  Of Arezzo him.]  Benincasa of Arezzo, eminent for his\nskill in jurisprudence, who, having condemned to death Turrino da\nTurrita brother of Ghino di Tacco, for his robberies in Maremma,\nwas murdered by Ghino, in an apartment of his own house, in the\npresence of many witnesses. Ghino was not only suffered to escape\nin safety, but (as the commentators inform us) obtained so high a\nreputation by the liberality with which he was accustomed to\ndispense the fruits of his plunder, and treated those who fell\ninto his hands with so much courtesy, that he was afterwards\ninvited to Rome, and knighted by Boniface VIII. A story is told\nof him by Boccaccio, G. x. N. 2.\n\nv. 15.  Him beside.]  Ciacco de\' Tariatti of Arezzo.  He is said\nto have been carried by his horse into the Arno, and there\ndrowned, while he was in pursuit of certain of his enemies.\n\nv. 17.  Frederic Novello.]  Son of the Conte Guido da Battifolle,\nand slain by one of the family of Bostoli.\n\nv. 18.  Of Pisa he.]  Farinata de\' Scornigiani of Pisa.  His\nfather Marzuco, who had entered the order of the Frati Minori, so\nentirely overcame the feelings of resentment, that he even kissed\nthe hands of the slayer of his son, and, as he was following the\nfuneral, exhorted his kinsmen to reconciliation.\n\nv. 20.  Count 0rso.]  Son of Napoleone da Cerbaia, slain by\nAlberto da Mangona, his uncle.\n\nv. 23.  Peter de la Brosse.]  Secretary of Philip III  of France.\nThe courtiers, envying the high place which he held in the king\'s\nfavour, prevailed on Mary of Brabant to charge him falsely with\nan attempt upon her person for which supposed crime he suffered\ndeath. So say the Italian commentators.  Henault represents the\nmatter very differently: \"Pierre de la Brosse, formerly barber to\nSt. Louis, afterwards the favorite of Philip, fearing the too\ngreat attachment of the king for his wife Mary, accuses this\nprincess of having poisoned Louis, eldest son of Philip, by his\nfirst marriage. This calumny is discovered by a nun of Nivelle in\nFlanders.  La Brosse is hung.\" Abrege Chron. t. 275, &c.\n\nv. 30.  In thy text.]  He refers to Virgil, Aen. 1, vi.  376.\nDesine fata deum flecti sperare precando, 37. The sacred height\nOf judgment. Shakespeare, Measure for Measure, a. ii. s. 2.\nIf he, which is the top of judgment\n\nv. 66.  Eyeing us as a lion on his watch.]\nA guisa di Leon quando si posa.\nA line taken by Tasso, G.  L. c. x. st. 56.\n\nv. 76.  Sordello.]  The history of Sordello\'s life is wrapt in\nthe obscurity of romance.  That he distinguished himself by his\nskill in Provencal poetry is certain. It is probable that he was\nborn towards the end of the twelfth, and died about the middle of\nthe succeeding century.  Tiraboschi has taken much pains to sift\nall the notices he could collect relating to him.  Honourable\nmention of his name is made by our Poet in the Treatise de Vulg.\nEloq.  1. i. c. 15.\n\nv. 76.  Thou inn of grief.]\nThou most beauteous inn\nWhy should h");strcat(expected_filecontent6, "ucca: and that face beyond him, pierc\'d\nUnto a leaner fineness than the rest,\nHad keeping of the church: he was of Tours,\nAnd purges by wan abstinence away\nBolsena\'s eels and cups of muscadel.\"\n     He show\'d me many others, one by one,\nAnd all, as they were nam\'d, seem\'d well content;\nFor no dark gesture I discern\'d in any.\nI saw through hunger Ubaldino grind\nHis teeth on emptiness; and Boniface,\nThat wav\'d the crozier o\'er a num\'rous flock.\nI saw the Marquis, who tad time erewhile\nTo swill at Forli with less drought, yet so\nWas one ne\'er sated.  I howe\'er, like him,\nThat gazing \'midst a crowd, singles out one,\nSo singled him of Lucca; for methought\nWas none amongst them took such note of me.\nSomewhat I heard him whisper of Gentucca:\nThe sound was indistinct, and murmur\'d there,\nWhere justice, that so strips them, fix\'d her sting.\n     \"Spirit!\" said I, \"it seems as thou wouldst fain\nSpeak with me.  Let me hear thee.  Mutual wish\nTo converse prompts, which let us both indulge.\"\n     He, answ\'ring, straight began: \"Woman is born,\nWhose brow no wimple shades yet, that shall make\nMy city please thee, blame it as they may.\nGo then with this forewarning.  If aught false\nMy whisper too implied, th\' event shall tell\nBut say, if of a  truth I see the man\nOf that new lay th\' inventor, which begins\nWith \'Ladies, ye that con the lore of love\'.\"\n     To whom I thus:  \"Count of me but as one\nWho am the scribe of love; that, when he breathes,\nTake up my pen, and, as he dictates, write.\"\n     \"Brother!\" said he, \"the hind\'rance which once held\nThe notary with Guittone and myself,\nShort of that new and sweeter style I hear,\nIs now disclos\'d.  I see how ye your plumes\nStretch, as th\' inditer guides them; which, no question,\nOurs did not.  He that seeks a grace beyond,\nSees not the distance parts one style from other.\"\nAnd, as contented, here he held his peace.\n     Like as the bird, that winter near the Nile,\nIn squared regiment direct their course,\nThen stretch themselves in file for speedier flight;\nThus all the tribe of spirits, as they turn\'d\nTheir visage, faster deaf, nimble alike\nThrough leanness and desire.  And as a man,\nTir\'d With the motion of a trotting steed,\nSlacks pace, and stays behind his company,\nTill his o\'erbreathed lungs keep temperate time;\nE\'en so Forese let that holy crew\nProceed, behind them lingering at my side,\nAnd saying: \"When shall I again behold thee?\"\n     \"How long my life may last,\" said I, \"I know not;\nThis know, how soon soever I return,\nMy wishes will before me have arriv\'d.\nSithence the place, where I am set to live,\nIs, day by day, more scoop\'d of all its good,\nAnd dismal ruin seems to threaten it.\"\n     \"Go now,\" he cried:  \"lo!  he, whose guilt is most,\nPasses before my vision, dragg\'d at heels\nOf an infuriate beast.  Toward the vale,\nWhere guilt hath no redemption, on it speeds,\nEach step increasing swiftness on the last;\nUntil a blow it strikes, that leaveth him\nA corse most vilely shatter\'d.  No long space\nThose wheels have yet to roll\"  (therewith his eyes\nLook\'d up to heav\'n) \"ere thou shalt plainly see\nThat which my words may not more plainly tell.\nI quit thee: time is precious here: I lose\nToo much, thus measuring my pace with shine.\"\n     As from a troop of well-rank\'d chivalry\nOne knight, more enterprising than the rest,\nPricks forth at gallop, eager to display\nHis prowess in the first encounter prov\'d\nSo parted he from us with lengthen\'d strides,\nAnd left me on the way with those twain spirits,\nWho were such mighty marshals of the world.\n     When he beyond us had so fled mine eyes\nNo nearer reach\'d him, than my thought his words,\nThe branches of another fruit, thick hung,\nAnd blooming fresh, appear\'d.  E\'en as our steps\nTurn\'d thither, not far off it rose to view.\nBeneath it were a multitude, that rais\'d\nTheir hands, and shouted forth I know not What\nUnto the boughs; like greedy and fond brats,\nThat beg, and answer none obtain from him,\nOf whom they beg; but more to draw them on,\nHe at arm\'s length the object of their wish\nAbove them holds aloft, and hides it not.\n     At length, as un");
    strcat(expected_filecontent6, "deceiv\'d they went their way:\nAnd we approach the tree, who vows and tears\nSue to in vain, the mighty tree.  \"Pass on,\nAnd come not near.  Stands higher up the wood,\nWhereof Eve tasted, and from it was ta\'en\n\'this plant.\" Such sounds from midst the thickets came.\nWhence I, with either bard, close to the side\nThat rose, pass\'d forth beyond.  \"Remember,\" next\nWe heard, \"those noblest creatures of the clouds,\nHow they their twofold bosoms overgorg\'d\nOppos\'d in fight to Theseus:  call to mind\nThe Hebrews, how effeminate they stoop\'d\nTo ease their thirst; whence Gideon\'s ranks were thinn\'d,\nAs he to Midian march\'d adown the hills.\"\n     Thus near one border coasting, still we heard\nThe sins of gluttony, with woe erewhile\nReguerdon\'d.  Then along the lonely path,\nOnce more at large, full thousand paces on\nWe travel\'d, each contemplative and mute.\n     \"Why pensive journey thus ye three alone?\"\nThus suddenly a voice exclaim\'d: whereat\nI shook, as doth a scar\'d and paltry beast;\nThen rais\'d my head to look from whence it came.\n     Was ne\'er, in furnace, glass, or metal seen\nSo bright and glowing red, as was the shape\nI now beheld.  \"If ye desire to mount,\"\nHe cried, \"here must ye turn.  This way he goes,\nWho goes in quest of peace.\"  His countenance\nHad dazzled me; and to my guides I fac\'d\nBackward, like one who walks, as sound directs.\n     As when, to harbinger the dawn, springs up\nOn freshen\'d wing the air of May, and breathes\nOf fragrance, all impregn\'d with herb and flowers,\nE\'en such a wind I felt upon my front\nBlow gently, and the moving of a wing\nPerceiv\'d, that moving shed ambrosial smell;\nAnd then a voice:  \"Blessed are they, whom grace\nDoth so illume, that appetite in them\nExhaleth no inordinate desire,\nStill hung\'ring as the rule of temperance wills.\"\n\n\n\nCANTO XXV\n\nIt was an hour, when he who climbs, had need\nTo walk uncrippled: for the sun had now\nTo Taurus the meridian circle left,\nAnd to the Scorpion left the night.  As one\nThat makes no pause, but presses on his road,\nWhate\'er betide him, if some urgent need\nImpel: so enter\'d we upon our way,\nOne before other; for, but singly, none\nThat steep and narrow scale admits to climb.\n     E\'en as the young stork lifteth up his wing\nThrough wish to fly, yet ventures not to quit\nThe nest, and drops it; so in me desire\nOf questioning my guide arose, and fell,\nArriving even to the act, that marks\nA man prepar\'d for speech.  Him all our haste\nRestrain\'d not, but thus spake the sire belov\'d:\nFear not to speed the shaft, that on thy lip\nStands trembling for its flight.\"  Encourag\'d thus\nI straight began:  \"How there can leanness come,\nWhere is no want of nourishment to feed?\"\n     \"If thou,\" he answer\'d, \"hadst remember\'d thee,\nHow Meleager with the wasting brand\nWasted alike, by equal fires consm\'d,\nThis would not trouble thee: and hadst thou thought,\nHow in the mirror your reflected form\nWith mimic motion vibrates, what now seems\nHard, had appear\'d no harder than the pulp\nOf summer fruit mature.  But that thy will\nIn certainty may find its full repose,\nLo Statius here!  on him I call, and pray\nThat he would now be healer of thy wound.\"\n     \"If in thy presence I unfold to him\nThe secrets of heaven\'s vengeance, let me plead\nThine own injunction, to exculpate me.\"\nSo Statius answer\'d, and forthwith began:\n\"Attend my words, O son, and in thy mind\nReceive them: so shall they be light to clear\nThe doubt thou offer\'st. Blood, concocted well,\nWhich by the thirsty veins is ne\'er imbib\'d,\nAnd rests as food superfluous, to be ta\'en\nFrom the replenish\'d table, in the heart\nDerives effectual virtue, that informs\nThe several human limbs, as being that,\nWhich passes through the veins itself to make them.\nYet more concocted it descends, where shame\nForbids to mention: and from thence distils\nIn natural vessel on another\'s blood.\nThen each unite together, one dispos\'d\nT\' endure, to act the other, through meet frame\nOf its recipient mould: that being reach\'d,\nIt \'gins to work, coagulating first;\nThen vivifies what its own substance caus\'d\nTo bear.  With animation now indued,\nThe active virt");
    strcat(expected_filecontent6, "ue (differing from a plant\nNo further, than that this is on the way\nAnd at its limit that) continues yet\nTo operate, that now it moves, and feels,\nAs sea sponge clinging to the rock: and there\nAssumes th\' organic powers its seed convey\'d.\n\'This is the period, son!  at which the virtue,\nThat from the generating heart proceeds,\nIs pliant and expansive; for each limb\nIs in the heart by forgeful nature plann\'d.\nHow babe of animal becomes, remains\nFor thy consid\'ring.  At this point, more wise,\nThan thou hast err\'d, making the soul disjoin\'d\nFrom passive intellect, because he saw\nNo organ for the latter\'s use assign\'d.\n     \"Open thy bosom to the truth that comes.\nKnow soon as in the embryo, to the brain,\nArticulation is complete, then turns\nThe primal Mover with a smile of joy\nOn such great work of nature, and imbreathes\nNew spirit replete with virtue, that what here\nActive it finds, to its own substance draws,\nAnd forms an individual soul, that lives,\nAnd feels, and bends reflective on itself.\nAnd that thou less mayst marvel at the word,\nMark the sun\'s heat, how that to wine doth change,\nMix\'d with the moisture filter\'d through the vine.\n     \"When Lachesis hath spun the thread, the soul\nTakes with her both the human and divine,\nMemory, intelligence, and will, in act\nFar keener than before, the other powers\nInactive all and mute.  No pause allow\'d,\nIn wond\'rous sort self-moving, to one strand\nOf those, where the departed roam, she falls,\nHere learns her destin\'d path.  Soon as the place\nReceives her, round the plastic virtue beams,\nDistinct as in the living limbs before:\nAnd as the air, when saturate with showers,\nThe casual beam refracting, decks itself\nWith many a hue; so here the ambient air\nWeareth that form, which influence of the soul\nImprints on it; and like the flame, that where\nThe fire moves, thither follows, so henceforth\nThe new form on the spirit follows still:\nHence hath it semblance, and is shadow call\'d,\nWith each sense even to the sight endued:\nHence speech is ours, hence laughter, tears, and sighs\nWhich thou mayst oft have witness\'d on the mount\nTh\' obedient shadow fails not to present\nWhatever varying passion moves within us.\nAnd this the cause of what thou marvel\'st at.\"\n     Now the last flexure of our way we reach\'d,\nAnd to the right hand turning, other care\nAwaits us.  Here the rocky precipice\nHurls forth redundant flames, and from the rim\nA blast upblown, with forcible rebuff\nDriveth them back, sequester\'d from its bound.\n     Behoov\'d us, one by one, along the side,\nThat border\'d on the void, to pass; and I\nFear\'d on one hand the fire, on th\' other fear\'d\nHeadlong to fall: when thus th\' instructor warn\'d:\n\"Strict rein must in this place direct the eyes.\nA little swerving and the way is lost.\"\n     Then from the bosom of the burning mass,\n\"O God of mercy!\" heard I sung; and felt\nNo less desire to turn.  And when I saw\nSpirits along the flame proceeding, I\nBetween their footsteps and mine own was fain\nTo share by turns my view.  At the hymn\'s close\nThey shouted loud, \"I do not know a man;\"\nThen in low voice again took up the strain,\nWhich once more ended, \"To the wood,\" they cried,\n\"Ran Dian, and drave forth Callisto, stung\nWith Cytherea\'s poison:\" then return\'d\nUnto their song; then marry a pair extoll\'d,\nWho liv\'d in virtue chastely, and the bands\nOf wedded love.  Nor from that task, I ween,\nSurcease they; whilesoe\'er the scorching fire\nEnclasps them.  Of such skill appliance needs\nTo medicine the wound, that healeth last.\n\n\n\nCANTO XXVI\n\nWhile singly thus along the rim we walk\'d,\nOft the good master warn\'d me:  \"Look thou well.\nA");


            struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            
                    struct file_t* file0 = file_open(volume, "WISH.TXT");
                    test_error(file0 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file1 = file_open(volume, "LEARN.TX");
                    test_error(file1 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file2 = file_open(volume, "DRINK.BIN");
                    test_error(file2 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file3 = file_open(volume, "COME");
                    test_error(file3 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file4 = file_open(volume, "SEVEN.TX");
                    test_error(file4 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file5 = file_open(volume, "QUESTION.TX");
                    test_error(file5 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
                    struct file_t* file6 = file_open(volume, "TOUCH.BIN");
                    test_error(file6 != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
                    onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)"

            
            
                size_t size0 = file_read(filecontent0, 1, 10240, file0);
                test_error(size0 == 10240, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 10240 bajtów, a wczytała %lu", size0);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos0 = mem_find_first_difference(filecontent0, expected_filecontent0, 10240);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos0 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos0, mem_get_byte(filecontent0, diff_pos0), mem_get_byte(expected_filecontent0, diff_pos0));
        
                onerror_compare_memory(expected_filecontent0, filecontent0, 10240);
            
                size_t size1 = file_read(filecontent1, 1, 9688, file1);
                test_error(size1 == 9688, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 9688 bajtów, a wczytała %lu", size1);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos1 = mem_find_first_difference(filecontent1, expected_filecontent1, 9688);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos1 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos1, mem_get_byte(filecontent1, diff_pos1), mem_get_byte(expected_filecontent1, diff_pos1));
        
                onerror_compare_memory(expected_filecontent1, filecontent1, 9688);
            
                size_t size2 = file_read(filecontent2, 1, 10313, file2);
                test_error(size2 == 10313, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 10313 bajtów, a wczytała %lu", size2);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos2 = mem_find_first_difference(filecontent2, expected_filecontent2, 10313);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos2 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos2, mem_get_byte(filecontent2, diff_pos2), mem_get_byte(expected_filecontent2, diff_pos2));
        
                onerror_compare_memory(expected_filecontent2, filecontent2, 10313);
            
                size_t size3 = file_read(filecontent3, 1, 1544, file3);
                test_error(size3 == 1544, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 1544 bajtów, a wczytała %lu", size3);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos3 = mem_find_first_difference(filecontent3, expected_filecontent3, 1544);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos3 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos3, mem_get_byte(filecontent3, diff_pos3), mem_get_byte(expected_filecontent3, diff_pos3));
        
                onerror_compare_memory(expected_filecontent3, filecontent3, 1544);
            
                size_t size4 = file_read(filecontent4, 1, 12521, file4);
                test_error(size4 == 12521, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 12521 bajtów, a wczytała %lu", size4);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos4 = mem_find_first_difference(filecontent4, expected_filecontent4, 12521);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos4 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos4, mem_get_byte(filecontent4, diff_pos4), mem_get_byte(expected_filecontent4, diff_pos4));
        
                onerror_compare_memory(expected_filecontent4, filecontent4, 12521);
            
                size_t size5 = file_read(filecontent5, 1, 7471, file5);
                test_error(size5 == 7471, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 7471 bajtów, a wczytała %lu", size5);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos5 = mem_find_first_difference(filecontent5, expected_filecontent5, 7471);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos5 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos5, mem_get_byte(filecontent5, diff_pos5), mem_get_byte(expected_filecontent5, diff_pos5));
        
                onerror_compare_memory(expected_filecontent5, filecontent5, 7471);
            
                size_t size6 = file_read(filecontent6, 1, 11807, file6);
                test_error(size6 == 11807, "Funkcja file_read() niepoprawnie wczytała dane z pliku, powinna wczytać 11807 bajtów, a wczytała %lu", size6);
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
                int diff_pos6 = mem_find_first_difference(filecontent6, expected_filecontent6, 11807);
        
                // jeśli jest, to raportuj błąd
                test_error(diff_pos6 == -1, "Dane wczytane z pliku nie są poprawne; różnica w bajcie %d; jest 0x%02x a powinno być 0x%02x",
                    diff_pos6, mem_get_byte(filecontent6, diff_pos6), mem_get_byte(expected_filecontent6, diff_pos6));
        
                onerror_compare_memory(expected_filecontent6, filecontent6, 11807);
            

            free(filecontent0);
    free(filecontent1);
    free(filecontent2);
    free(filecontent3);
    free(filecontent4);
    free(filecontent5);
    free(filecontent6);

            file_close(file0);
    file_close(file1);
    file_close(file2);
    file_close(file3);
    file_close(file4);
    file_close(file5);
    file_close(file6);


            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 29: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST29(void)
{
    // informacje o teście
    test_start(29, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(9688, 1);
            char expected_filecontent[9689] = "";

            strcat(expected_filecontent, "e?\nHe hath in sooth good cause for endless grief,\nWho, for the love of thing that lasteth not,\nDespoils himself forever of that love.\n     As oft along the still and pure serene,\nAt nightfall, glides a sudden trail of fire,\nAttracting with involuntary heed\nThe eye to follow it, erewhile at rest,\nAnd seems some star that shifted place in heav\'n,\nOnly that, whence it kindles, none is lost,\nAnd it is soon extinct; thus from the horn,\nThat on the dexter of the cross extends,\nDown to its foot, one luminary ran\nFrom mid the cluster shone there; yet no gem\nDropp\'d from its foil; and through the beamy list\nLike flame in alabaster, glow\'d its course.\n     So forward stretch\'d him (if of credence aught\nOur greater muse may claim) the pious ghost\nOf old Anchises, in the\' Elysian bower,\nWhen he perceiv\'d his son.  \"O thou, my blood!\nO most exceeding grace divine!  to whom,\nAs now to thee, hath twice the heav\'nly gate\nBeen e\'er unclos\'d?\" so spake the light; whence I\nTurn\'d me toward him; then unto my dame\nMy sight directed, and on either side\nAmazement waited me; for in her eyes\nWas lighted such a smile, I thought that mine\nHad div\'d unto the bottom of my grace\nAnd of my bliss in Paradise.  Forthwith\nTo hearing and to sight grateful alike,\nThe spirit to his proem added things\nI understood not, so profound he spake;\nYet not of choice but through necessity\nMysterious; for his high conception scar\'d\nBeyond the mark of mortals.  When the flight\nOf holy transport had so spent its rage,\nThat nearer to the level of our thought\nThe speech descended, the first sounds I heard\nWere, \"Best he thou, Triunal Deity!\nThat hast such favour in my seed vouchsaf\'d!\"\nThen follow\'d:  \"No unpleasant thirst, tho\' long,\nWhich took me reading in the sacred book,\nWhose leaves or white or dusky never change,\nThou hast allay\'d, my son, within this light,\nFrom whence my voice thou hear\'st; more thanks to her.\nWho for such lofty mounting has with plumes\nBegirt thee.  Thou dost deem thy thoughts to me\nFrom him transmitted, who is first of all,\nE\'en as all numbers ray from unity;\nAnd therefore dost not ask me who I am,\nOr why to thee more joyous I appear,\nThan any other in this gladsome throng.\nThe truth is as thou deem\'st; for in this hue\nBoth less and greater in that mirror look,\nIn which thy thoughts, or ere thou think\'st, are shown.\nBut, that the love, which keeps me wakeful ever,\nUrging with sacred thirst of sweet desire,\nMay be contended fully, let thy voice,\nFearless, and frank and jocund, utter forth\nThy will distinctly, utter forth the wish,\nWhereto my ready answer stands decreed.\"\n     I turn\'d me to Beatrice; and she heard\nEre I had spoken, smiling, an assent,\nThat to my will gave wings; and I began\n\"To each among your tribe, what time ye kenn\'d\nThe nature, in whom naught unequal dwells,\nWisdom and love were in one measure dealt;\nFor that they are so equal in the sun,\nFrom whence ye drew your radiance and your heat,\nAs makes all likeness scant.  But will and means,\nIn mortals, for the cause ye well discern,\nWith unlike wings are fledge.  A mortal I\nExperience inequality like this,\nAnd therefore give no thanks, but in the heart,\nFor thy paternal greeting.  This howe\'er\nI pray thee, living topaz!  that ingemm\'st\nThis precious jewel, let me hear thy name.\"\n     \"I am thy root, O leaf!  whom to expect\nEven, hath pleas\'d me:  \"thus the prompt reply\nPrefacing, next it added;  \"he, of whom\nThy kindred appellation comes, and who,\nThese hundred years and more, on its first ledge\nHath circuited the mountain, was my son\nAnd thy great grandsire.  Well befits, his long\nEndurance should he shorten\'d by thy deeds.\n     \"Florence, within her ancient limit-mark,\nWhich calls her still to matin prayers and noon,\nWas chaste and sober, and abode in peace.\nShe had no armlets and no head-tires then,\nNo purfled dames, no zone, that caught the eye\nMore than the person did.  Time was not yet,\nWhen at his daughter\'s birth the sire grew pale.\nFor fear the age and dowry should exceed\nOn each side just proportion.  House was none\nVoid of its family; nor yet had come\nHardanapalus, to");
    strcat(expected_filecontent, " exhibit feats\nOf chamber prowess.  Montemalo yet\nO\'er our suburban turret rose; as much\nTo be surpass in fall, as in its rising.\nI saw Bellincione Berti walk abroad\nIn leathern girdle and a clasp of bone;\nAnd, with no artful colouring on her cheeks,\nHis lady leave the glass.  The sons I saw\nOf Nerli and of Vecchio well content\nWith unrob\'d jerkin; and their good dames handling\nThe spindle and the flax; O happy they!\nEach sure of burial in her native land,\nAnd none left desolate a-bed for France!\nOne wak\'d to tend the cradle, hushing it\nWith sounds that lull\'d the parent\'s infancy:\nAnother, with her maidens, drawing off\nThe tresses from the distaff, lectur\'d them\nOld tales of Troy and Fesole and Rome.\nA Salterello and Cianghella we\nHad held as strange a marvel, as ye would\nA Cincinnatus or Cornelia now.\n     \"In such compos\'d and seemly fellowship,\nSuch faithful and such fair equality,\nIn so sweet household, Mary at my birth\nBestow\'d me, call\'d on with loud cries; and there\nIn your old baptistery, I was made\nChristian at once and Cacciaguida; as were\nMy brethren, Eliseo and Moronto.\n     \"From Valdipado came to me my spouse,\nAnd hence thy surname grew.  I follow\'d then\nThe Emperor Conrad; and his knighthood he\nDid gird on me; in such good part he took\nMy valiant service.  After him I went\nTo testify against that evil law,\nWhose people, by the shepherd\'s fault, possess\nYour right, usurping.  There, by that foul crew\nWas I releas\'d from the deceitful world,\nWhose base affection many a spirit soils,\nAnd from the martyrdom came to this peace.\"\n\n\n\nCANTO XVI\n\nO slight respect of man\'s nobility!\nI never shall account it marvelous,\nThat our infirm affection here below\nThou mov\'st to boasting, when I could not choose,\nE\'en in that region of unwarp\'d desire,\nIn heav\'n itself, but make my vaunt in thee!\nYet cloak thou art soon shorten\'d, for that time,\nUnless thou be eked out from day to day,\nGoes round thee with his shears.  Resuming then\nWith greeting such, as Rome, was first to bear,\nBut since hath disaccustom\'d I began;\nAnd Beatrice, that a little space\nWas sever\'d, smil\'d reminding me of her,\nWhose cough embolden\'d (as the story holds)\nTo first offence the doubting Guenever.\n     \"You are my sire,\" said I, \"you give me heart\nFreely to speak my thought: above myself\nYou raise me.  Through so many streams with joy\nMy soul is fill\'d, that gladness wells from it;\nSo that it bears the mighty tide, and bursts not\nSay then, my honour\'d stem!  what ancestors\nWhere those you sprang from, and what years were mark\'d\nIn your first childhood?  Tell me of the fold,\nThat hath Saint John for guardian, what was then\nIts state, and who in it were highest seated?\"\n     As embers, at the breathing of the wind,\nTheir flame enliven, so that light I saw\nShine at my blandishments; and, as it grew\nMore fair to look on, so with voice more sweet,\nYet not in this our modern phrase, forthwith\nIt answer\'d:  \"From the day, when it was said\n\' Hail Virgin!\' to the throes, by which my mother,\nWho now is sainted, lighten\'d her of me\nWhom she was heavy with, this fire had come,\nFive hundred fifty times and thrice, its beams\nTo reilumine underneath the foot\nOf its own lion.  They, of whom I sprang,\nAnd I, had there our birth-place, where the last\nPartition of our city first is reach\'d\nBy him, that runs her annual game.  Thus much\nSuffice of my forefathers: who they were,\nAnd whence they hither came, more honourable\nIt is to pass in silence than to tell.\nAll those, who in that time were there from Mars\nUntil the Baptist, fit to carry arms,\nWere but the fifth of them this day alive.\nBut then the citizen\'s blood, that now is mix\'d\nFrom Campi and Certaldo and Fighine,\nRan purely through the last mechanic\'s veins.\nO how much better were it, that these people\nWere neighbours to you, and that at Galluzzo\nAnd at Trespiano, ye should have your bound\'ry,\nThan to have them within, and bear the stench\nOf Aguglione\'s hind, and Signa\'s, him,\nThat hath his eye already keen for bart\'ring!\nHad not the people, which of all the world\nDegenerates most, been stepdame unto Caesar,\nBu");
    strcat(expected_filecontent, "t, as a mother, gracious to her son;\nSuch one, as hath become a Florentine,\nAnd trades and traffics, had been turn\'d adrift\nTo Simifonte, where his grandsire ply\'d\nThe beggar\'s craft.  The Conti were possess\'d\nOf Montemurlo still: the Cerchi still\nWere in Acone\'s parish; nor had haply\nFrom Valdigrieve past the Buondelmonte.\nThe city\'s malady hath ever source\nIn the confusion of its persons, as\nThe body\'s, in variety of food:\nAnd the blind bull falls with a steeper plunge,\nThan the blind lamb; and oftentimes one sword\nDoth more and better execution,\nThan five.  Mark Luni, Urbisaglia mark,\nHow they are gone, and after them how go\nChiusi and Sinigaglia; and \'t will seem\nNo longer new or strange to thee to hear,\nThat families fail, when cities have their end.\nAll things, that appertain t\' ye, like yourselves,\nAre mortal: but mortality in some\nYe mark not, they endure so long, and you\nPass by so suddenly.  And as the moon\nDoth, by the rolling of her heav\'nly sphere,\nHide and reveal the strand unceasingly;\nSo fortune deals with Florence.  Hence admire not\nAt what of them I tell thee, whose renown\nTime covers, the first Florentines.  I saw\nThe Ughi, Catilini and Filippi,\nThe Alberichi, Greci and Ormanni,\nNow in their wane, illustrious citizens:\nAnd great as ancient, of Sannella him,\nWith him of Arca saw, and Soldanieri\nAnd Ardinghi, and Bostichi.  At the poop,\nThat now is laden with new felony,\nSo cumb\'rous it may speedily sink the bark,\nThe Ravignani sat, of whom is sprung\nThe Co");

            struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "LEARN.TX");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, 5139, SEEK_SET);
        
            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[5139] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[5139], c);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 30: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST30(void)
{
    // informacje o teście
    test_start(30, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(10240, 1);
            char expected_filecontent[10241] = "";

            strcat(expected_filecontent, "ator, and remains\nEver between the sun and winter) for the cause\nThou hast assign\'d, from hence toward the north\nDeparts, when those who in the Hebrew land\nInhabit, see it tow\'rds the warmer part.\nBut if it please thee, I would gladly know,\nHow far we have to journey: for the hill\nMounts higher, than this sight of mine can mount.\"\n     He thus to me:  \"Such is this steep ascent,\nThat it is ever difficult at first,\nBut, more a man proceeds, less evil grows.\nWhen pleasant it shall seem to thee, so much\nThat upward going shall be easy to thee.\nAs in a vessel to go down the tide,\nThen of this path thou wilt have reach\'d the end.\nThere hope to rest thee from thy toil.  No more\nI answer, and thus far for certain know.\"\nAs he his words had spoken, near to us\nA voice there sounded:  \"Yet ye first perchance\nMay to repose you by constraint be led.\"\nAt sound thereof each turn\'d, and on the left\nA huge stone we beheld, of which nor I\nNor he before was ware.  Thither we drew,\nfind there were some, who in the shady place\nBehind the rock were standing, as a man\nThru\' idleness might stand.  Among them one,\nWho seem\'d to me much wearied, sat him down,\nAnd with his arms did fold his knees about,\nHolding his face between them downward bent.\n     \"Sweet Sir!\"  I cry\'d, \"behold that man, who shows\nHimself more idle, than if laziness\nWere sister to him.\"  Straight he turn\'d to us,\nAnd, o\'er the thigh lifting his face, observ\'d,\nThen in these accents spake:  \"Up then, proceed\nThou valiant one.\"  Straight who it was I knew;\nNor could the pain I felt (for want of breath\nStill somewhat urg\'d me) hinder my approach.\nAnd when I came to him, he scarce his head\nUplifted, saying \"Well hast thou discern\'d,\nHow from the left the sun his chariot leads.\"\n     His lazy acts and broken words my lips\nTo laughter somewhat mov\'d; when I began:\n\"Belacqua, now for thee I grieve no more.\nBut tell, why thou art seated upright there?\nWaitest thou escort to conduct thee hence?\nOr blame I only shine accustom\'d ways?\"\nThen he:  \"My brother, of what use to mount,\nWhen to my suffering would not let me pass\nThe bird of God, who at the portal sits?\nBehooves so long that heav\'n first bear me round\nWithout its limits, as in life it bore,\nBecause I to the end repentant Sighs\nDelay\'d, if prayer do not aid me first,\nThat riseth up from heart which lives in grace.\nWhat other kind avails, not heard in heaven?\"\'\n     Before me now the Poet up the mount\nAscending, cried:  \"Haste thee, for see the sun\nHas touch\'d the point meridian, and the night\nNow covers with her foot Marocco\'s shore.\"\n\n\n\nCANTO V\n\nNow had I left those spirits, and pursued\nThe steps of my Conductor, when beheld\nPointing the finger at me one exclaim\'d:\n\"See how it seems as if the light not shone\nFrom the left hand of him beneath, and he,\nAs living, seems to be led on.\"  Mine eyes\nI at that sound reverting, saw them gaze\nThrough wonder first at me, and then at me\nAnd the light broken underneath, by turns.\n\"Why are thy thoughts thus riveted?\"  my guide\nExclaim\'d, \"that thou hast slack\'d thy pace?  or how\nImports it thee, what thing is whisper\'d here?\nCome after me, and to their babblings leave\nThe crowd. Be as a tower, that, firmly set,\nShakes not its top for any blast that blows!\nHe, in whose bosom thought on thought shoots out,\nStill of his aim is wide, in that the one\nSicklies and wastes to nought the other\'s strength.\"\n     What other could I answer save \"I come?\"\nI said it, somewhat with that colour ting\'d\nWhich ofttimes pardon meriteth for man.\n     Meanwhile traverse along the hill there came,\nA little way before us, some who sang\nThe \"Miserere\" in responsive Strains.\nWhen they perceiv\'d that through my body I\nGave way not for the rays to pass, their song\nStraight to a long and hoarse exclaim they chang\'d;\nAnd two of them, in guise of messengers,\nRan on to meet us, and inquiring ask\'d:\nOf your condition we would gladly learn.\"\n     To them my guide.  \"Ye may return, and bear\nTidings to them who sent you, that his frame\nIs real flesh.  If, as I deem, to view\nHis shade they paus\'d, enough is answer\'d them.\nHim");
    strcat(expected_filecontent, " let them honour, they may prize him well.\"\n     Ne\'er saw I fiery vapours with such speed\nCut through the serene air at fall of night,\nNor August\'s clouds athwart the setting sun,\nThat upward these did not in shorter space\nReturn; and, there arriving, with the rest\nWheel back on us, as with loose rein a troop.\n     \"Many,\" exclaim\'d the bard, \"are these, who throng\nAround us: to petition thee they come.\nGo therefore on, and listen as thou go\'st.\"\n     \"O spirit!  who go\'st on to blessedness\nWith the same limbs, that clad thee at thy birth.\"\nShouting they came, \"a little rest thy step.\nLook if thou any one amongst our tribe\nHast e\'er beheld, that tidings of him there\nThou mayst report.  Ah, wherefore go\'st thou on?\nAh wherefore tarriest thou not?  We all\nBy violence died, and to our latest hour\nWere sinners, but then warn\'d by light from heav\'n,\nSo that, repenting and forgiving, we\nDid issue out of life at peace with God,\nWho with desire to see him fills our heart.\"\n     Then I:  \"The visages of all I scan\nYet none of ye remember.  But if aught,\nThat I can do, may please you, gentle spirits!\nSpeak; and I will perform it, by that peace,\nWhich on the steps of guide so excellent\nFollowing from world to world intent I seek.\"\n     In answer he began:  \"None here distrusts\nThy kindness, though not promis\'d with an oath;\nSo as the will fail not for want of power.\nWhence I, who sole before the others speak,\nEntreat thee, if thou ever see that land,\nWhich lies between Romagna and the realm\nOf Charles, that of thy courtesy thou pray\nThose who inhabit Fano, that for me\nTheir adorations duly be put up,\nBy which I may purge off my grievous sins.\nFrom thence I came.  But the deep passages,\nWhence issued out the blood wherein I dwelt,\nUpon my bosom in Antenor\'s land\nWere made, where to be more secure I thought.\nThe author of the deed was Este\'s prince,\nWho, more than right could warrant, with his wrath\nPursued me.  Had I towards Mira fled,\nWhen overta\'en at Oriaco, still\nMight I have breath\'d. But to the marsh I sped,\nAnd in the mire and rushes tangled there\nFell, and beheld my life-blood float the plain.\"\n     Then said another:  \"Ah! so may the wish,\nThat takes thee o\'er the mountain, be fulfill\'d,\nAs thou shalt graciously give aid to mine.\nOf Montefeltro I; Buonconte I:\nGiovanna nor none else have care for me,\nSorrowing with these I therefore go.\"  I thus:\n\"From Campaldino\'s field what force or chance\nDrew thee, that ne\'er thy sepulture was known?\"\n     \"Oh!\"  answer\'d he, \"at Casentino\'s foot\nA stream there courseth, nam\'d Archiano, sprung\nIn Apennine above the Hermit\'s seat.\nE\'en where its name is cancel\'d, there came I,\nPierc\'d in the heart, fleeing away on foot,\nAnd bloodying the plain.  Here sight and speech\nFail\'d me, and finishing with Mary\'s name\nI fell, and tenantless my flesh remain\'d.\nI will report the truth; which thou again0\nTell to the living.  Me God\'s angel took,\nWhilst he of hell exclaim\'d:  \"O thou from heav\'n!\nSay wherefore hast thou robb\'d me?  Thou of him\nTh\' eternal portion bear\'st with thee away\nFor one poor tear that he deprives me of.\nBut of the other, other rule I make.\"\n     \"Thou knowest how in the atmosphere collects\nThat vapour dank, returning into water,\nSoon as it mounts where cold condenses it.\nThat evil will, which in his intellect\nStill follows evil, came, and rais\'d the wind\nAnd smoky mist, by virtue of the power\nGiven by his nature.  Thence the valley, soon\nAs day was spent, he cover\'d o\'er with cloud\nFrom Pratomagno to the mountain range,\nAnd stretch\'d the sky above, so that the air\nImpregnate chang\'d to water.  Fell the rain,\nAnd to the fosses came all that the land\nContain\'d not; and, as mightiest streams are wont,\nTo the great river with such headlong sweep\nRush\'d, that nought stay\'d its course.  My stiffen\'d frame\nLaid at his mouth the fell Archiano found,\nAnd dash\'d it into Arno, from my breast\nLoos\'ning the cross, that of myself I made\nWhen overcome with pain.  He hurl\'d me on,\nAlong the banks and bottom of his course;\nThen in his muddy spoils encircling wrapt.\"\n     \"Ah!  when thou to th");
    strcat(expected_filecontent, "e world shalt be return\'d,\nAnd rested after thy long road,\" so spake\nNext the third spirit; \"then remember me.\nI once was Pia.  Sienna gave me life,\nMaremma took it from me.  That he knows,\nWho me with jewell\'d ring had first espous\'d.\"\n\n\n\nCANTO VI\n\nWhen from their game of dice men separate,\nHe, who hath lost, remains in sadness fix\'d,\nRevolving in his mind, what luckless throws\nHe cast: but meanwhile all the company\nGo with the other; one before him runs,\nAnd one behind his mantle twitches, one\nFast by his side bids him remember him.\nHe stops not; and each one, to whom his hand\nIs stretch\'d, well knows he bids him stand aside;\nAnd thus he from the press defends himself.\nE\'en such was I in that close-crowding throng;\nAnd turning so my face around to all,\nAnd promising, I \'scap\'d from it with pains.\n     Here of Arezzo him I saw, who fell\nBy Ghino\'s cruel arm; and him beside,\nWho in his chase was swallow\'d by the stream.\nHere Frederic Novello, with his hand\nStretch\'d forth, entreated; and of Pisa he,\nWho put the good Marzuco to such proof\nOf constancy.  Count Orso I beheld;\nAnd from its frame a soul dismiss\'d for spite\nAnd envy, as it said, but for no crime:\nI speak of Peter de la Brosse; and here,\nWhile she yet lives, that Lady of Brabant\nLet her beware; lest for so false a deed\nShe herd with worse than these. When I was freed\nFrom all those spirits, who pray\'d for others\' prayers\nTo hasten on their state of blessedness;\nStraight I began:  \"O thou, my luminary!\nIt seems expressly in thy text denied,\nThat heaven\'s supreme decree can never bend\nTo supplication; yet with this design\nDo these entreat.  Can then their hope be vain,\nOr is thy saying not to me reveal\'d?\"\n     He thus to me:  \"Both what I write is plain,\nAnd these deceiv\'d not in their hope, if well\nThy mind consider, that the sacred height\nOf judgment doth not stoop, because love\'s flame\nIn a short moment all fulfils, which he\nWho sojourns here, in right should satisfy.\nBesides, when I this point concluded thus,\nBy praying no defect could be supplied;\nBec");

            struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "WISH.TXT");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, -3180, SEEK_END);

            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[7060] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[7060], c);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 31: Sprawdzanie poprawności działania funkcji file_seek
//
void UTEST31(void)
{
    // informacje o teście
    test_start(31, "Sprawdzanie poprawności działania funkcji file_seek", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    
            char *filecontent = (char *)calloc(1544, 1);
            char expected_filecontent[1545] = "";

            strcat(expected_filecontent, "males to\ndeath.\n\nv. 120.  Alessio.]  Alessio, of an ancient and considerable\nfamily in Lucca, called the Interminei.\n\nv. 130.  Thais.]  He alludes to that passage in the Eunuchus of\nTerence where Thraso asks if Thais was obliged to him for the\npresent he had sent her, and Gnatho replies, that she had\nexpressed her obligation in the most forcible terms.\n        T.  Magnas vero agere gratias Thais mihi?\n        G.  Ingentes.\n               Eun. a. iii. s. i.\n\nCANTO XIX\n\nv. 18.  Saint John\'s fair dome.]  The apertures in the  rock were\nof the same dimensions as the fonts of St. John the Baptist at\nFlorence, one of which, Dante says he had broken, to rescue a\nchild  that was playing near and fell in. He intimates that the\nmotive of his  breaking the font had been maliciously represented\nby his enemies.\n\nv. 55.  O Boniface!]  The spirit mistakes Dante for  Boniface\nVIII. who was then alive, and who he did not expect would have\narrived so soon, in consequence, as it should seem, of a\nprophecy, which  predicted the death of that Pope at a later\nperiod. Boniface died in  1303.\n\nv. 58.  In guile.]  \"Thou didst presume to arrive by fraudulent\nmeans at the papal power, and afterwards to abuse it.\"\n\nv. 71.  In the mighty mantle I was rob\'d.]  Nicholas III, of the\nOrsini family, whom the poet therefore calls \"figliuol dell\'\norsa,\" \"son of the she-bear.\"  He died in 1281.\n\nv. 86.  From forth the west, a shepherd without law.]   Bertrand\nde Got Archbishop of Bordeaux, who succeeded to the pontificate\nin 1305, and assumed the title of");

            struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "COME");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_seek(file, 733, SEEK_SET);
            file_seek(file, 378, SEEK_CUR);

            char c;
            int res = file_read(&c, 1, 1, file);
            test_error(res == 1, "Funkcja file_read() powinna zwrócić wartość 1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            test_error(expected_filecontent[1111] == c, "Funkcja file_read() powinna odczyatć z pliku wartość |%c|, a odczytała |%c|", expected_filecontent[1111], c);

            free(filecontent);
            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 32: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST32(void)
{
    // informacje o teście
    test_start(32, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "COTTON");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (COTTON) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 33: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST33(void)
{
    // informacje o teście
    test_start(33, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "LAND");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (LAND) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 34: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST34(void)
{
    // informacje o teście
    test_start(34, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "PUSH");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (PUSH) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 35: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST35(void)
{
    // informacje o teście
    test_start(35, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "JUMP");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (JUMP) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 36: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST36(void)
{
    // informacje o teście
    test_start(36, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "NOISE");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (NOISE) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 37: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST37(void)
{
    // informacje o teście
    test_start(37, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "GOLD");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (GOLD) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 38: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST38(void)
{
    // informacje o teście
    test_start(38, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "EQUAL");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (EQUAL) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 39: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST39(void)
{
    // informacje o teście
    test_start(39, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                 struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                 test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct volume_t* volume = fat_open(disk, 0);
                 test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 struct file_t* file = file_open(volume, "ABOUTSTO");
                 test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL - nazwa podana w parametrze (ABOUTSTO) jest nazwą katalogu, a nie pliku");
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                 fat_close(volume);
                 disk_close(disk);

                 test_no_heap_leakage();
                 onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
             
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 40: Sprawdzanie poprawności działania funkcji file_open
//
void UTEST40(void)
{
    // informacje o teście
    test_start(40, "Sprawdzanie poprawności działania funkcji file_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "BOTTOM");
            test_error(file == NULL, "Funkcja file_open() nie powinna otworzyć pliku o nazwie BOTTOM, ponieważ nie istnieje on w katalogu głównym");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 41: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST41(void)
{
    // informacje o teście
    test_start(41, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(NULL, "BOTTOM");
            test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL w przypadku podania błędnych danych");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 42: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST42(void)
{
    // informacje o teście
    test_start(42, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, NULL);
            test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL w przypadku podania błędnych danych");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 43: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST43(void)
{
    // informacje o teście
    test_start(43, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(NULL, NULL);
            test_error(file == NULL, "Funkcja file_open() powinna zwrócić NULL w przypadku podania błędnych danych");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 44: Sprawdzanie poprawności działania funkcji file_close
//
void UTEST44(void)
{
    // informacje o teście
    test_start(44, "Sprawdzanie poprawności działania funkcji file_close", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            file_close(NULL);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 45: Sprawdzanie poprawności działania funkcji file_read
//
void UTEST45(void)
{
    // informacje o teście
    test_start(45, "Sprawdzanie poprawności działania funkcji file_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct file_t* file = file_open(volume, "WISH.TXT");
            test_error(file != NULL, "Funkcja file_open() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            int res = file_read(NULL, 1, 1, file);
            test_error(res == -1, "Funkcja file_read() powinna zwrócić wartość -1, a zwróciła %d", res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            file_close(file);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 46: Sprawdzanie poprawności działania funkcji dir_read
//
void UTEST46(void)
{
    // informacje o teście
    test_start(46, "Sprawdzanie poprawności działania funkcji dir_read", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            char* expected_names[15] = { "WISH.TXT", "LEARN.TX", "DRINK.BIN", "COME", "SEVEN.TX", "QUESTION.TX", "TOUCH.BIN", "COTTON", "LAND", "PUSH", "JUMP", "NOISE", "GOLD", "EQUAL", "ABOUTSTO" };
            int found_names[15] = { 0 };

            struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t* pdir = dir_open(volume, "\\");
            test_error(pdir != NULL, "Funkcja dir_open() niepoprawnie otworzyła katalog");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            for (int i = 0; i < 15; ++i)
            {
                struct dir_entry_t entry;
                int res = dir_read(pdir, &entry);
                test_error(res == 0, "Funkcja dir_read() niepoprawnie odczytała wpis z katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                int name_found = 0;

                for (int j = 0; j < 15; ++j)
                {
                    if (strcmp(entry.name, expected_names[j]) == 0)
                    {
                        test_error(found_names[j] == 0, "Funkcja dir_read() ponownie zwróciła informację o wpisie %s", expected_names[j]);
                        found_names[j] = 1;
                        name_found = 1;
                        break;
                    }
                }

                test_error(name_found == 1, "Funkcja dir_read() zwróciła informację o wpisie %s, który nie znajduje się w katalogu", entry.name);
            }

            struct dir_entry_t entry;
            int res = dir_read(pdir, &entry);
            test_error(res == 1, "Funkcja dir_read() zwróciła niepoprawną wartość, po odczytaniu wszystkich wpisów z katalogu powinna zwrócić %d, a zwróciła %d", 1, res);
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            dir_close(pdir);
            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 47: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST47(void)
{
    // informacje o teście
    test_start(47, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "WISH.TXT");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 48: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST48(void)
{
    // informacje o teście
    test_start(48, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "LEARN.TX");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 49: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST49(void)
{
    // informacje o teście
    test_start(49, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "DRINK.BIN");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 50: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST50(void)
{
    // informacje o teście
    test_start(50, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "COME");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 51: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST51(void)
{
    // informacje o teście
    test_start(51, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "SEVEN.TX");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 52: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST52(void)
{
    // informacje o teście
    test_start(52, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "QUESTION.TX");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 53: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST53(void)
{
    // informacje o teście
    test_start(53, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

                struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
                test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct volume_t* volume = fat_open(disk, 0);
                test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                struct dir_t*  dir = dir_open(volume, "TOUCH.BIN");
                test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

                fat_close(volume);
                disk_close(disk);

                test_no_heap_leakage();
                onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
            
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}

//
//  Test 54: Sprawdzanie poprawności działania funkcji dir_open
//
void UTEST54(void)
{
    // informacje o teście
    test_start(54, "Sprawdzanie poprawności działania funkcji dir_open", __LINE__);

    // uwarunkowanie zasobów - pamięci, itd...
    test_file_write_limit_setup(33554432);
    rldebug_reset_limits();
    
    //
    // -----------
    //
    

            struct disk_t* disk = disk_open_from_file("home_fat16_volume.img");
            test_error(disk != NULL, "Funkcja disk_open_from_file() niepoprawnie otworzyła plik");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct volume_t* volume = fat_open(disk, 0);
            test_error(volume != NULL, "Funkcja fat_open() niepoprawnie otworzyła wolumin");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            struct dir_t*  dir = dir_open(volume, "fly");
            test_error(dir == NULL, "Funkcja dir_open() powinna zwrócić NULL w przypadku podania niepoprawnej nazwy katalogu");
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)

            fat_close(volume);
            disk_close(disk);

            test_no_heap_leakage();
            onerror_terminate(); // przerwanie wszystkich testów jednostkowych (np. coś jest mocno nie tak z kodem)
        
    //
    // -----------
    //

    // przywrócenie podstawowych parametów przydzielania zasobów (jeśli to tylko możliwe)
    rldebug_reset_limits();
    test_file_write_limit_restore();
    
    test_ok();
}




enum run_mode_t { rm_normal_with_rld = 0, rm_unit_test = 1, rm_main_test = 2 };

int __wrap_main(volatile int _argc, char** _argv, char** _envp)
{
    int volatile vargc = _argc;
    char ** volatile vargv = _argv, ** volatile venvp = _envp;
	volatile enum run_mode_t run_mode = rm_unit_test; // -1
	volatile int selected_test = -1;

    if (vargc > 1)
	{
	    char* smode = strtok(vargv[1], ",");
	    char* stest = strtok(NULL, "");
		char *errptr = NULL;
		run_mode = (enum run_mode_t)strtol(smode, &errptr, 10);
		if (*errptr == '\x0')
		{
			memmove(vargv + 1, vargv + 2, sizeof(char*) * (vargc - 1));
			vargc--;

			if (stest != NULL)
			{
			    int val = (int)strtol(stest, &errptr, 10);
			    if (*errptr == '\x0')
			        selected_test = val;
			}
		}
	}

    // printf("runmode=%d; selected_test=%d\n", run_mode, selected_test);

    // inicjuj testy jednostkowe
    unit_test_init(run_mode, "unit_test_v2.c");
    test_limit_init();
    rldebug_set_reported_severity_level(MSL_FAILURE);

    if (run_mode == rm_normal_with_rld)
    {
        // konfiguracja ograniczników
        rldebug_reset_limits();
        

        // uruchom funkcję main Studenta a potem wyświetl podsumowanie sterty i zasobów
        volatile int ret_code = rdebug_call_main(tested_main, vargc, vargv, venvp);

        rldebug_reset_limits();
        

        int leaks_detected = rldebug_show_leaked_resources(0);
        if (leaks_detected)
            raise(SIGHEAP);

        return ret_code;
    }

    
    if (run_mode == rm_unit_test)
    {
        test_title("Testy jednostkowe");

        void (*pfcn[])(void) =
        { 
            UTEST1, // Sprawdzanie poprawności działania funkcji disk_open_from_file
            UTEST2, // Sprawdzanie poprawności działania funkcji disk_open_from_file
            UTEST3, // Sprawdzanie poprawności działania funkcji disk_close
            UTEST4, // Sprawdzanie poprawności działania funkcji fat_open
            UTEST5, // Sprawdzanie poprawności działania funkcji disk_open_from_file
            UTEST6, // Sprawdzanie poprawności działania funkcji file_read
            UTEST7, // Sprawdzanie poprawności działania funkcji file_read
            UTEST8, // Sprawdzanie poprawności działania funkcji file_read
            UTEST9, // Sprawdzanie poprawności działania funkcji file_read
            UTEST10, // Sprawdzanie poprawności działania funkcji file_read
            UTEST11, // Sprawdzanie poprawności działania funkcji file_read
            UTEST12, // Sprawdzanie poprawności działania funkcji file_read
            UTEST13, // Sprawdzanie poprawności działania funkcji file_read
            UTEST14, // Sprawdzanie poprawności działania funkcji file_read
            UTEST15, // Sprawdzanie poprawności działania funkcji file_read
            UTEST16, // Sprawdzanie poprawności działania funkcji file_read
            UTEST17, // Sprawdzanie poprawności działania funkcji file_read
            UTEST18, // Sprawdzanie poprawności działania funkcji file_read
            UTEST19, // Sprawdzanie poprawności działania funkcji file_read
            UTEST20, // Sprawdzanie poprawności działania funkcji file_read
            UTEST21, // Sprawdzanie poprawności działania funkcji file_read
            UTEST22, // Sprawdzanie poprawności działania funkcji file_read
            UTEST23, // Sprawdzanie poprawności działania funkcji file_read
            UTEST24, // Sprawdzanie poprawności działania funkcji file_read
            UTEST25, // Sprawdzanie poprawności działania funkcji file_read
            UTEST26, // Sprawdzanie poprawności działania funkcji file_read
            UTEST27, // Sprawdzanie poprawności działania funkcji file_read
            UTEST28, // Sprawdzanie poprawności działania funkcji file_read
            UTEST29, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST30, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST31, // Sprawdzanie poprawności działania funkcji file_seek
            UTEST32, // Sprawdzanie poprawności działania funkcji file_open
            UTEST33, // Sprawdzanie poprawności działania funkcji file_open
            UTEST34, // Sprawdzanie poprawności działania funkcji file_open
            UTEST35, // Sprawdzanie poprawności działania funkcji file_open
            UTEST36, // Sprawdzanie poprawności działania funkcji file_open
            UTEST37, // Sprawdzanie poprawności działania funkcji file_open
            UTEST38, // Sprawdzanie poprawności działania funkcji file_open
            UTEST39, // Sprawdzanie poprawności działania funkcji file_open
            UTEST40, // Sprawdzanie poprawności działania funkcji file_open
            UTEST41, // Sprawdzanie poprawności działania funkcji file_read
            UTEST42, // Sprawdzanie poprawności działania funkcji file_read
            UTEST43, // Sprawdzanie poprawności działania funkcji file_read
            UTEST44, // Sprawdzanie poprawności działania funkcji file_close
            UTEST45, // Sprawdzanie poprawności działania funkcji file_read
            UTEST46, // Sprawdzanie poprawności działania funkcji dir_read
            UTEST47, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST48, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST49, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST50, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST51, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST52, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST53, // Sprawdzanie poprawności działania funkcji dir_open
            UTEST54, // Sprawdzanie poprawności działania funkcji dir_open
            NULL
        };

        for (int idx = 0; pfcn[idx] != NULL && !test_get_session_termination_flag(); idx++)
        {
            if (selected_test == -1 || selected_test == idx + 1)
                pfcn[idx]();

            // limit niezaliczonych testów, po jakim testy jednostkowe zostaną przerwane
            if (test_session_get_fail_count() >= 1000)
                test_terminate_session();
        }


        test_title("RLDebug :: Analiza wycieku zasobów");
        // sprawdź wycieki pamięci
        int leaks_detected = rldebug_show_leaked_resources(1);
        test_set_session_leaks(leaks_detected);

        // poinformuj serwer Mrówka o wyniku testu - podsumowanie
        test_title("Podsumowanie");
        if (selected_test == -1)
            test_summary(54); // wszystkie testy muszą zakończyć się sukcesem
        else
            test_summary(1); // tylko jeden (selected_test) test musi zakończyć się  sukcesem
        return EXIT_SUCCESS;
    }
    

    if (run_mode == rm_main_test)
    {
        test_title("Testy funkcji main()");

        void (*pfcn[])(int, char**, char**) =
        { 
            NULL
        };

        for (volatile int idx = 0; pfcn[idx] != NULL && !test_get_session_termination_flag(); idx++)
        {
            if (selected_test == -1 || selected_test == idx + 1)
                pfcn[idx](vargc, vargv, venvp);

            // limit niezaliczonych testów, po jakim testy jednostkowe zostaną przerwane
            if (test_session_get_fail_count() >= 1000)
                test_terminate_session();
        }


        test_title("RLDebug :: Analiza wycieku zasobów");
        // sprawdź wycieki pamięci
        int leaks_detected = rldebug_show_leaked_resources(1);
        test_set_session_leaks(leaks_detected);

        // poinformuj serwer Mrówka o wyniku testu - podsumowanie
        test_title("Podsumowanie");
        if (selected_test == -1)
            test_summary(0); // wszystkie testy muszą zakończyć się sukcesem
        else
            test_summary(1); // tylko jeden (selected_test) test musi zakończyć się  sukcesem

        return EXIT_SUCCESS;
    }

    printf("*** Nieznana wartość RunMode: %d", (int)run_mode);
    abort();
}