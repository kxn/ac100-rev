// func rdmngr_working_channel_set_update @ 00613428 size=356

undefined4 rdmngr_working_channel_set_update(short param_1,short param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  uVar3 = (uint)param_1;
  uVar4 = (uint)param_2;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  FUN_004082d0(l_working_channel_mutex,0xffffffff);
  if ((uVar3 - 1 & 0xffff) < 0xbf) {
    iVar2 = *(int *)(&rdmngr_working_channel_set_count + uVar3 * 4);
    if (iVar2 != 0) {
      *(int *)(&rdmngr_working_channel_set_count + uVar3 * 4) = iVar2 + -1;
    }
    if (*(int *)(&rdmngr_working_channel_set_count + uVar3 * 4) == 0) {
      *(uint *)(&rdmngr_working_channel_set + ((int)uVar3 >> 5) * 4) =
           ~(1 << (uVar3 & 0x1f)) & *(uint *)(&rdmngr_working_channel_set + ((int)uVar3 >> 5) * 4);
    }
  }
  if ((uVar4 - 1 & 0xffff) < 0xbf) {
    iVar2 = *(int *)(&rdmngr_working_channel_set_count + uVar4 * 4);
    iVar1 = iVar2 + 1;
    *(int *)(&rdmngr_working_channel_set_count + uVar4 * 4) = iVar1;
    if (iVar2 == 0) {
      *(uint *)(&rdmngr_working_channel_set + ((int)uVar4 >> 5) * 4) =
           iVar1 << (uVar4 & 0x1f) | *(uint *)(&rdmngr_working_channel_set + ((int)uVar4 >> 5) * 4);
    }
  }
  iVar2 = memcmp(&rdmngr_working_channel_set,&local_28,0x18);
  if (iVar2 == 0) {
    rdmngr_working_channel_set_last = 0;
    DAT_007cc5e4 = 0;
    DAT_007cc5e8 = 0;
    DAT_007cc5ec = 0;
    DAT_007cc5f0 = 0;
    DAT_007cc5f4 = 0;
  }
  FUN_00407f30(l_working_channel_mutex);
  return 0;
}

