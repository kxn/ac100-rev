// func apdb_region_list_dump @ 0060dd08 size=724

void apdb_region_list_dump(void)

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
  int local_30;
  
  if ((l_apdb_ap_item_cur != 0) && (local_30 = 0, 0 < l_apdb_ap_item_cnt_cur)) {
    for (; local_30 < l_apdb_ap_item_cnt_cur; local_30 = local_30 + 1) {
      iVar9 = 0;
      iVar5 = local_30 * 0x58;
      while( true ) {
        if (*(int *)(l_apdb_ap_item_cur + iVar5 + 0x4c) <= iVar9) break;
        iVar4 = iVar9 * 0x168;
        iVar1 = *(int *)(l_apdb_ap_item_cur + iVar5 + 0x54) + iVar4;
        if (*(int *)(iVar1 + 0x164) == 0) {
          iVar9 = iVar9 + 1;
        }
        else {
          iVar8 = 0;
          if (*(int *)(iVar1 + 0x160) < 1) {
            iVar9 = iVar9 + 1;
          }
          else {
            while (iVar1 = *(int *)(l_apdb_ap_item_cur + iVar5 + 0x54) + iVar4,
                  iVar8 < *(int *)(iVar1 + 0x160)) {
              iVar6 = iVar8 * 0x38;
              iVar1 = *(int *)(iVar1 + 0x164) + iVar6;
              if (*(char *)(iVar1 + 0x15) == '\0') {
                iVar8 = iVar8 + 1;
              }
              else {
                if (*(int *)(iVar1 + 0x30) != 0) {
                  puts(
                      "================================================================================"
                      );
                  psVar2 = (short *)(*(int *)(((undefined4 *)(l_apdb_ap_item_cur + iVar5))[0x15] +
                                              iVar4 + 0x164) + iVar6);
                  printf("apdb_id=%d, hwver=%d.%d, region_cnt=%d \n",
                         *(undefined4 *)(l_apdb_ap_item_cur + iVar5),(int)*psVar2,(int)psVar2[1],
                         (uint)*(byte *)((int)psVar2 + 0x15));
                  for (iVar1 = 0;
                      iVar3 = *(int *)(*(int *)(l_apdb_ap_item_cur + iVar5 + 0x54) + iVar4 + 0x164)
                              + iVar6, iVar1 < (int)(uint)*(byte *)(iVar3 + 0x15); iVar1 = iVar1 + 1
                      ) {
                    iVar7 = iVar1 * 0xc3;
                    printf("\tcode=%d\n",(uint)*(byte *)(*(int *)(iVar3 + 0x30) + iVar7));
                    printf("\tname_len=%d\n",
                           (uint)*(byte *)(*(int *)(*(int *)(*(int *)(l_apdb_ap_item_cur + iVar5 +
                                                                     0x54) + iVar4 + 0x164) + iVar6
                                                   + 0x30) + iVar7 + 1));
                    printf("\tch_lst_len=%d\n",
                           (uint)*(byte *)(*(int *)(*(int *)(*(int *)(l_apdb_ap_item_cur + iVar5 +
                                                                     0x54) + iVar4 + 0x164) + iVar6
                                                   + 0x30) + iVar7 + 2));
                    printf("\tname:%s\n",
                           *(int *)(*(int *)(*(int *)(l_apdb_ap_item_cur + iVar5 + 0x54) + iVar4 +
                                            0x164) + iVar6 + 0x30) + iVar7 + 3);
                    printf("\tch_lst:%s\n",
                           *(int *)(*(int *)(*(int *)(l_apdb_ap_item_cur + iVar5 + 0x54) + iVar4 +
                                            0x164) + iVar6 + 0x30) + iVar7 + 0x43);
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

