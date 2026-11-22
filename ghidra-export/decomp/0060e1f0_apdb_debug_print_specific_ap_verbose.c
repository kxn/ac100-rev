// func apdb_debug_print_specific_ap_verbose @ 0060e1f0 size=1

void apdb_debug_print_specific_ap_verbose(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  int iVar7;
  int iVar8;
  undefined1 auStack_58 [40];
  int iStack_30;
  
  iVar8 = 0;
  FUN_004082d0(l_apdb_mutex,0xffffffff);
  if (l_apdb_ap_item_cur == 0) {
    if (apdb_debug_switch != 0) {
      printf("[APDB_DEBUG]%s()/line %d : apdb is empty.\n","apdb_print_specific_ap_verbose",0x2c13);
    }
  }
  else {
    while (iVar8 < l_apdb_ap_item_cnt_cur) {
      iStack_30 = iVar8 * 0x58;
      if (*(int *)(l_apdb_ap_item_cur + iStack_30) == param_1) {
        FUN_00408570(((int *)(l_apdb_ap_item_cur + iStack_30))[0x14],_fw_id_hash_show_cb,0);
        for (iVar7 = 0; iVar7 < *(int *)(l_apdb_ap_item_cur + iStack_30 + 0x4c); iVar7 = iVar7 + 1)
        {
          iVar5 = *(int *)(l_apdb_ap_item_cur + iStack_30 + 0x54) + iVar7 * 0x168;
          printf("AP name: %s, nick name: %s, device type:%s id: %x\n",iVar5 + 0xda,iVar5 + 0x11b,
                 iVar5 + 0x98,*(undefined4 *)(iVar5 + 0x10));
          printf("  vendor: %d, wire_phy: %d, ishd: %d, version: %d\n",*(undefined4 *)(iVar5 + 0x18)
                 ,*(undefined4 *)(iVar5 + 0x14),*(undefined4 *)(iVar5 + 0x1c),
                 *(undefined4 *)(iVar5 + 0x15c));
          printf("  nego: %d, model_cnt: %d, support trunk: %d \n",*(undefined4 *)(iVar5 + 0x94),
                 *(undefined4 *)(iVar5 + 0x160),*(undefined4 *)(iVar5 + 0x70));
          printf("  support cloud upgrade: %d",*(undefined4 *)(iVar5 + 0x74));
          if (*(int *)(iVar5 + 0x74) != 0) {
            iVar4 = 0;
            printf(", hardware id:");
            iVar1 = iVar5;
            do {
              iVar4 = iVar4 + 1;
              printf("%02X",(uint)*(byte *)(iVar1 + 0x84));
              iVar1 = iVar5 + iVar4;
            } while (iVar4 != 0x10);
          }
          putchar(10);
          printf("  support large fw upgrade: %d",*(undefined4 *)(iVar5 + 0x78));
          printf("  is mesh device:%d, product type: %d\n",*(undefined4 *)(iVar5 + 0x7c),
                 *(undefined4 *)(iVar5 + 0x80));
          for (iVar1 = 0; iVar1 < *(int *)(iVar5 + 0x160); iVar1 = iVar1 + 1) {
            psVar6 = (short *)(*(int *)(iVar5 + 0x164) + iVar1 * 0x38);
            printf("    hw_ver: %d.%d, is_nego: %d, learned: %d, radio_cnt %d\n",(int)*psVar6,
                   (int)psVar6[1],*(undefined4 *)(psVar6 + 0x12),*(undefined4 *)(psVar6 + 0x10),
                   *(undefined4 *)(psVar6 + 8));
            for (iVar4 = 0; iVar4 < *(int *)(psVar6 + 8); iVar4 = iVar4 + 1) {
              iVar2 = *(int *)(psVar6 + 0x14);
              memset(auStack_58,0,0x21);
              piVar3 = (int *)(iVar2 + iVar4 * 0x114);
              _apdb_extend_cap_transfer_to_str(piVar3 + 0x40,0x10,auStack_58,0x21);
              printf("      %s: maxssid: %d, max_sta: %d, max_tx: %d, min_tx: %d, dft_tx: %d, real_max_tx: %d, real_min_tx: %d, real_dft_tx: %d, dft_bw: %d, 11ac: %d, 11ax: %d, 11be:%d, 240m:%d, 160m: %d, 80m+80m: %d, wpa3: %d, mutex_ch: %s, max_tx_stream: %d, min_rx_stream: %d, extend_cap:%s\n"
                     ,(&PTR_s_2_4GHz_00702480)[*piVar3],(int)*(short *)(piVar3 + 7),
                     (int)*(short *)((int)piVar3 + 0x1e),(int)*(short *)(piVar3 + 8),
                     (int)*(short *)((int)piVar3 + 0x22),(int)*(short *)(piVar3 + 9),
                     (int)*(short *)((int)piVar3 + 0x26),(int)*(short *)(piVar3 + 10),
                     (int)*(short *)((int)piVar3 + 0x2a),piVar3[0xc],piVar3[1],piVar3[2],piVar3[5],
                     piVar3[6],piVar3[3],piVar3[4],piVar3[0xd],piVar3 + 0xe,
                     (uint)*(byte *)(piVar3 + 0xb),(uint)*(byte *)((int)piVar3 + 0x2d),auStack_58);
              piVar3 = *(int **)(*(int *)(psVar6 + 0x14) + iVar4 * 0x114 + 0x110);
              if (piVar3 != (int *)0x0) {
                _apdb_extend_cap_transfer_to_str(piVar3 + 0x40,0x10,auStack_58,0x21);
                printf("         %s: maxssid: %d, max_sta: %d, max_tx: %d, min_tx: %d, dft_tx: %d, real_max_tx: %d, real_min_tx: %d, real_dft_tx: %d, dft_bw: %d, 11ac: %d, 11ax: %d, 11be:%d, 240m:%d, 160m: %d, 80m+80m: %d, wpa3: %d, mutex_ch: %s, max_tx_stream: %d, min_rx_stream: %d, extend_cap:%s\n"
                       ,(&PTR_s_2_4GHz_00702480)[*piVar3],(int)*(short *)(piVar3 + 7),
                       (int)*(short *)((int)piVar3 + 0x1e),(int)*(short *)(piVar3 + 8),
                       (int)*(short *)((int)piVar3 + 0x22),(int)*(short *)(piVar3 + 9),
                       (int)*(short *)((int)piVar3 + 0x26),(int)*(short *)(piVar3 + 10),
                       (int)*(short *)((int)piVar3 + 0x2a),piVar3[0xc],piVar3[1],piVar3[2],piVar3[5]
                       ,piVar3[6],piVar3[3],piVar3[4],piVar3[0xd],piVar3 + 0xe,
                       (uint)*(byte *)(piVar3 + 0xb),(uint)*(byte *)((int)piVar3 + 0x2d),auStack_58)
                ;
              }
            }
          }
        }
        iVar8 = iVar8 + 1;
      }
      else {
        iVar8 = iVar8 + 1;
      }
    }
  }
  FUN_00407f30(l_apdb_mutex);
  return;
}

