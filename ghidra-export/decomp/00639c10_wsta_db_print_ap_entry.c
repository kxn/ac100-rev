// func wsta_db_print_ap_entry @ 00639c10 size=428

void wsta_db_print_ap_entry(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  char *__format;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  if (param_1 != 0) {
    iVar7 = param_2 * 4;
    iVar5 = 0;
    for (uVar6 = 1; uVar1 = rdmngr_profile_get_max_rd_per_ap(), uVar6 <= uVar1; uVar6 = uVar6 + 1) {
      iVar4 = 0;
      uVar1 = 1;
      while (uVar2 = rdmngr_profile_get_max_wlan_per_rd(), uVar1 <= uVar2) {
        if (*(int *)(*(int *)(*(int *)(DAT_007cc6e4 + iVar7) + iVar5) + iVar4 + 8) == 0) {
          uVar1 = uVar1 + 1;
          iVar4 = iVar4 + 0xc;
        }
        else {
          puts("#################################################################");
          printf("ap/rd/wlan    = [%d/%d/%d]\n",param_2,uVar6,uVar1);
          printf("wsta_num      = %d\n",
                 *(undefined4 *)(*(int *)(*(int *)(DAT_007cc6e4 + iVar7) + iVar5) + iVar4 + 8));
          printf("wsta_id       = ");
          for (iVar3 = FUN_004081b0(*(int *)(*(int *)(DAT_007cc6e4 + iVar7) + iVar5) + iVar4);
              iVar3 != 0; iVar3 = FUN_00408680(iVar3)) {
            if (*(char *)(iVar3 + 0x34) == '\0') {
              __format = "%d/";
            }
            else {
              __format = "%d(roam)/";
            }
            printf(__format,*(undefined4 *)(iVar3 + 0x1c));
          }
          uVar1 = uVar1 + 1;
          putchar(10);
          iVar4 = iVar4 + 0xc;
        }
      }
      iVar5 = iVar5 + 4;
    }
  }
  return;
}

