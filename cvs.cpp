void openCSVfile()
{
QFile csv(FILENAME);
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

            int id = rows[0].toInt();
            QString name = rows[1];
            int gender = rows[2].toInt();
            int yearborn = rows[3].toInt();
            int yeardead = rows[4].toInt();
            gogn.add_person(id, name, gender, yearborn, yeardead);

        }
    }

    csv.close();
}
}

void saveCSVfile()
{
    QVector<person> results =   gogn.query();
    QFile write(FILENAME);
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
