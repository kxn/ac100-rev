// func wsta_roam_db_print_pmk_all @ 00483020 size=500

void wsta_roam_db_print_pmk_all(void)

{
  byte bVar1;
  int *piVar2;
  uint extraout_v1;
  char *__format;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  printf("total num:\t%d\n",DAT_00767550);
  FUN_00407e70();
  while (iVar5 < max_roam_sta) {
    piVar3 = (int *)(DAT_00767548 + iVar5 * 0x4c);
    if (piVar3 == (int *)0x0) {
      iVar5 = iVar5 + 1;
    }
    else if (*piVar3 == 0) {
      iVar5 = iVar5 + 1;
    }
    else {
      iVar4 = 0;
      puts("#################################################################");
      printf("id       = %d\n",piVar3[1]);
      printf("mac      = ");
      do {
        if (iVar4 == 5) {
          bVar1 = *(byte *)((int)piVar3 + 0x15);
          __format = "%02x\r\n";
        }
        else {
          bVar1 = *(byte *)((int)piVar3 + iVar4 + 0x10);
          __format = "%02x-";
        }
        iVar4 = iVar4 + 1;
        printf(__format,(uint)bVar1);
      } while (iVar4 != 6);
      iVar4 = 0;
      printf("wserv_id = %d\n",piVar3[2]);
      printf("pairwise = %d\n",piVar3[3]);
      printf("pmk      = ");
      piVar2 = piVar3;
      do {
        iVar4 = iVar4 + 1;
        printf("%02x",(uint)*(byte *)((int)piVar2 + 0x16));
        piVar2 = (int *)((int)piVar3 + iVar4);
      } while (iVar4 != 0x20);
      iVar4 = 0;
      putchar(10);
      printf("pmk_name = ");
      piVar2 = piVar3;
      while( true ) {
        iVar4 = iVar4 + 1;
        printf("%02x",(uint)*(byte *)((int)piVar2 + 0x36));
        if (iVar4 == 0x10) break;
        piVar2 = (int *)((int)piVar3 + iVar4);
      }
      iVar5 = iVar5 + 1;
      putchar(10);
      iVar4 = piVar3[0x12] - extraout_v1;
      if ((uint)piVar3[0x12] <= extraout_v1) {
        iVar4 = 0;
      }
      printf("time_to_expire = %d\n",iVar4);
    }
  }
  return;
}

