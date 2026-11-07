#include <format>
#include <iostream>

#include <utils/matrix.h>
#include <utils/graphics/colour.h>

#include <SFML/Graphics.hpp>

#include <barnack/window/base.h>

#include <barnack/layout/all.h>
//#include <nlohmann/json.hpp>

struct ct { float r, g, b; };
sf::Color ct_to_sf_color(const ct& c, float alpha) noexcept
	{
	return sf::Color
		{
		static_cast<uint8_t>(c.r   * 255.f),
		static_cast<uint8_t>(c.g   * 255.f),
		static_cast<uint8_t>(c.b   * 255.f),
		static_cast<uint8_t>(alpha * 255.f)
		};
	};



std::string element_data_as_string(const barnack::layout::element& element)
	{
	//const std::string node_properties
	//	{
	//	"("
	//	"position: (" + std::to_string(element.rect_content.ll()) + ", " + std::to_string(element.rect_content.up()) + "), "
	//	"bottom_right: (" + std::to_string(element.rect_content.rr()) + ", " + std::to_string(element.rect_content.dw()) + "), "
	//	"size: (" + std::to_string(element.rect_content.w()) + ", " + std::to_string(element.rect_content.h()) + ")"
	//	")"
	//	};
	return std::format("{} - {}", static_cast<const void*>(std::addressof(element)), typeid(element).name()) /*+ ' ' + node_properties*/;
	}

int main()
	{
	barnack::layout::container::horizontal h;
	if (auto& v{h.add_slot().emplace<barnack::layout::container::vertical>()})
		{
		if (auto& e{v.add_slot().emplace<barnack::layout::spacer>()})
			{
			e.constraints.min() = utils::math::vec2f{ 32.f,  32.f};
			e.constraints.max() = utils::math::vec2f{320.f, 320.f};
			e.constraints.x.prf() = 100.f;
			e.constraints.y.prf() = 200.f;
			}
		
		if (auto& e{v.add_slot().emplace<barnack::layout::spacer>()})
			{
			e.constraints.min() = utils::math::vec2f{ 32.f,  32.f};
			e.constraints.max() = utils::math::vec2f{320.f, 320.f};
			e.constraints.x.prf() = 100.f;
			e.constraints.y.prf() = 100.f;
			}
		}
	if (auto& e{h.add_slot().emplace<barnack::layout::spacer>()})
		{
		e.constraints.min() = utils::math::vec2f{32.f,  32.f};
		e.constraints.prf() = utils::math::vec2f{32.f,  32.f};
		e.constraints.max() = utils::math::vec2f{64.f,  64.f};
		}
	if (auto& e{h.add_slot().emplace<barnack::layout::spacer>()})
		{
		e.constraints.min() = utils::math::vec2f{32.f,  32.f};
		e.constraints.prf() = utils::math::vec2f{48.f,  48.f};
		e.constraints.max() = utils::math::vec2f{64.f,  64.f};
		}
	if (auto& e{h.add_slot().emplace<barnack::layout::spacer>()})
		{
		e.constraints.min() = utils::math::vec2f{32.f,  32.f};
		e.constraints.prf() = utils::math::vec2f{64.f,  64.f};
		e.constraints.max() = utils::math::vec2f{64.f,  64.f};
		}
	if (auto& e{h.add_slot().emplace<barnack::layout::spacer>()})
		{
		e.constraints.min() = utils::math::vec2f{0.f, 0.f};
		e.constraints.prf() = utils::math::vec2f{0.f, 0.f};
		e.constraints.max() = utils::math::vec2f{utils::math::constants::finf, utils::math::constants::finf};
		}
	 
	if (auto& v{h.add_slot().emplace<barnack::layout::container::vertical>()})
		{
		v.constraints.x.min() = 500.f;
		//v.constraints.x.max() = 500.f;
	
		if (auto& e{v.add_slot().emplace<barnack::layout::spacer>()})
			{
			e.constraints.min() = utils::math::vec2f{ 32.f,  32.f};
			e.constraints.max() = utils::math::vec2f{320.f, 320.f};
			e.constraints.x.prf() = 200.f;
			e.constraints.y.prf() = 100.f;
			}
		
		if (auto& e{v.add_slot(utils::alignment::horizontal::left).emplace<barnack::layout::spacer>()})
			{
			e.constraints.min() = utils::math::vec2f{ 32.f,  32.f};
			e.constraints.max() = utils::math::vec2f{320.f, 320.f};
			e.constraints.x.prf() = 150.f;
			e.constraints.y.prf() = 200.f;
			}
		if (auto& e{v.add_slot(utils::alignment::horizontal::centre).emplace<barnack::layout::spacer>()})
			{
			e.constraints.min() = utils::math::vec2f{ 32.f,  32.f};
			e.constraints.max() = utils::math::vec2f{320.f, 320.f};
			e.constraints.x.prf() = 150.f;
			e.constraints.y.prf() = 200.f;
			}
		if (auto& e{v.add_slot(utils::alignment::horizontal::right).emplace<barnack::layout::spacer>()})
			{
			e.constraints.min() = utils::math::vec2f{ 32.f,  32.f};
			e.constraints.max() = utils::math::vec2f{320.f, 320.f};
			e.constraints.x.prf() = 150.f;
			e.constraints.y.prf() = 200.f;
			}
		
		if (auto& e{v.add_slot().emplace<barnack::layout::spacer>()})
			{
			e.constraints.min() = utils::math::vec2f{ 32.f,  32.f};
			e.constraints.max() = utils::math::vec2f{320.f, 320.f};
			e.constraints.x.prf() = 150.f;
			e.constraints.y.prf() = 200.f;
			}
		
		if (auto& p{v.add_slot().emplace<barnack::layout::container::stack>(utils::alignment::create::centre())})
			{
			if (auto& e{p.add_slot().emplace<barnack::layout::spacer>()})
				{
				e.constraints.min() = utils::math::vec2f{312.f,  32.f};
				e.constraints.max() = utils::math::vec2f{820.f, 320.f};
				e.constraints.x.prf() = 600.f;
				e.constraints.y.prf() = 300.f;
				}
			if (auto& e{p.add_slot().emplace<barnack::layout::spacer>()})
				{
				e.constraints.min() = utils::math::vec2f{ 32.f,  32.f};
				e.constraints.max() = utils::math::vec2f{100.f, 100.f};
				}
			}
		}












	barnack::window::initializer window_initializer;


	utils::matrix<utils::graphics::colour::rgba_u> icon_image
		(
		utils::math::vec2s{size_t{2}, size_t{2}},
		utils::graphics::colour::rgba_u{uint8_t{255}, uint8_t{  0}, uint8_t{  0}, uint8_t{255}},
		utils::graphics::colour::rgba_u{uint8_t{  0}, uint8_t{255}, uint8_t{  0}, uint8_t{255}},
		utils::graphics::colour::rgba_u{uint8_t{  0}, uint8_t{  0}, uint8_t{255}, uint8_t{255}},
		utils::graphics::colour::rgba_u{uint8_t{255}, uint8_t{255}, uint8_t{255}, uint8_t{255}}
		);
	barnack::window::icon window_icon{icon_image};

	//barnack::window::base bwindow{barnack::window::factory
	//	{
	//	.title{"My Window"},
	//	.minimum_size{{34, 64}},
	//
	//	.callbacks
	//		{
	//		.on_move_begin = [](barnack::window::base& window) { return barnack::window::simple_event_return_type::use_default_handler; },
	//		}
	//	}.create()};

	//window_icon.assign_to(bwindow);

	//bwindow.show();
	//while (bwindow.is_open())
	//	{
	//	//bwindow.wait_event();
	//	while (bwindow.poll_event());
	//	}

	//sf::RenderWindow rw{bwindow.get()};
	sf::RenderWindow rw{sf::VideoMode{{800u, 600u}}, "asd"};
	window_icon.assign_to({rw.getNativeHandle()});
	rw.setActive(true);



















	auto debug_draw{[&rw](const barnack::layout::element& element) -> bool
		{
		const ct color{[&element]() -> ct
			{
			if (dynamic_cast<const barnack::layout::owner  *>(&element)) { return {0.f, .5f, .8f}; }
			if (dynamic_cast<const barnack::layout::element*>(&element)) { return {0.f, 1.f, 0.f}; }
			return {1.f, 0.f, 0.f};
			}()};
		sf::RectangleShape rs;
		rs.setPosition({element.get_rect_content().x(), element.get_rect_content().y()});
		rs.setSize(sf::Vector2f{element.get_rect_content().width(), element.get_rect_content().height()});

		rs.setOutlineThickness(1.f);
		rs.setOutlineColor(ct_to_sf_color(color, .8f));
		rs.setFillColor   (ct_to_sf_color(color, .2f));

		rw.draw(rs);
		return true;
		}};

	rw.display();

	rw.setMinimumSize(sf::Vector2u
		{
		static_cast<unsigned int>(std::floor(h.get_size_min().x())), 
		static_cast<unsigned int>(std::floor(h.get_size_min().y()))
		});

	
	sf::Font default_font{std::filesystem::path{"Arial.ttf"}};

	barnack::layout::traversal traversal;
	bool traversal_changed{true};

	sf::Text sf_text{default_font, "", 16U};
	std::string traversal_string;

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

				traversal_changed = traversal.begin(h, new_position);
				if (traversal_changed)
					{
					traversal_string = "";

					traversal_string += "Unchanged:\n";
					traversal.previously_visited().visit_with_depth([&](const barnack::layout::element& element, size_t depth)
						{
						traversal_string += std::string(depth, ' ');
						traversal_string += element_data_as_string(element) + "\n";
						return true;
						});

					traversal_string += "Entered:\n";
					for (const auto& element : traversal.newly_visited())
						{
						element.visit_with_depth([&](const barnack::layout::element& element, size_t depth)
							{
							traversal_string += std::string(depth, ' ');
							traversal_string += element_data_as_string(element) + "\n";
							return true;
							});
						}
					traversal_string += "Left:\n";
					for (const auto& element : traversal.left())
						{
						element.visit_with_depth([&](const barnack::layout::element& element, size_t depth)
							{
							traversal_string += std::string(depth, ' ');
							traversal_string += element_data_as_string(element) + "\n";
							return true;
							});
						}

					sf_text.setString(traversal_string);
					std::cout << traversal_string << "\n\n==============================================================\n\n";
					}
				}
			}
	
		rw.clear();
		try
			{
			h.visit(debug_draw);
			}
		catch (const std::exception&)
			{

			}
	
		if (!traversal_string.empty())
			{
			rw.draw(sf_text);
			}
		rw.display();
		}
	}