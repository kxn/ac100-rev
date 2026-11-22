// func write_snapshot @ 00594c34 size=1372

undefined4 write_snapshot(undefined4 param_1,FILE *param_2,int param_3)

{
  char *__s;
  char *__s_00;
  char *__s_01;
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  char cVar6;
  size_t sVar4;
  byte *pbVar5;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  char *__s_02;
  char *__format;
  undefined4 uVar10;
  undefined8 uVar11;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  
  if ((param_3 == 0) || (param_2 == (FILE *)0x0)) {
    __s_01 = (char *)0x0;
    __s_00 = (char *)0x0;
  }
  else {
    if (snapshot_store_debug_switch != 0) {
      printf("[SNAPSHOT_STORE_DEBUG]%s()/%d write_snapshot1\n","write_snapshot",0x177);
    }
    __s = (char *)FUN_00408450(0x200,0x178);
    __s_00 = (char *)FUN_00408450(0x200,0x179);
    __s_01 = (char *)FUN_00408450(0x200,0x17a);
    if (__s != (char *)0x0) {
      uVar10 = 0xffffffff;
      if ((__s_00 != (char *)0x0) && (__s_01 != (char *)0x0)) {
        memset(__s,0,0x200);
        memset(__s_00,0,0x200);
        memset(__s_01,0,0x200);
        local_2c = *(undefined4 *)(param_3 + 0x14);
        local_30 = *(undefined4 *)(param_3 + 0x10);
        uVar11 = __udivdi3(local_30,local_2c,0,1000000);
        uVar10 = (undefined4)((ulonglong)uVar11 >> 0x20);
        uVar7 = (undefined4)uVar11;
        uVar11 = __umoddi3(local_30,local_2c,0,1000000);
        uVar1 = (undefined4)((ulonglong)uVar11 >> 0x20);
        uVar8 = (undefined4)uVar11;
        uVar9 = (uint)*(byte *)(param_3 + 0x38);
        if (uVar9 - 1 < 2) {
          pbVar5 = *(byte **)(param_3 + 0x54);
          snprintf(__s,0x200,
                   "%u,\"[%llu,%llu]\",%02X-%02X-%02X-%02X-%02X-%02X,,%d,%d,%d,%d,%d,%d,%d,%d,%d,,,,"
                   ,param_1,uVar10,uVar7,uVar1,uVar8,(uint)*(byte *)(param_3 + 0x2c),
                   (uint)*(byte *)(param_3 + 0x2d),(uint)*(byte *)(param_3 + 0x2e),
                   (uint)*(byte *)(param_3 + 0x2f),(uint)*(byte *)(param_3 + 0x30),
                   (uint)*(byte *)(param_3 + 0x31),uVar9,*(undefined4 *)(param_3 + 0x34),
                   (uint)*(byte *)(param_3 + 0x32),(uint)*pbVar5,(uint)pbVar5[1],(uint)pbVar5[2],
                   *(undefined4 *)(pbVar5 + 4),*(undefined4 *)(pbVar5 + 8),
                   *(undefined4 *)(pbVar5 + 0xc));
        }
        else if (uVar9 == 5) {
          memset(__s_01,0,0x200);
          memcpy(&local_48,(void *)(param_3 + 0x18),0x14);
          if (local_48._0_1_ == '\x01') {
            sVar4 = strlen(__s_01);
            snprintf(__s_01 + sVar4,0x200 - sVar4,"%u",local_44);
            pbVar5 = *(byte **)(param_3 + 0x54);
          }
          else {
            FUN_00408190(local_48,local_44,local_40,local_3c,local_38,__s_01,0x200,&DAT_00698ca0);
            pbVar5 = *(byte **)(param_3 + 0x54);
          }
          snprintf(__s,0x200,"%u,\"[%llu,%llu]\",,%s,%d,,,%d,%d,%d,%d,%d,%d,,,,",param_1,uVar10,
                   uVar7,uVar1,uVar8,__s_01,(uint)*(byte *)(param_3 + 0x38),(uint)*pbVar5,
                   (uint)pbVar5[1],(uint)pbVar5[2],*(undefined4 *)(pbVar5 + 4),
                   *(undefined4 *)(pbVar5 + 8),*(undefined4 *)(pbVar5 + 0xc));
        }
        else {
          puVar2 = *(undefined4 **)(param_3 + 0x58);
          if (puVar2 != (undefined4 *)0x0) {
            snprintf(__s,0x200,
                     "%u,\"[%llu,%llu]\",%02X-%02X-%02X-%02X-%02X-%02X,,%d,%d,%d,,,,,,,%d,%d,%d,",
                     param_1,uVar10,uVar7,uVar1,uVar8,(uint)*(byte *)(param_3 + 0x2c),
                     (uint)*(byte *)(param_3 + 0x2d),(uint)*(byte *)(param_3 + 0x2e),
                     (uint)*(byte *)(param_3 + 0x2f),(uint)*(byte *)(param_3 + 0x30),
                     (uint)*(byte *)(param_3 + 0x31),uVar9,*(undefined4 *)(param_3 + 0x34),
                     (uint)*(byte *)(param_3 + 0x32),*puVar2,(uint)*(byte *)(puVar2 + 1),puVar2[2]);
          }
        }
        if (snapshot_store_debug_switch != 0) {
          printf("[SNAPSHOT_STORE_DEBUG]%s()/%d buf %s\n","write_snapshot",0x1ae,__s);
        }
        iVar3 = FUN_00407fe0(param_3 + 0x48);
        if (iVar3 == 0) {
          sVar4 = strlen(__s);
          __s_02 = __s + sVar4;
          sVar4 = 0x200 - sVar4;
          __format = ",,\n";
        }
        else {
          FUN_00594650(__s,__s_00,param_3 + 0x48);
          iVar3 = FUN_00407fe0(param_3 + 0x3c);
          if (iVar3 == 0) {
            sVar4 = strlen(__s);
            snprintf(__s + sVar4,0x200 - sVar4,",");
            cVar6 = *__s_00;
          }
          else {
            FUN_00594650(__s,__s_00,param_3 + 0x3c);
            cVar6 = *__s_00;
          }
          if (cVar6 == '\0') {
            sVar4 = strlen(__s);
            __s_02 = __s + sVar4;
            sVar4 = 0x200 - sVar4;
            __format = "\n";
          }
          else {
            sVar4 = strlen(__s);
            snprintf(__s + sVar4,0x200 - sVar4,"\"%s",__s_00);
            sVar4 = strlen(__s);
            __s_02 = __s + (sVar4 - 1);
            sVar4 = 0x201 - sVar4;
            __format = "\"\n";
          }
        }
        snprintf(__s_02,sVar4,__format);
        if (snapshot_store_debug_switch != 0) {
          printf("[SNAPSHOT_STORE_DEBUG]%s()/%d buf %s\n","write_msg_ele_str",0x9e,__s);
        }
        sVar4 = strlen(__s);
        uVar10 = 0;
        fwrite(__s,sVar4,1,param_2);
      }
      FUN_00407df0(__s);
      goto LAB_00594f08;
    }
  }
  uVar10 = 0xffffffff;
LAB_00594f08:
  if (__s_00 != (char *)0x0) {
    FUN_00407df0(__s_00);
  }
  if (__s_01 != (char *)0x0) {
    FUN_00407df0(__s_01);
  }
  return uVar10;
}

