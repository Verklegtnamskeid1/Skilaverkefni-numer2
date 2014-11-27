Skilverefni1
============

Fyrsta skilaverkefnið

Hugmyndir: 

* Nota qstring (https://qt-project.org/doc/qt-4.7/qstring.html) en ekki string – qstring styður utf8 
* 

struct person {
  int id;
  QString name;
  int year_born;
  int year_death;
} ;

Það sem við þurfum er:

* Eitthvað sem birtir allar færslur (hægt að sortera eftir dánar- og fæðingarári, kyn og nafni. 
** Það veðrur líka að vera hægt að leita
* Eitthvað sem getur tekið við inputi og bætt við í einhverja C++ drullu
* Eitthvað sem opnar skjal (t.d. csv: http://en.wikipedia.org/wiki/Comma-separated_values skjal) og setur í C++ drulluna
* Eitthvað sem tekur C++ drulluna og vistar í skjalið

* Uhh, svo þarf auðvitað að passa að notendaviðmótið sé allt AÐGREINT frá virkni svo við getum auðveldlega portað þessu á Android og allt moðerfökkingdrasl

Verkefnalýsing
============

Í þessum hluta skal skrifa console forrit með eftirfarandi kröfur til virkni:

    Notandi skal geta skráð þekktar persónur úr sögu tölvunarfræðinnar. Að lágmarki skal vera hægt að skrá eftirfarandi gögn um sérhverja persónu: nafn, kyn, fæðingarár og dánarár.
    Forritið skal geta birt lista af þeim persónum sem skráðar hafa verið.
    Forritið skal geyma listann, þannig að hann týnist ekki þó forritinu sé lokað.
    Hægt skal vera að leita í listanum.
    Þegar listinn er birtur, skal bjóða notandanum að velja hvernig hann skuli raðaður.

Þá eru gerðar eftirfarandi kröfur að auki:

    Nota skal lagskipta högun við útfærslu kerfisins.
    Kóðinn skal hýstur með Git (GitHub, Bitbucket, etc.)
    Nota skal Qt Creator við útfærslu (sjá betur síðar í námskeiðinu).
    Kóðinn skal vera lesanlegur, vel formaður, vel skjalaður, og viðhaldanlegur.

Skila skal lokaútgáfu kóðans í einni .zip/.rar skrá, ásamt upplýsingum um það hvar kóðann er að finna, þ.e. á GitHub/BitBucket etc. Þá skal fylgja með keyranleg útgáfa kerfisins, ásamt gagnaskrá með a.m.k. 10 færslum.


Skilafrestur til miðvikudagsins 3 des kl 10:00
