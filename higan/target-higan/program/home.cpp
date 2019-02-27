Home::Home(View* parent) : Panel(parent, Size{~0, ~0}) {
  setCollapsible().setVisible(false);
  image icon{Resource::Icon};
  icon.shrink();
  for(uint y : range(icon.height())) {
    auto data = icon.data() + y * icon.pitch();
    for(uint x : range(icon.width())) {
      uint8_t alpha = icon.read(data) >> 24;
      icon.write(data, uint8_t(alpha * 0.15) << 24);
      data += icon.stride();
    }
  }
  iconCanvas.setIcon(icon);
  spacerButton.setVisible(false);
}

auto Home::show() -> void {
  setVisible(true);
}

auto Home::hide() -> void {
  setVisible(false);
}