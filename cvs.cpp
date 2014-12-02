QVector<QStringList> openCSVfile()
{
QFile csv(FILENAME); /* FILENAME er skilgreind í main.h */
QVector<QStringList> buffer;

if (csv.exists() && csv.open(QIODevice::ReadOnly | QIODevice::Text))
{
    QTextStream in(&csv);
    QString line = "";
    while (!line.isNull())
    {
        line = in.readLine();
        QStringList rows = line.split(",");
        if (rows.count() == 5)
        {
            /* file formattið er til dæmis svona:
             * 0,jon orn,0,1983,3000
             * */
            /* int id = rows[0].toInt();
            QString name = rows[1];
            int gender = rows[2].toInt();
            int yearborn = rows[3].toInt();
            int yeardead = rows[4].toInt(); */

            buffer.push_back(rows);
            // gogn.add_person(id, name, gender, yearborn, yeardead);

        }
    }

    csv.close();
    return buffer;
}
    return buffer;

}

void saveCSVfile(QVector<person> results)
{
    QFile write(FILENAME); /* FILENAME er skilgreint í main.h */
    write.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream wf(&write);
    foreach(person item,results )
    {
        wf << item.id <<","<<
              item.name<<","<<
              item.gender<<","<<
              item.year_born<<","<<
              item.year_death<<endl;
    }
    write.flush();
    write.close();

}
