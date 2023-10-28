#include "Renderer.h"

void Renderer::Render()
{
	//render every pixel
}

void Renderer::OnResize(uint32_t width, uint32_t height)
{
	if (!m_Image) {
		m_Image->Resize(width, height);

	}
	else{
		m_Image = std::make_shared<Walnut::Image>(width, height, Walnut::ImageFormat::RGBA);
	} 

	if (!m_Image || width != m_Image->GetWidth() || height != m_Image->GetHeight()) {
		m_Image = std::make_shared<Walnut::Image>(width, height, Walnut::ImageFormat::RGBA);
		delete[] m_ImageData;
		m_ImageData = new uint32_t[m_ViewportWidth * m_ViewportHeight];
	}
}
