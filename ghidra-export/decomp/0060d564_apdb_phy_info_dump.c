// func apdb_phy_info_dump @ 0060d564 size=620

void apdb_phy_info_dump(void)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  if ((l_apdb_ap_item_cur != 0) && (iVar10 = 0, 0 < l_apdb_ap_item_cnt_cur)) {
    for (; iVar10 < l_apdb_ap_item_cnt_cur; iVar10 = iVar10 + 1) {
      iVar9 = 0;
      iVar6 = iVar10 * 0x58;
      while (iVar9 < *(int *)(l_apdb_ap_item_cur + iVar6 + 0x4c)) {
        iVar5 = iVar9 * 0x168;
        iVar1 = *(int *)(l_apdb_ap_item_cur + iVar6 + 0x54) + iVar5;
        if (*(int *)(iVar1 + 0x164) == 0) {
          iVar9 = iVar9 + 1;
        }
        else {
          iVar8 = 0;
          if (*(int *)(iVar1 + 0x160) < 1) {
            iVar9 = iVar9 + 1;
          }
          else {
            while (iVar1 = *(int *)(l_apdb_ap_item_cur + iVar6 + 0x54) + iVar5,
                  iVar8 < *(int *)(iVar1 + 0x160)) {
              iVar7 = iVar8 * 0x38;
              iVar1 = *(int *)(iVar1 + 0x164) + iVar7;
              if (*(char *)(iVar1 + 0x14) == '\0') {
                iVar8 = iVar8 + 1;
              }
              else {
                if (*(int *)(iVar1 + 0x2c) != 0) {
                  puts(
                      "================================================================================"
                      );
                  psVar2 = (short *)(*(int *)(((undefined4 *)(l_apdb_ap_item_cur + iVar6))[0x15] +
                                              iVar5 + 0x164) + iVar7);
                  printf("ap_id=%d, hwver=%d.%d, phy_num=%d \n",
                         *(undefined4 *)(l_apdb_ap_item_cur + iVar6),(int)*psVar2,(int)psVar2[1],
                         (uint)*(byte *)(psVar2 + 10));
                  for (iVar1 = 0;
                      iVar3 = *(int *)(*(int *)(l_apdb_ap_item_cur + iVar6 + 0x54) + iVar5 + 0x164)
                              + iVar7, iVar1 < (int)(uint)*(byte *)(iVar3 + 0x14); iVar1 = iVar1 + 1
                      ) {
                    iVar4 = iVar1 * 8;
                    printf("    phy=%d\n",(uint)*(byte *)(*(int *)(iVar3 + 0x2c) + iVar4));
                    printf("    type=%d\n",
                           (uint)*(byte *)(*(int *)(*(int *)(*(int *)(l_apdb_ap_item_cur + iVar6 +
                                                                     0x54) + iVar5 + 0x164) + iVar7
                                                   + 0x2c) + iVar4 + 1));
                    printf("    speed=%d\n",
                           *(undefined4 *)
                            (*(int *)(*(int *)(*(int *)(l_apdb_ap_item_cur + iVar6 + 0x54) + iVar5 +
                                              0x164) + iVar7 + 0x2c) + iVar4 + 4));
                    putchar(10);
                  }
                }
                iVar8 = iVar8 + 1;
              }
            }
            iVar9 = iVar9 + 1;
          }
        }
      }
    }
    return;
  }
  puts("apdb_ap_cur is null");
  return;
}

