using System;
using System.Threading;
namespace simga
{
public
    class Chromosome
    {
    public
        Chromosome()

        {
        }

    protected
        double cost;

        Random randObj = new Random();

    protected
        int[] cityList;
    protected
        double mutationPercent;
    protected
        int crossoverPoint;

    public
        Chromosome(City[] cities)

        {

            bool[] taken = new bool[cities.Length];

            cityList = new int[cities.Length];

            cost = 0.0;

            for (int i = 0; i < cityList.Length; i++)
                taken[i] = false;

            for (int i = 0; i < cityList.Length - 1; i++)

            {

                int icandidate;

                do

                {

                    icandidate = (int)(randObj.NextDouble() * (double)cityList.Length);

                } while (taken[icandidate]);

                cityList[i] = icandidate;

                taken[icandidate] = true;

                if (i == cityList.Length - 2)

                {

                    icandidate = 0;

                    while (taken[icandidate])
                        icandidate++;

                    cityList[i + 1] = icandidate;
                }
            }

            calculateCost(cities);

            crossoverPoint = 1;
        }

    public
        void calculateCost(City[] cities)

        {

            cost = 0;

            for (int i = 0; i < cityList.Length - 1; i++)

            {

                double dist = cities[cityList[i]].proximity(cities[cityList[i + 1]]);

                cost += dist;
            }
        }

    public
        double getCost()
        {
            return cost;
        }

    public
        int getCity(int i)

        {
            return cityList[i];
        }

    public
        void assignCities(int[] list)
        {
            for (int i = 0; i < cityList.Length; i++)
            {
                cityList[i] = list[i];
            }
        }

    public
        void assignCity(int index, int value)
        {
            cityList[index] = value;
        }

    public
        void assignCut(int cut)
        {
            crossoverPoint = cut;
        }

    public
        void assignMutation(double prob)
        {
            mutationPercent = prob;
        }

    public
        int mate(Chromosome father, Chromosome offspring1, Chromosome offspring2)
        {
            int crossoverPostion1 = (int)((randObj.NextDouble()) * (double)(cityList.Length - crossoverPoint));

            int crossoverPostion2 = crossoverPostion1 + crossoverPoint;

            int[] offset1 = new int[cityList.Length];

            int[] offset2 = new int[cityList.Length];

            bool[] taken1 = new bool[cityList.Length];

            bool[] taken2 = new bool[cityList.Length];

            for (int i = 0; i < cityList.Length; i++)
            {
                taken1[i] = false;
                taken2[i] = false;
            }

            for (int i = 0; i < cityList.Length; i++)
            {
                if (i < crossoverPostion1 || i >= crossoverPostion2)
                {
                    offset1[i] = -1;
                    offset2[i] = -1;
                }
                else
                {
                    int imother = cityList[i];
                    int ifather = father.getCity(i);
                    offset1[i] = ifather;
                    offset2[i] = imother;
                    taken1[ifather] = true;
                    taken2[imother] = true;
                }
            }
            for (int i = 0; i < crossoverPostion1; i++)
            {
                if (offset1[i] == -1)
                {
                    for (int j = 0; j < cityList.Length; j++)
                    {
                        int imother = cityList[j];
                        if (!taken1[imother])
                        {
                            offset1[i] = imother;
                            taken1[imother] = true;
                            break;
                        }
                    }
                }

                if (offset2[i] == -1)
                {

                    for (int j = 0; j < cityList.Length; j++)

                    {

                        int ifather = father.getCity(j);

                        if (!taken2[ifather])

                        {

                            offset2[i] = ifather;

                            taken2[ifather] = true;

                            break;
                        }
                    }
                }
            }

            for (int i = cityList.Length - 1; i >= crossoverPostion2; i--)

            {

                if (offset1[i] == -1)

                {

                    for (int j = cityList.Length - 1; j >= 0; j--)

                    {

                        int imother = cityList[j];

                        if (!taken1[imother])

                        {

                            offset1[i] = imother;

                            taken1[imother] = true;

                            break;
                        }
                    }
                }

                if (offset2[i] == -1)

                {

                    for (int j = cityList.Length - 1; j >= 0; j--)

                    {

                        int ifather = father.getCity(j);

                        if (!taken2[ifather])

                        {

                            offset2[i] = ifather;

                            taken2[ifather] = true;

                            break;
                        }
                    }
                }
            }

            offspring1.assignCities(offset1);

            offspring2.assignCities(offset2);

            int mutate = 0;

            int swapPoint1 = 0;

            int swapPoint2 = 0;

            if (randObj.NextDouble() < mutationPercent)

            {

                swapPoint1 = (int)(randObj.NextDouble() * (double)(cityList.Length));

                swapPoint2 = (int)(randObj.NextDouble() * (double)cityList.Length);

                int i = offset1[swapPoint1];

                offset1[swapPoint1] = offset1[swapPoint2];

                offset1[swapPoint2] = i;

                mutate++;
            }

            if (randObj.NextDouble() < mutationPercent)

            {

                swapPoint1 = (int)(randObj.NextDouble() * (double)(cityList.Length));

                swapPoint2 = (int)(randObj.NextDouble() * (double)cityList.Length);

                int i = offset2[swapPoint1];

                offset2[swapPoint1] = offset2[swapPoint2];

                offset2[swapPoint2] = i;

                mutate++;
            }

            return mutate;
        }

    public
        void PrintCity(int i, City[] cities)

        {

            System.Console.WriteLine("City " + i.ToString() + ": (" + cities[cityList[i]].getx().ToString() + ", "

                                     + cities[cityList[i]].gety().ToString() + ")");
        }

    public
        static void sortChromosomes(Chromosome[] chromosomes, int num)

        {

            bool swapped = true;

            Chromosome dummy;

            while (swapped)

            {

                swapped = false;

                for (int i = 0; i < num - 1; i++)

                {

                    if (chromosomes[i].getCost() > chromosomes[i + 1].getCost())

                    {

                        dummy = chromosomes[i];

                        chromosomes[i] = chromosomes[i + 1];

                        chromosomes[i + 1] = dummy;

                        swapped = true;
                    }
                }
            }
        }
    }

}

using System;

using System.Threading;

using System.IO;

namespace simga

{

    class GA_TSP

    {

    protected
        int cityCount;

    protected
        int populationSize;

    protected
        double mutationPercent;

    protected
        int matingPopulationSize;

    protected
        int favoredPopulationSize;

    protected
        int cutLength;

    protected
        int generation;

    protected
        Thread worker = null;

    protected
        bool started = false;

    protected
        City[] cities;

    protected
        Chromosome[] chromosomes;

    private
        string status = "";

    public
        GA_TSP()

        {
        }

    public
        void Initialization()

        {

            Random randObj = new Random();

            try

            {

                cityCount = 40;

                populationSize = 1000;

                mutationPercent = 0.05;
            }

            catch (Exception e)

            {

                cityCount = 100;
            }

            matingPopulationSize = populationSize / 2;

            favoredPopulationSize = matingPopulationSize / 2;

            cutLength = cityCount / 5;

            cities = new City[cityCount];

            for (int i = 0; i < cityCount; i++)

            {

                cities[i] = new City(

                    (int)(randObj.NextDouble() * 30), (int)(randObj.NextDouble() * 15));
            }

            chromosomes = new Chromosome[populationSize];

            for (int i = 0; i < populationSize; i++)

            {

                chromosomes[i] = new Chromosome(cities);

                chromosomes[i].assignCut(cutLength);

                chromosomes[i].assignMutation(mutationPercent);
            }

            Chromosome.sortChromosomes(chromosomes, populationSize);

            started = true;

            generation = 0;
        }

    public
        void TSPCompute()

        {

            double thisCost = 500.0;

            double oldCost = 0.0;

            double dcost = 500.0;

            int countSame = 0;

            Random randObj = new Random();

            while (countSame < 120)

            {

                generation++;

                int ioffset = matingPopulationSize;

                int mutated = 0;

                for (int i = 0; i < favoredPopulationSize; i++)

                {

                    Chromosome cmother = chromosomes[i];

                    int father = (int)(randObj.NextDouble() * (double)matingPopulationSize);

                    Chromosome cfather = chromosomes[father];

                    mutated += cmother.mate(cfather, chromosomes[ioffset], chromosomes[ioffset + 1]);

                    ioffset += 2;
                }

                for (int i = 0; i < matingPopulationSize; i++)

                {

                    chromosomes[i] = chromosomes[i + matingPopulationSize];

                    chromosomes[i].calculateCost(cities);
                }

                Chromosome.sortChromosomes(chromosomes, matingPopulationSize);

                double cost = chromosomes[0].getCost();

                dcost = Math.Abs(cost - thisCost);

                thisCost = cost;

                double mutationRate = 100.0 * (double)mutated / (double)matingPopulationSize;

                System.Console.WriteLine("Generation = " + generation.ToString() + " Cost = " + thisCost.ToString() + " Mutated Rate = " + mutationRate.ToString() + "%");

                if ((int)thisCost == (int)oldCost)

                {

                    countSame++;
                }

                else

                {

                    countSame = 0;

                    oldCost = thisCost;
                }
            }

            for (int i = 0; i < cities.Length; i++)

            {

                chromosomes[i].PrintCity(i, cities);
            }
        }

        [STAThread]

            static void Main(string[] args)

        {

            GA_TSP tsp = new GA_TSP();

            tsp.Initialization();

            tsp.TSPCompute();
        }

    }

    public class City

    {

    public
        City()

        {
        }
    private
        int xcoord;
    private
        int ycoord;
    public
        City(int x, int y)
        {

            xcoord = x;

            ycoord = y;
        }

    public
        int getx()

        {

            return xcoord;
        }

    public
        int gety()

        {

            return ycoord;
        }

    public
        int proximity(City cother)

        {

            return proximity(cother.getx(), cother.gety());
        }

    public
        int proximity(int x, int y)

        {

            int xdiff = xcoord - x;

            int ydiff = ycoord - y;

            return (int)Math.Sqrt(xdiff * xdiff + ydiff * ydiff);
        }
    }

}