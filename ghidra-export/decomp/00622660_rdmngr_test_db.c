// func rdmngr_test_db @ 00622660 size=1

void rdmngr_test_db(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  
  uVar6 = 0;
  while( true ) {
    iVar5 = DAT_007cc65c;
    iVar1 = apmngr_db_get_ap_max();
    iVar2 = apmngr_db_get_template_max();
    iVar3 = apmngr_db_get_sensor_max();
    if ((uint)((iVar1 + iVar2 + iVar3) * iVar5) <= uVar6) break;
    piVar4 = *(int **)(DAT_007cc650 + uVar6 * 8 + 4);
    if (piVar4 == (int *)0x0) {
      uVar6 = uVar6 + 1;
    }
    else {
      iVar5 = *piVar4;
      if (iVar5 == -1) {
        uVar6 = uVar6 + 1;
      }
      else {
        rdmngr_db_rd_update(iVar5,2);
        uVar6 = uVar6 + 1;
      }
    }
  }
  return;
}

