#include <iostream>

#include <SFML/Graphics.hpp>

#include <barnack/layout/wrappers/fillers.h>
#include <barnack/layout/wrappers/padding.h>
#include <barnack/layout/containers/stack.h>
#include <barnack/layout/containers/vertical.h>
#include <barnack/layout/containers/horizontal.h>

#include <nlohmann/json.hpp>

struct ct { float r, g, b; };
sf::Color ct_to_sf_color(const ct& c, float alpha) noexcept
	{
	return sf::Color
		{
		static_cast<uint8_t>(c.r * 255.f),
		static_cast<uint8_t>(c.g * 255.f),
		static_cast<uint8_t>(c.b * 255.f),
		static_cast<uint8_t>(alpha * 255.f)
		};
	};








int main()
	{
	barnack::layout::containers::horizontal h;
	if (auto& v{h.emplace<barnack::layout::containers::vertical>()})
		{
		if (auto& e{v.emplace<barnack::layout::core::element>()})
			{
			e.sizes.proxy_min() = utils::math::vec2f{ 32.f,  32.f};
			e.sizes.proxy_max() = utils::math::vec2f{320.f, 320.f};
			e.sizes.proxy_prf_x() = 100.f;
			e.sizes.proxy_prf_y() = 200.f;
			}
		
		if (auto& e{v.emplace<barnack::layout::core::element>()})
			{
			e.sizes.proxy_min() = utils::math::vec2f{ 32.f,  32.f};
			e.sizes.proxy_max() = utils::math::vec2f{320.f, 320.f};
			e.sizes.proxy_prf_x() = 100.f;
			e.sizes.proxy_prf_y() = 100.f;
			}
		}
	if (auto& e{h.emplace<barnack::layout::core::element>()})
		{
		e.sizes.proxy_min() = utils::math::vec2f{32.f,  32.f};
		e.sizes.proxy_prf() = utils::math::vec2f{32.f,  32.f};
		e.sizes.proxy_max() = utils::math::vec2f{64.f,  64.f};
		}
	if (auto& e{h.emplace<barnack::layout::core::element>()})
		{
		e.sizes.proxy_min() = utils::math::vec2f{32.f,  32.f};
		e.sizes.proxy_prf() = utils::math::vec2f{48.f,  48.f};
		e.sizes.proxy_max() = utils::math::vec2f{64.f,  64.f};
		}
	if (auto& e{h.emplace<barnack::layout::core::element>()})
		{
		e.sizes.proxy_min() = utils::math::vec2f{32.f,  32.f};
		e.sizes.proxy_prf() = utils::math::vec2f{64.f,  64.f};
		e.sizes.proxy_max() = utils::math::vec2f{64.f,  64.f};
		}
	if (auto& e{h.emplace<barnack::layout::core::element>()})
		{
		e.sizes.proxy_min() = utils::math::vec2f{0.f, 0.f};
		e.sizes.proxy_prf() = utils::math::vec2f{0.f, 0.f};
		e.sizes.proxy_max() = utils::math::vec2f{utils::math::constants::finf, utils::math::constants::finf};
		}
	if (auto& v{h.emplace<barnack::layout::containers::vertical>()})
		{
		v.sizes.proxy_min_x() = 500.f;
		//v.sizes.proxy_max_x() = 500.f;

		if (auto& e{v.emplace<barnack::layout::core::element>()})
			{
			e.sizes.proxy_min() = utils::math::vec2f{ 32.f,  32.f};
			e.sizes.proxy_max() = utils::math::vec2f{320.f, 320.f};
			e.sizes.proxy_prf_x() = 200.f;
			e.sizes.proxy_prf_y() = 100.f;
			}

		if (auto& p{v.emplace<barnack::layout::wrappers::filler_horizontal>()})
			{
			p.alignment = utils::alignment::horizontal::left;

			if (auto& e{p.emplace<barnack::layout::core::element>()})
				{
				e.sizes.proxy_min() = utils::math::vec2f{ 32.f,  32.f};
				e.sizes.proxy_max() = utils::math::vec2f{320.f, 320.f};
				e.sizes.proxy_prf_x() = 150.f;
				e.sizes.proxy_prf_y() = 200.f;
				}
			}
		if (auto& p{v.emplace<barnack::layout::wrappers::filler_horizontal>()})
			{
			p.alignment = utils::alignment::horizontal::centre;

			if (auto& e{p.emplace<barnack::layout::core::element>()})
				{
				e.sizes.proxy_min() = utils::math::vec2f{ 32.f,  32.f};
				e.sizes.proxy_max() = utils::math::vec2f{320.f, 320.f};
				e.sizes.proxy_prf_x() = 150.f;
				e.sizes.proxy_prf_y() = 200.f;
				}
			}
		if (auto& p{v.emplace<barnack::layout::wrappers::filler_horizontal>()})
			{
			p.alignment = utils::alignment::horizontal::right;

			if (auto& e{p.emplace<barnack::layout::core::element>()})
				{
				e.sizes.proxy_min() = utils::math::vec2f{ 32.f,  32.f};
				e.sizes.proxy_max() = utils::math::vec2f{320.f, 320.f};
				e.sizes.proxy_prf_x() = 150.f;
				e.sizes.proxy_prf_y() = 200.f;
				}
			}

		if (auto& e{v.emplace<barnack::layout::core::element>()})
			{
			e.sizes.proxy_min() = utils::math::vec2f{ 32.f,  32.f};
			e.sizes.proxy_max() = utils::math::vec2f{320.f, 320.f};
			e.sizes.proxy_prf_x() = 150.f;
			e.sizes.proxy_prf_y() = 200.f;
			}

		if (auto& p{v.emplace<barnack::layout::containers::stack>()})
			{
			p.alignment = utils::alignment::create::centre();

			if (auto& e{p.emplace<barnack::layout::core::element>()})
				{
				e.sizes.proxy_min() = utils::math::vec2f{ 32.f,  32.f};
				e.sizes.proxy_max() = utils::math::vec2f{320.f, 320.f};
				e.sizes.proxy_prf_x() = 150.f;
				e.sizes.proxy_prf_y() = 300.f;
				}
			if (auto& e{p.emplace<barnack::layout::core::element>()})
				{
				e.sizes.proxy_min() = utils::math::vec2f{ 32.f,  32.f};
				e.sizes.proxy_max() = utils::math::vec2f{100.f, 100.f};
				}
			}
		}


	sf::RenderWindow rw{sf::VideoMode{{800u, 600u}}, "asd"};


	auto debug_draw{[&rw](const barnack::layout::core::element& element)
		{
		const ct color{[&element]() -> ct
			{
			if (dynamic_cast<const barnack::layout::core::container*>(&element)) { return {0.f, .5f, .8f}; }
			if (dynamic_cast<const barnack::layout::core::wrapper  *>(&element)) { return {.3f, .5f, 0.f}; }
			if (dynamic_cast<const barnack::layout::core::element  *>(&element)) { return {0.f, 1.f, 0.f}; }
			return {1.f, 0.f, 0.f};
			}()};
		sf::RectangleShape rs;
		rs.setPosition({element.rect.x(), element.rect.y()});
		rs.setSize(sf::Vector2f{element.rect.width(), element.rect.height()});

		rs.setOutlineThickness(1.f);
		rs.setOutlineColor(ct_to_sf_color(color, .8f));
		rs.setFillColor   (ct_to_sf_color(color, .2f));

		rw.draw(rs);
		}};

	rw.display();

	rw.setMinimumSize(sf::Vector2u
		{
		static_cast<unsigned int>(std::floor(h.get_size_min().x())), 
		static_cast<unsigned int>(std::floor(h.get_size_min().y()))
		});

	std::string traversal_string;
	
	sf::Font default_font{std::filesystem::path{"Arial.ttf"}};

	while (rw.isOpen())
		{
		if (const auto event_opt{rw.waitEvent()})
			{
			const auto& event{*event_opt};

			if (event.is<sf::Event::Closed>())
				{
				rw.close();
				}
			else if (const auto* obs{event.getIf<sf::Event::Resized>()})
				{
				const auto& resized{*obs};
				const utils::math::vec2f new_size{static_cast<float>(resized.size.x), static_cast<float>(resized.size.y)};
				h.resize(new_size);
				h.reposition({0.f, 0.f});

				sf::FloatRect visibleArea({0.f, 0.f}, {static_cast<float>(resized.size.x), static_cast<float>(resized.size.y)});
				rw.setView(sf::View(visibleArea));
				}
			else if (const auto* obs{event.getIf<sf::Event::MouseMoved>()})
				{
				const auto& mouse_moved{*obs};
				const utils::math::vec2f new_position{static_cast<float>(mouse_moved.position.x), static_cast<float>(mouse_moved.position.y)};
				
				traversal_string = "";
				h.traverse(new_position, [&traversal_string] (const auto& element)
					{
					const std::string node_name{typeid(element).name()};
					const std::string node_properties
						{
						'(' +
						"position: ("     + std::to_string(element.rect.ll()) + ", " + std::to_string(element.rect.up()) + "), " +
						"bottom_right: (" + std::to_string(element.rect.rr()) + ", " + std::to_string(element.rect.dw()) + "), " +
						"size: ("         + std::to_string(element.rect.w ()) + ", " + std::to_string(element.rect.h ()) + ")" + 
						')'
						};
					traversal_string += node_name + ' ' + node_properties + '\n';
					});
				}
			}

		rw.clear();
		h.traverse(debug_draw);

		if (!traversal_string.empty())
			{
			sf::Text text{default_font, traversal_string, 16U};
			rw.draw(text);
			}
		rw.display();
		}
	}