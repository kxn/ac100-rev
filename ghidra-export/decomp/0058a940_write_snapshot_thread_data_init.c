// func write_snapshot_thread_data_init @ 0058a940 size=1332

undefined4 write_snapshot_thread_data_init(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  FILE *__stream;
  char *__format;
  undefined4 uVar4;
  uint uVar5;
  undefined1 local_230;
  undefined1 local_22f;
  undefined1 local_22e;
  char acStack_22c [520];
  
  memset(acStack_22c,0,0x200);
  local_230 = 0xef;
  local_22f = 0xbb;
  local_22e = 0xbf;
  piVar2 = (int *)FUN_00408450(0x20,0x1ef);
  g_write_snapshot_data = piVar2;
  if (piVar2 == (int *)0x0) {
    if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_0058abd0;
    __format = "[CW_ERROR]%32s():%4d malloc write_snapshot_data failed\n";
    uVar4 = 0x1f2;
  }
  else {
    memset(piVar2,0,0x20);
    iVar3 = FUN_00408450(*(int *)(l_profile + 0x28) << 2,0x1f7);
    piVar2[1] = iVar3;
    piVar2 = g_write_snapshot_data;
    iVar3 = FUN_00408450(*(int *)(l_profile + 0x28) * 0xc,0x1f8);
    *piVar2 = iVar3;
    piVar2 = g_write_snapshot_data;
    iVar3 = FUN_00408450(0x200,0x1f9);
    piVar1 = g_write_snapshot_data;
    piVar2[6] = iVar3;
    iVar3 = l_profile;
    if ((((void *)piVar1[1] == (void *)0x0) || (*piVar1 == 0)) || (piVar1[6] == 0)) {
      if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) goto LAB_0058abd0;
      __format = "[CW_ERROR]%32s():%4d malloc failed\n";
      uVar4 = 0x1fc;
    }
    else {
      memset((void *)piVar1[1],0,*(int *)(l_profile + 0x28) << 2);
      memset((void *)*piVar1,0,*(int *)(iVar3 + 0x28) * 0xc);
      memset((void *)piVar1[6],0,0x200);
      for (uVar5 = 0; piVar2 = g_write_snapshot_data, uVar5 < *(uint *)(l_profile + 0x28);
          uVar5 = uVar5 + 1) {
        FUN_0051ad88(*g_write_snapshot_data + uVar5 * 0xc);
        memset(acStack_22c,0,0x200);
        snprintf(acStack_22c,0x200,"%s%d","snapshot_list_mutex_",uVar5);
        iVar3 = g_write_snapshot_data[1];
        uVar4 = FUN_00407f00(acStack_22c,0);
        *(undefined4 *)(iVar3 + uVar5 * 4) = uVar4;
        if (*(int *)(g_write_snapshot_data[1] + uVar5 * 4) == 0) {
          if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
          goto LAB_0058abd0;
          __format = "[CW_ERROR]%32s():%4d Failed to init mutex.\n";
          uVar4 = 0x20e;
          goto LAB_0058ad64;
        }
      }
      iVar3 = FUN_00407d80("snapshot_msg_cond_name");
      piVar2[4] = iVar3;
      piVar2 = g_write_snapshot_data;
      if (g_write_snapshot_data[4] == 0) {
        if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
        goto LAB_0058abd0;
        __format = "[CW_ERROR]%32s():%4d Create snapshot msg cond failed.\n";
        uVar4 = 0x216;
      }
      else {
        iVar3 = FUN_00407f00("snapshot_work_mutex",0);
        piVar2[2] = iVar3;
        if (g_write_snapshot_data[2] != 0) {
          __stream = fopen("/tmp/pkt_snapshot.csv","a+");
          if (__stream != (FILE *)0x0) {
            iVar3 = get_write_out_snapshot_count(g_write_snapshot_data + 5);
            if (iVar3 == 0) {
              if (g_write_snapshot_data[5] == 0) {
                fwrite(&local_230,1,3,__stream);
                fflush(__stream);
                fwrite(&DAT_006dec98,0x159,1,__stream);
              }
              else {
                g_write_snapshot_data[5] = g_write_snapshot_data[5] + -1;
              }
            }
            else {
              fclose(__stream);
              __stream = fopen("/tmp/pkt_snapshot.csv","w+");
              if (__stream == (FILE *)0x0) goto LAB_0058abd0;
              fwrite(&local_230,1,3,__stream);
              fflush(__stream);
              fwrite(&DAT_006dec98,0x159,1,__stream);
              g_write_snapshot_data[5] = 0;
            }
            fclose(__stream);
            return 0;
          }
          goto LAB_0058abd0;
        }
        if ((capwap_err_switch == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
        goto LAB_0058abd0;
        __format = "[CW_ERROR]%32s():%4d Failed to init mutex.\n";
        uVar4 = 0x21d;
      }
    }
  }
LAB_0058ad64:
  printf(__format,"write_snapshot_thread_data_init",uVar4);
LAB_0058abd0:
  if (g_write_snapshot_data[1] != 0) {
    free_mutex_array();
    FUN_00407df0(g_write_snapshot_data[1]);
    g_write_snapshot_data[1] = 0;
  }
  if (g_write_snapshot_data[2] == 0) {
    iVar3 = *g_write_snapshot_data;
  }
  else {
    FUN_00408360();
    g_write_snapshot_data[2] = 0;
    iVar3 = *g_write_snapshot_data;
  }
  if (iVar3 != 0) {
    FUN_00407df0();
    *g_write_snapshot_data = 0;
  }
  if (g_write_snapshot_data[6] != 0) {
    FUN_00407df0();
    g_write_snapshot_data[6] = 0;
  }
  if (g_write_snapshot_data[4] != 0) {
    FUN_00408220();
    g_write_snapshot_data[4] = 0;
  }
  if (g_write_snapshot_data != (int *)0x0) {
    FUN_00407df0();
    g_write_snapshot_data = (int *)0x0;
  }
  return 0xffffffff;
}

