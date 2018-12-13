#include "Glower.h"
#include "Interfaces.h"


#define OPTION(type, var, val) type var = val

OPTION(Color, color_glow_ally, Color(0, 128, 255));
OPTION(Color, color_glow_enemy, Color(255, 0, 0));
OPTION(Color, color_glow_chickens, Color(0, 128, 0));
OPTION(Color, color_glow_c4_carrier, Color(255, 255, 0));
OPTION(Color, color_glow_planted_c4, Color(128, 0, 128));
OPTION(Color, color_glow_defuse, Color(255, 255, 255));
OPTION(Color, color_glow_weapons, Color(255, 128, 0));
OPTION(Color, color_glow_default, color_glow_weapons);

void Glower::glow()
{
	for (auto i = 0; i < Interfaces::g_glowObjManager->m_GlowObjectDefinitions.Count(); i++) {
		auto& glowObject = Interfaces::g_glowObjManager->m_GlowObjectDefinitions[i];
		auto entity = reinterpret_cast<C_BasePlayer*>(glowObject.m_pEntity);

		if (glowObject.IsUnused())
			continue;

		if (!entity || entity->IsDormant())
			continue;

		auto class_id = entity->GetClientClass()->m_ClassID;
		auto color = color_glow_default;

		switch (class_id) {
		case ClassId_CCSPlayer:
			{
				auto is_enemy = entity->m_iTeamNum() != g_player->m_iTeamNum();

				if (entity->HasC4() && is_enemy) {
					color = color_glow_c4_carrier;
					break;
				}

				color = is_enemy ? color_glow_enemy : color_glow_ally;

				break;
			}
		case ClassId_CChicken:
			entity->m_bShouldGlow() = true;
			color = color_glow_chickens;
			break;
		case ClassId_CPlantedC4:
			color = color_glow_planted_c4;
			break;
		default:
			{
				if (entity->IsWeapon()) {
					color = color_glow_weapons;
				}
			}
		}

		glowObject.m_flRed = color.r() / 255.0f;
		glowObject.m_flGreen = color.g() / 255.0f;
		glowObject.m_flBlue = color.b() / 255.0f;
		glowObject.m_flAlpha = color.a() / 255.0f;
		glowObject.m_bRenderWhenOccluded = true;
		glowObject.m_bRenderWhenUnoccluded = false;
	}
}
