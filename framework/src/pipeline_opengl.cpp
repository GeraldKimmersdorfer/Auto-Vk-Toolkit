namespace cgb
{
	using namespace cpplinq;
	using namespace cgb::cfg;

	owning_resource<graphics_pipeline_t> graphics_pipeline_t::create(graphics_pipeline_config _Config, cgb::context_specific_function<void(graphics_pipeline_t&)> _AlterConfigBeforeCreation)
	{
		graphics_pipeline_t result;
		result.mTracker.setTrackee(result);
		return result;
	}


}
