; func wips_uninit @ 0x004caaf0 size=0x88
  4caaf0:	27bdffe0 	addiu	sp,sp,-32
  4caaf4:	afb00018 	sw	s0,24(sp)
  4caaf8:	3c100077 	lui	s0,0x77
  4caafc:	afbf001c 	sw	ra,28(sp)
  4cab00:	8e04809c 	lw	a0,-32612(s0)
  4cab04:	50800005 	beqzl	a0,0x4cab1c
  4cab08:	3c100077 	lui	s0,0x77
  4cab0c:	0c102058 	jal	0x408160
  4cab10:	00000000 	nop
  4cab14:	ae00809c 	sw	zero,-32612(s0)
  4cab18:	3c100077 	lui	s0,0x77
  4cab1c:	8e048094 	lw	a0,-32620(s0)
  4cab20:	50800005 	beqzl	a0,0x4cab38
  4cab24:	3c100077 	lui	s0,0x77
  4cab28:	0c102058 	jal	0x408160
  4cab2c:	00000000 	nop
  4cab30:	ae008094 	sw	zero,-32620(s0)
  4cab34:	3c100077 	lui	s0,0x77
  4cab38:	8e048070 	lw	a0,-32656(s0)
  4cab3c:	10800005 	beqz	a0,0x4cab54
  4cab40:	3c020077 	lui	v0,0x77
  4cab44:	0c1020c4 	jal	0x408310
  4cab48:	00000000 	nop
  4cab4c:	ae008070 	sw	zero,-32656(s0)
  4cab50:	3c020077 	lui	v0,0x77
  4cab54:	8c448074 	lw	a0,-32652(v0)
  4cab58:	10800004 	beqz	a0,0x4cab6c
  4cab5c:	8fbf001c 	lw	ra,28(sp)
  4cab60:	8fb00018 	lw	s0,24(sp)
  4cab64:	081020d8 	j	0x408360
  4cab68:	27bd0020 	addiu	sp,sp,32
  4cab6c:	8fb00018 	lw	s0,24(sp)
  4cab70:	03e00008 	jr	ra
  4cab74:	27bd0020 	addiu	sp,sp,32
