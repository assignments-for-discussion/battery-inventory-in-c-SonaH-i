#include <stdio.h>
#include <assert.h>

struct CountsByUsage {
  int lowCount;
  int mediumCount;
  int highCount;
};

struct CountsByUsage countBatteriesByUsage(const int* cycles, int nBatteries) {
  struct CountsByUsage counts = {0, 0, 0};
  int countlow=0;
  int countmedium=0;
  int counthigh=0;
  for(int i=0;i<nBatteries;i++){
    if(cycles[i]<310){
      countlow++;
    }
    else if(cycles[i]>=310 && cycles[i]>=929){
      countmedium++;
    }
    else{
      counthigh++;
    }
  }
  counts[0]=countlow;
  counts[1]=countmedium;
  counts[2]=counthigh;
  return counts;
}

void testBucketingByNumberOfCycles() {
  const int chargeCycleCounts[] = {100, 300, 500, 600, 900, 1000};
  const int numberOfBatteries = sizeof(chargeCycleCounts) / sizeof(chargeCycleCounts[0]);
  printf("Counting batteries by usage cycles...\n");
  struct CountsByUsage counts = countBatteriesByUsage(chargeCycleCounts, numberOfBatteries);
  assert(counts.lowCount == 2);
  assert(counts.mediumCount == 3);
  assert(counts.highCount == 1);
  printf("Done counting :)\n");
}

int main() {
  testBucketingByNumberOfCycles();
  return 0;
}
