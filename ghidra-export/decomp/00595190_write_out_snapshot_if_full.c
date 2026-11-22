// func write_out_snapshot_if_full @ 00595190 size=908

undefined4 write_out_snapshot_if_full(undefined4 *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  FILE *__s;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  char *pcVar7;
  char *pcVar8;
  undefined1 local_430;
  undefined1 local_42f;
  undefined1 local_42e;
  char acStack_42c [512];
  char acStack_22c [516];
  undefined8 local_28;
  
  memset(acStack_22c,0,0x200);
  local_430 = 0xef;
  local_42f = 0xbb;
  local_42e = 0xbf;
  if (snapshot_store_debug_switch != 0) {
    printf("[SNAPSHOT_STORE_DEBUG]%s()/%d write_out_snapshot_if_full\n","write_out_snapshot_if_full"
           ,0x1ef);
  }
  uVar4 = 0xffffffff;
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    local_28 = FUN_00524078();
    iVar1 = is_send_tftp_server();
    if (iVar1 == 0) {
      uVar4 = 0;
      recreate_new_file();
      *param_1 = 0;
      if (snapshot_store_debug_switch == 0) {
        return 0;
      }
      pcVar7 = "[SNAPSHOT_STORE_DEBUG]%s()/%d delete_entry\n";
      uVar3 = 0x223;
    }
    else {
      memset(acStack_42c,0,0x200);
      uVar5 = FUN_00524078();
      uVar4 = (undefined4)((ulonglong)uVar5 >> 0x20);
      iVar1 = access("/tmp/old_pkt_snapshot.csv",0);
      uVar6 = local_28;
      if (iVar1 == 0) {
        uVar6 = __udivdi3(uVar4,(int)uVar5,0,1000000);
        uVar5 = __umoddi3(uVar4,(int)uVar5,0,1000000,uVar6);
        pcVar7 = "old_pkt_snapshot.csv";
        pcVar8 = "old_pkt_snapshot.csv";
        iVar1 = param_2;
        snprintf(acStack_42c,0x200,"cd /tmp && tftp -p -r [%llu,%llu]%s -l %s %s");
        if (snapshot_store_debug_switch != 0) {
          printf("[SNAPSHOT_STORE_DEBUG]%s()/%d cmd %s\n","check_old_file_is_exit",0x1d9,acStack_42c
                 ,(int)((ulonglong)uVar6 >> 0x20),(int)uVar6,(int)((ulonglong)uVar5 >> 0x20),
                 (int)uVar5,pcVar7,pcVar8,iVar1);
        }
        uVar2 = system(acStack_42c);
        uVar6 = local_28;
        if ((((uVar2 & 0x7f) == 0) && ((uVar2 << 0x10) >> 0x18 == 0)) && (uVar2 != 0xffffffff)) {
          remove("/tmp/old_pkt_snapshot.csv");
          uVar6 = local_28;
          if (snapshot_store_debug_switch != 0) {
            printf("[SNAPSHOT_STORE_DEBUG]%s()/%d write_out_to_tftp\n","check_old_file_is_exit",
                   0x1e1);
            uVar6 = local_28;
          }
        }
      }
      local_28._0_4_ = (undefined4)((ulonglong)uVar6 >> 0x20);
      local_28._4_4_ = (undefined4)uVar6;
      uVar5 = __udivdi3(local_28._0_4_,local_28._4_4_,0,1000000);
      local_28 = uVar6;
      uVar6 = __umoddi3(local_28._0_4_,local_28._4_4_,0,1000000,uVar5);
      pcVar7 = "pkt_snapshot.csv";
      pcVar8 = "pkt_snapshot.csv";
      snprintf(acStack_22c,0x200,"cd /tmp && tftp -p -r [%llu,%llu]%s -l %s %s");
      if (snapshot_store_debug_switch != 0) {
        printf("[SNAPSHOT_STORE_DEBUG]%s()/%d cmd %s\n","write_out_snapshot_if_full",0x1ff,
               acStack_22c,(int)((ulonglong)uVar5 >> 0x20),(int)uVar5,
               (int)((ulonglong)uVar6 >> 0x20),(int)uVar6,pcVar7,pcVar8,param_2);
      }
      uVar2 = system(acStack_22c);
      if ((((uVar2 & 0x7f) != 0) || ((uVar2 << 0x10) >> 0x18 != 0)) || (uVar2 == 0xffffffff)) {
        recreate_new_file();
        *param_1 = 0;
        return 0;
      }
      *param_1 = 0;
      __s = (FILE *)open_snapshot_file(&DAT_00678548,1);
      if (__s == (FILE *)0x0) {
        uVar4 = 0xffffffff;
        if (snapshot_store_debug_switch == 0) {
          return 0xffffffff;
        }
        pcVar7 = &DAT_006e2830;
        uVar3 = 0x20c;
      }
      else {
        fwrite(&local_430,1,3,__s);
        fflush(__s);
        fwrite(&DAT_006dec98,0x159,1,__s);
        uVar4 = 0;
        close_snapshot_file();
        if (snapshot_store_debug_switch == 0) {
          return 0;
        }
        pcVar7 = "[SNAPSHOT_STORE_DEBUG]%s()/%d write_out_to_tftp\n";
        uVar3 = 0x215;
      }
    }
    printf(pcVar7,"write_out_snapshot_if_full",uVar3);
  }
  return uVar4;
}

