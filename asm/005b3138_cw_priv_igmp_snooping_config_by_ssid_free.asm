; func cw_priv_igmp_snooping_config_by_ssid_free @ 0x005b3138 size=0x54
  5b3138:	27bdffd8 	addiu	sp,sp,-40
  5b313c:	afb10020 	sw	s1,32(sp)
  5b3140:	afbf0024 	sw	ra,36(sp)
  5b3144:	afb0001c 	sw	s0,28(sp)
  5b3148:	8c900010 	lw	s0,16(a0)
  5b314c:	12000009 	beqz	s0,0x5b3174
  5b3150:	00808821 	move	s1,a0
  5b3154:	8e040004 	lw	a0,4(s0)
  5b3158:	10800003 	beqz	a0,0x5b3168
  5b315c:	00000000 	nop
  5b3160:	0c101f7c 	jal	0x407df0
  5b3164:	00000000 	nop
  5b3168:	0c101f7c 	jal	0x407df0
  5b316c:	02002021 	move	a0,s0
  5b3170:	ae200010 	sw	zero,16(s1)
  5b3174:	8fbf0024 	lw	ra,36(sp)
  5b3178:	00001021 	move	v0,zero
  5b317c:	8fb10020 	lw	s1,32(sp)
  5b3180:	8fb0001c 	lw	s0,28(sp)
  5b3184:	03e00008 	jr	ra
  5b3188:	27bd0028 	addiu	sp,sp,40
