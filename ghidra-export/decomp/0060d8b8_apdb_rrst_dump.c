// func apdb_rrst_dump @ 0060d8b8 size=1

void apdb_rrst_dump(void)

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
  int iStack_38;
  int iStack_34;
  int iStack_30;
  
  puts("enter apdb rrst dump");
  if ((l_apdb_ap_item_cur == 0) || (iStack_38 = 0, l_apdb_ap_item_cnt_cur < 1)) {
    (*(code *)PTR_puts_00758f90)("apdb_ap_cur is null");
    return;
  }
  do {
    if (l_apdb_ap_item_cnt_cur <= iStack_38) {
      return;
    }
    iVar5 = iStack_38 * 0x58;
    for (iStack_30 = 0; iStack_30 < *(int *)(l_apdb_ap_item_cur + iVar5 + 0x4c);
        iStack_30 = iStack_30 + 1) {
      iVar4 = iStack_30 * 0x168;
      iVar1 = *(int *)(l_apdb_ap_item_cur + iVar5 + 0x54) + iVar4;
      if ((*(int *)(iVar1 + 0x164) != 0) && (0 < *(int *)(iVar1 + 0x160))) {
        for (iStack_34 = 0; iVar1 = *(int *)(l_apdb_ap_item_cur + iVar5 + 0x54) + iVar4,
            iStack_34 < *(int *)(iVar1 + 0x160); iStack_34 = iStack_34 + 1) {
          iVar6 = iStack_34 * 0x38;
          iVar1 = *(int *)(iVar1 + 0x164) + iVar6;
          if ((0 < *(int *)(iVar1 + 4)) && (*(int *)(iVar1 + 0x34) != 0)) {
            puts("====================");
            psVar2 = (short *)(*(int *)(((undefined4 *)(l_apdb_ap_item_cur + iVar5))[0x15] + iVar4 +
                                       0x164) + iVar6);
            printf("apdb_id=%d, hwver=%d.%d, rrst_row_cnt=%d \n",
                   *(undefined4 *)(l_apdb_ap_item_cur + iVar5),(int)*psVar2,(int)psVar2[1],
                   *(undefined4 *)(psVar2 + 2));
            for (iVar1 = 0;
                iVar1 < *(int *)(*(int *)(*(int *)(l_apdb_ap_item_cur + iVar5 + 0x54) + iVar4 +
                                         0x164) + iVar6 + 4); iVar1 = iVar1 + 1) {
              iVar8 = 0;
              iVar7 = iVar1 * 0x1fc;
              do {
                if (*(char *)(*(int *)(*(int *)(*(int *)(l_apdb_ap_item_cur + iVar5 + 0x54) + iVar4
                                               + 0x164) + iVar6 + 0x34) + iVar7 + iVar8 + 9) ==
                    '\x01') {
                  printf("%d, ",iVar8);
                }
                iVar8 = iVar8 + 1;
              } while (iVar8 != 0x20);
              for (iVar8 = 0;
                  iVar3 = *(int *)(*(int *)(*(int *)(l_apdb_ap_item_cur + iVar5 + 0x54) + iVar4 +
                                           0x164) + iVar6 + 0x34) + iVar7,
                  iVar8 < (int)(uint)*(byte *)(iVar3 + 8); iVar8 = iVar8 + 1) {
                iVar9 = iVar8 * 0x74;
                printf("        radio_id=%d:\n",(uint)*(byte *)(iVar3 + iVar9 + 0x98));
                printf("            bandwidth=%d:\n",
                       (uint)*(byte *)(*(int *)(*(int *)(*(int *)(l_apdb_ap_item_cur + iVar5 + 0x54)
                                                         + iVar4 + 0x164) + iVar6 + 0x34) + iVar7 +
                                       iVar9 + 0x99));
                printf("            default_channel=%d:\n",
                       (int)*(short *)(*(int *)(*(int *)(*(int *)(l_apdb_ap_item_cur + iVar5 + 0x54)
                                                         + iVar4 + 0x164) + iVar6 + 0x34) + iVar7 +
                                       iVar9 + 0x30));
                printf("            is_channel_equal=%d:\n",
                       *(undefined4 *)
                        (*(int *)(*(int *)(*(int *)(l_apdb_ap_item_cur + iVar5 + 0x54) + iVar4 +
                                          0x164) + iVar6 + 0x34) + iVar7 + iVar9 + 0x9c));
                printf("            radio_abstract_status=%d:\n",
                       *(undefined4 *)
                        (*(int *)(*(int *)(*(int *)(l_apdb_ap_item_cur + iVar5 + 0x54) + iVar4 +
                                          0x164) + iVar6 + 0x34) + iVar7 + iVar9 + 0x2c));
                iVar3 = 0;
                printf("            bind_id=%d:\n",
                       (uint)*(byte *)(*(int *)(*(int *)(*(int *)(l_apdb_ap_item_cur + iVar5 + 0x54)
                                                         + iVar4 + 0x164) + iVar6 + 0x34) + iVar7 +
                                       iVar9 + 0x9a));
                printf("            chnls=");
                do {
                  if (*(short *)(*(int *)(*(int *)(*(int *)(l_apdb_ap_item_cur + iVar5 + 0x54) +
                                                   iVar4 + 0x164) + iVar6 + 0x34) + iVar7 +
                                 (iVar8 * 0x3a + iVar3 + 0x14) * 2 + 10) == 0) break;
                  iVar3 = iVar3 + 1;
                  printf("%d, ");
                } while (iVar3 != 0x33);
                putchar(10);
              }
            }
          }
        }
      }
    }
    iStack_38 = iStack_38 + 1;
  } while( true );
}

