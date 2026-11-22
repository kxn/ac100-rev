// func uac_com_get_dev_vendor @ 00516f34 size=504

uint uac_com_get_dev_vendor(void)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  char acStack_58 [32];
  undefined4 local_38;
  char *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined2 local_20;
  undefined2 local_1e;
  char *local_1c;
  undefined4 local_18;
  
  memset(acStack_58,0,0x20);
  puVar1 = PTR_DAT_007591ac;
  uVar2 = *(uint *)(PTR_DAT_007591ac + 0x1f78);
  if (2 < uVar2) {
    if (uac_comm_dbg_switch != 0) {
      printf("[UAC_COMM_DBG]%s()/line %d : Start to init value first time.\n",
             "uac_com_get_dev_vendor",0xa6);
    }
    local_34 = "vendor_id";
    local_38 = 0;
    local_30 = 1;
    local_2c = 1;
    local_28 = 0;
    local_24 = 0;
    local_20 = 1;
    local_1e = 0x20;
    local_18 = 0;
    local_1c = acStack_58;
    iVar3 = uac_com_uci_parse_req("device_info","info",&local_38,1);
    if (iVar3 == 0) {
      iVar3 = strncmp(acStack_58,"0x00010001",10);
      if (iVar3 == 0) {
        *(undefined4 *)(puVar1 + 0x1f78) = 1;
        uVar2 = *(uint *)(puVar1 + 0x1f78);
      }
      else {
        iVar3 = strncmp(acStack_58,"0x00020001",10);
        if (iVar3 == 0) {
          *(undefined4 *)(puVar1 + 0x1f78) = 2;
        }
        else {
          iVar3 = strncmp(acStack_58,"0x00000001",10);
          if (iVar3 == 0) {
            *(undefined4 *)(puVar1 + 0x1f78) = 0;
            return *(uint *)(puVar1 + 0x1f78);
          }
          if (uac_comm_err_switch != 0) {
            printf("[UAC_COMM_ERR]%s()/line %d : invalid vendor_name:%s\n\n",
                   "uac_com_get_dev_vendor",0xc1,acStack_58);
          }
          *(undefined4 *)(puVar1 + 0x1f78) = 3;
        }
        uVar2 = *(uint *)(puVar1 + 0x1f78);
      }
    }
    else if (uac_comm_err_switch == 0) {
      uVar2 = *(uint *)(puVar1 + 0x1f78);
    }
    else {
      printf("[UAC_COMM_ERR]%s()/line %d : uci req parse failed.\n","uac_com_get_dev_vendor",0xaf);
      uVar2 = *(uint *)(puVar1 + 0x1f78);
    }
  }
  return uVar2;
}

