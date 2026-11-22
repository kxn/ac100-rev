// func rate_db_init @ 0055cdd0 size=1812

undefined4 rate_db_init(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_2b0;
  char *local_2ac;
  undefined4 local_2a8;
  undefined4 local_2a4;
  undefined4 local_2a0;
  undefined4 local_29c;
  undefined2 local_298;
  undefined2 local_296;
  int local_294;
  undefined4 local_290;
  undefined4 local_28c;
  char *local_288;
  undefined4 local_284;
  undefined4 local_280;
  undefined4 local_27c;
  undefined4 local_278;
  undefined2 local_274;
  undefined2 local_272;
  int local_270;
  undefined4 local_26c;
  undefined4 local_268;
  char *local_264;
  undefined4 local_260;
  undefined4 local_25c;
  undefined4 local_258;
  undefined4 local_254;
  undefined2 local_250;
  undefined2 local_24e;
  int local_24c;
  undefined4 local_248;
  undefined4 local_244;
  char *local_240;
  undefined4 local_23c;
  undefined4 local_238;
  undefined4 local_234;
  undefined4 local_230;
  undefined2 local_22c;
  undefined2 local_22a;
  int local_228;
  undefined4 local_224;
  undefined4 local_220;
  char *local_21c;
  undefined4 local_218;
  undefined4 local_214;
  undefined4 local_210;
  undefined4 local_20c;
  undefined2 local_208;
  undefined2 local_206;
  int local_204;
  undefined4 local_200;
  undefined4 local_1fc;
  char *local_1f8;
  undefined4 local_1f4;
  undefined4 local_1f0;
  undefined4 local_1ec;
  undefined4 local_1e8;
  undefined2 local_1e4;
  undefined2 local_1e2;
  int local_1e0;
  undefined4 local_1dc;
  undefined4 local_1d8;
  char *local_1d4;
  undefined4 local_1d0;
  undefined4 local_1cc;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined2 local_1c0;
  undefined2 local_1be;
  int local_1bc;
  undefined4 local_1b8;
  undefined4 local_1b4;
  char *local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  undefined2 local_19c;
  undefined2 local_19a;
  int local_198;
  undefined4 local_194;
  undefined4 local_190;
  char *local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined2 local_178;
  undefined2 local_176;
  int local_174;
  undefined4 local_170;
  undefined4 local_16c;
  char *local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_158;
  undefined2 local_154;
  undefined2 local_152;
  int local_150;
  undefined4 local_14c;
  undefined4 local_148;
  char *local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined2 local_130;
  undefined2 local_12e;
  int local_12c;
  undefined4 local_128;
  undefined4 local_124;
  char *local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined2 local_10c;
  undefined2 local_10a;
  int local_108;
  undefined4 local_104;
  undefined4 local_100;
  char *local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined2 local_e8;
  undefined2 local_e6;
  int local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  char *local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined2 local_c4;
  undefined2 local_c2;
  int local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  char *local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined2 local_a0;
  undefined2 local_9e;
  int local_9c;
  undefined4 local_98;
  undefined4 local_94;
  char *local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined2 local_7c;
  undefined2 local_7a;
  int local_78;
  undefined4 local_74;
  undefined4 local_70;
  char *local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined2 local_58;
  undefined2 local_56;
  int local_54;
  undefined4 local_50;
  undefined4 local_4c;
  char *local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined2 local_34;
  undefined2 local_32;
  int local_30;
  undefined4 local_2c;
  
  rate_db_mutex = FUN_00407f00("rate_rdt_mutex",1);
  if (rate_db_mutex == 0) {
    if (rate_err_switch == 0) {
      return 0xffffffff;
    }
    printf("[RATE_ERR]%s()/%d Create database mutex failed.\n","rate_db_init",0x89);
    return 0xffffffff;
  }
  rate_cfg = rrc_create();
  if (rate_cfg == 0) {
    if (rate_err_switch != 0) {
      printf("[RATE_ERR]%s()/%d create rate_cfg failed.\n","rate_db_init",0x90);
    }
    goto LAB_0055d38c;
  }
  rate_cfg_md5 = rrc_md5_create();
  if (rate_cfg_md5 == 0) {
    if (rate_err_switch != 0) {
      printf("[RATE_ERR]%s()/%d create rate_cfg failed.\n","rate_db_init",0x98);
    }
    FUN_00408360(rate_db_mutex);
    rrc_destroy(rate_cfg);
    rate_db_mutex = 0;
    return 0xffffffff;
  }
  local_94 = 0;
  local_84 = 0;
  local_74 = 0;
  local_64 = 0;
  local_90 = "11a_base";
  local_88 = 1;
  local_80 = 10;
  local_78 = rate_cfg + 4;
  local_7a = 4;
  local_8c = 3;
  local_7c = 0x10;
  local_70 = 1;
  local_68 = 3;
  local_6c = "11a_supp";
  local_54 = rate_cfg + 0x44;
  local_60 = 0;
  local_30 = rate_cfg + 0x84;
  local_5c = 10;
  local_58 = 0x10;
  local_56 = 4;
  local_50 = 0;
  local_4c = 2;
  local_48 = "11a_mult";
  local_44 = 0;
  local_40 = 1;
  local_3c = 0;
  local_38 = 10;
  local_34 = 1;
  local_32 = 4;
  local_2c = 0;
  iVar1 = FUN_00408120("apmng_rate","rate_11a",&local_94,3);
  if (iVar1 == 0) {
    local_100 = 0;
    local_f8 = 3;
    local_f4 = 1;
    local_f0 = 0;
    local_fc = "11b_base";
    local_ec = 10;
    local_e8 = 0x10;
    local_e4 = rate_cfg + 0x88;
    local_e6 = 4;
    local_e0 = 0;
    local_dc = 1;
    local_d4 = 3;
    local_d0 = 0;
    local_d8 = "11b_supp";
    local_c0 = rate_cfg + 200;
    local_9c = rate_cfg + 0x108;
    local_cc = 0;
    local_c8 = 10;
    local_c4 = 0x10;
    local_c2 = 4;
    local_bc = 0;
    local_b8 = 2;
    local_b4 = "11b_mult";
    local_b0 = 0;
    local_ac = 1;
    local_a8 = 0;
    local_a4 = 10;
    local_a0 = 1;
    local_9e = 4;
    local_98 = 0;
    iVar1 = FUN_00408120("apmng_rate","rate_11b",&local_100,3);
    if (iVar1 == 0) {
      local_16c = 0;
      local_164 = 3;
      local_160 = 1;
      local_15c = 0;
      local_168 = "11g_base";
      local_158 = 10;
      local_154 = 0x10;
      local_150 = rate_cfg + 0x10c;
      local_152 = 4;
      local_14c = 0;
      local_148 = 1;
      local_140 = 3;
      local_13c = 0;
      local_144 = "11g_supp";
      local_12c = rate_cfg + 0x14c;
      local_108 = rate_cfg + 0x18c;
      local_138 = 0;
      local_134 = 10;
      local_130 = 0x10;
      local_12e = 4;
      local_128 = 0;
      local_124 = 2;
      local_120 = "11g_mult";
      local_11c = 0;
      local_118 = 1;
      local_114 = 0;
      local_110 = 10;
      local_10c = 1;
      local_10a = 4;
      local_104 = 0;
      iVar1 = FUN_00408120("apmng_rate","rate_11g",&local_16c,3);
      if (iVar1 == 0) {
        local_1d8 = 0;
        local_1d0 = 0;
        local_1cc = 1;
        local_1c8 = 0;
        local_1d4 = "11n_base";
        local_1c4 = 10;
        local_1c0 = 1;
        local_1bc = rate_cfg + 400;
        local_1be = 4;
        local_1b8 = 0;
        local_1b4 = 1;
        local_1ac = 0;
        local_1a8 = 1;
        local_1b0 = "11n_supp";
        local_198 = rate_cfg + 0x194;
        local_174 = rate_cfg + 0x198;
        local_1a4 = 0;
        local_1a0 = 10;
        local_19c = 1;
        local_19a = 4;
        local_194 = 0;
        local_190 = 2;
        local_18c = "11n_mult";
        local_188 = 0;
        local_184 = 0;
        local_180 = 0;
        local_17c = 10;
        local_178 = 1;
        local_176 = 4;
        local_170 = 0;
        iVar1 = FUN_00408120("apmng_rate","rate_11n",&local_1d8,3);
        if (iVar1 == 0) {
          local_244 = 0;
          local_23c = 0;
          local_238 = 1;
          local_234 = 0;
          local_240 = "11ac_base";
          local_230 = 10;
          local_22c = 1;
          local_228 = rate_cfg + 0x19c;
          local_22a = 4;
          local_224 = 0;
          local_220 = 1;
          local_218 = 0;
          local_214 = 1;
          local_21c = "11ac_supp";
          local_204 = rate_cfg + 0x1a0;
          local_1e0 = rate_cfg + 0x1a4;
          local_210 = 0;
          local_20c = 10;
          local_208 = 1;
          local_206 = 4;
          local_200 = 0;
          local_1fc = 2;
          local_1f8 = "11ac_mult";
          local_1f4 = 0;
          local_1f0 = 0;
          local_1ec = 0;
          local_1e8 = 10;
          local_1e4 = 1;
          local_1e2 = 4;
          local_1dc = 0;
          iVar1 = FUN_00408120("apmng_rate","rate_11ac",&local_244,3);
          if (iVar1 == 0) {
            local_2b0 = 0;
            local_2a8 = 0;
            local_2a4 = 1;
            local_2a0 = 0;
            local_2ac = "11ax_base";
            local_29c = 10;
            local_298 = 1;
            local_294 = rate_cfg + 0x1a8;
            local_296 = 4;
            local_290 = 0;
            local_28c = 1;
            local_284 = 0;
            local_280 = 1;
            local_288 = "11ax_supp";
            local_270 = rate_cfg + 0x1ac;
            local_24c = rate_cfg + 0x1b0;
            local_27c = 0;
            local_278 = 10;
            local_274 = 1;
            local_272 = 4;
            local_26c = 0;
            local_268 = 2;
            local_264 = "11ax_mult";
            local_260 = 0;
            local_25c = 0;
            local_258 = 0;
            local_254 = 10;
            local_250 = 1;
            local_24e = 4;
            local_248 = 0;
            iVar1 = FUN_00408120("apmng_rate","rate_11ax",&local_2b0,3);
            if (iVar1 == 0) {
              transfer_rate_db_to_rate_md5(rate_cfg,rate_cfg_md5);
              return 0;
            }
            if (rate_err_switch != 0) {
              uVar2 = 0xf0;
LAB_0055d404:
              printf("[RATE_ERR]%s()/%d uci req parse failed.\n","rate_db_init",uVar2);
            }
          }
          else if (rate_err_switch != 0) {
            uVar2 = 0xe2;
            goto LAB_0055d404;
          }
        }
        else if (rate_err_switch != 0) {
          uVar2 = 0xd4;
          goto LAB_0055d404;
        }
      }
      else if (rate_err_switch != 0) {
        uVar2 = 0xc6;
        goto LAB_0055d404;
      }
    }
    else if (rate_err_switch != 0) {
      uVar2 = 0xb8;
      goto LAB_0055d404;
    }
  }
  else if (rate_err_switch != 0) {
    uVar2 = 0xaa;
    goto LAB_0055d404;
  }
  rrc_destroy(rate_cfg);
  rate_cfg = 0;
  rrc_md5_destroy(rate_cfg_md5);
  rate_cfg_md5 = 0;
LAB_0055d38c:
  FUN_00408360(rate_db_mutex);
  rate_db_mutex = 0;
  return 0xffffffff;
}

