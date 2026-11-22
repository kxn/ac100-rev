// func uac_memory_status_get @ 0051dbbc size=1

void uac_memory_status_get(void)

{
  int in_t9;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  (**(code **)(in_t9 + 0x23bca8))(&uStack_30);
  (**(code **)(in_t9 + 0x23bd14))(*(int *)(in_t9 + 0x23b56c) + 0x31e8,uStack_30);
  (**(code **)(in_t9 + 0x23bd14))(*(int *)(in_t9 + 0x23b56c) + 0x31f4,uStack_2c);
  (**(code **)(in_t9 + 0x23bd14))(*(int *)(in_t9 + 0x23b56c) + 0x3204,uStack_28);
  (**(code **)(in_t9 + 0x23bd14))(*(int *)(in_t9 + 0x23b56c) + 0x3214,uStack_24);
  (**(code **)(in_t9 + 0x23bd14))(*(int *)(in_t9 + 0x23b56c) + 0x3220,uStack_20);
  (**(code **)(in_t9 + 0x23bd14))(*(int *)(in_t9 + 0x23b56c) + 0x3230,uStack_1c);
  (**(code **)(in_t9 + 0x23bd14))(*(int *)(in_t9 + 0x23b56c) + 0x3240,uStack_18);
  (**(code **)(in_t9 + 0x23bd14))(*(int *)(in_t9 + 0x23b56c) + 0x3250,uStack_14);
  (**(code **)(in_t9 + 0x23bd14))(*(int *)(in_t9 + 0x23b56c) + 0x3260,uStack_10);
                    /* WARNING: Could not recover jumptable at 0x0051dcd0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(in_t9 + 0x23bd14))(*(int *)(in_t9 + 0x23b56c) + 0x3270,uStack_c);
  return;
}

