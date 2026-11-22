// func cloud_mngt_key_cert_path_init @ 0048e69c size=360

undefined4 cloud_mngt_key_cert_path_init(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_158;
  char *local_154;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined2 local_140;
  undefined2 local_13e;
  char *local_13c;
  undefined4 local_138;
  undefined4 local_134;
  char *local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined2 local_11c;
  undefined2 local_11a;
  char *local_118;
  undefined4 local_114;
  char acStack_110 [128];
  char acStack_90 [128];
  
  memset(acStack_90,0,0x80);
  memset(acStack_110,0,0x80);
  local_158 = 0;
  local_14c = 0;
  local_148 = 0;
  local_154 = "ssl_crt";
  local_144 = 0;
  local_13e = 0x80;
  local_150 = 1;
  local_140 = 1;
  local_138 = 0;
  local_134 = 1;
  local_130 = "ssl_key";
  local_12c = 1;
  local_128 = 0;
  local_124 = 0;
  local_120 = 0;
  local_11c = 1;
  local_11a = 0x80;
  local_114 = 0;
  local_13c = acStack_90;
  local_118 = acStack_110;
  iVar1 = FUN_00408120("ngx_proxy",&DAT_00681f70,&local_158,2);
  if (iVar1 == 0) {
    memset(&g_cert_file_name,0,0x81);
    strncpy(&g_cert_file_name,acStack_90,0x80);
    memset(&g_key_file_name,0,0x81);
    strncpy(&g_key_file_name,acStack_110,0x80);
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
    if (cloud_mngt_err_switch != '\0') {
      printf("[CLOUD_MNGT_ERROR]%s()/%d uci req parse failed.\n","cloud_mngt_key_cert_path_init",
             0xfe4);
    }
  }
  return uVar2;
}

