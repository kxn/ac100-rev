// func cw_priv_radio_role_table_control_dump @ 0057dd68 size=372

undefined4 cw_priv_radio_role_table_control_dump(int param_1)

{
  char *__format;
  uint uVar1;
  byte *pbVar2;
  byte *pbVar3;
  int iVar4;
  
  if (capwap_debug_switch == 0) {
    pbVar3 = *(byte **)(param_1 + 0x10);
  }
  else {
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      pbVar3 = *(byte **)(param_1 + 0x10);
    }
    else {
      printf("[CW_DEBUG]%32s():%4d cw_priv_radio_role_table_control_dump ENTER\n",
             "cw_priv_radio_role_table_control_dump",400);
      pbVar3 = *(byte **)(param_1 + 0x10);
    }
  }
  if (pbVar3 != (byte *)0x0) {
    printf("\t\t\tType: (t=%d,l=%d) radio role table control\r\n",(uint)*(ushort *)(param_1 + 0xc),
           (uint)*(ushort *)(param_1 + 0xe));
    printf("\t\t\t\tType: private rrt control(%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
    printf("\t\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
    printf("\t\t\t\tElement count: %d \r\n",(uint)*pbVar3);
    if (*pbVar3 != 0) {
      iVar4 = 0;
      printf("\t\t\t\t\t*****tlv Message Element of radio role table control private(%d)*****\n",
             (uint)*(ushort *)(param_1 + 0xc));
      while (iVar4 < (int)(uint)*pbVar3) {
        pbVar2 = (byte *)(*(int *)(pbVar3 + 4) + iVar4 * 8);
        printf("\t\t\t\t\tTlv element: (t=%d,l=%d) \r\n",(uint)*pbVar2,(uint)*(ushort *)(pbVar2 + 2)
              );
        if (*pbVar2 == 0) {
          uVar1 = (uint)**(byte **)(pbVar2 + 4);
          __format = "\t\t\t\t\t\ttable_id=%d\r\n";
LAB_0057de84:
          printf(__format,uVar1);
          iVar4 = iVar4 + 1;
        }
        else {
          if (*pbVar2 == 1) {
            __format = "\t\t\t\t\t\tparam_capability=%d\r\n";
            uVar1 = **(uint **)(pbVar2 + 4);
            goto LAB_0057de84;
          }
          iVar4 = iVar4 + 1;
        }
      }
    }
  }
  return 0;
}

