module Summary = {
  [@react.component]
  let make = (~summary: DataModel.summary) => {
    <p className="lead mb-5"> {ReasonReact.string(summary.content)} </p>;
  };
};

module Banner = {
  [@react.component]
  let make = (~name: DataModel.name, ~headline: string, ~location: string) => {
    <div>
      <h1 className="mb-0">
        {ReasonReact.string(name.firstName ++ " " ++ name.middleName)}
        <span className="text-primary">
          {ReasonReact.string(" " ++ name.lastName)}
        </span>
      </h1>
      <div className="subheading mb-5">
        {ReasonReact.string(headline ++ " - " ++ location ++ " - ")}
        <a href="mailto:name@email.com">
          {ReasonReact.string("name@email.com")}
        </a>
      </div>
    </div>;
  };
};

module Work = {
  [@react.component]
  let make = (~work: list(DataModel.employment)) => {
    <div>
      <h2 className="mb-5"> {React.string("Experience")} </h2>
List.map( (w: DataModel.employment) => {
      <div
        className="resume-item d-flex flex-column flex-md-row justify-content-between mb-5">
        <div className="resume-content">
          <h3 className="mb-0"> {React.string(w.position} </h3>
          <div className="subheading mb-3"> {React.string("enfore")} </div>
          <p> {React.string("doing stuff")} </p>
        </div>
        <div className="resume-date text-md-right">
          <span className="text-primary">
            {React.string("September 2009 - Present")}
          </span>
        </div>
      </div>
}, work)
    </div>;
  };
};

module Socials = {
  [@react.component]
  let make = (~socials: list(string)) => {
    print_endline(Js.String.make(socials));
    <div className="social-icons">
      <a href="#"> <i className="fab fa-linkedin-in" /> </a>
      <a href="#"> <i className="fab fa-xing" /> </a>
      <a href="#"> <i className="fab fa-github" /> </a>
      <a href="#"> <i className="fab fa-gitter" /> </a>
      <a href="#"> <i className="fab fa-twitter" /> </a>
    </div>;
  };
};

module Education = {
  [@react.component]
  let make = (~educations: list(DataModel.education)) => {
    <div> {ReasonReact.string(Js.String.make(educations))} </div>;
  };
};

module ListItem = {
  [@react.component]
  let make = (~displayString: string) => {
    <li className="nav-item">
      <a
        className="nav-link js-scroll-trigger active"
        href={"#" ++ String.lowercase(displayString)}>
        {ReasonReact.string(displayString)}
      </a>
    </li>;
  };
};

module Navigation = {
  [@react.component]
  let make = (~data: DataModel.resumeData) => {
    <nav
      className="navbar navbar-expand-lg navbar-dark bg-primary fixed-top"
      id="sideNav">
      <a className="navbar-brand js-scroll-trigger" href="#page-top">
        <span className="d-block d-lg-none">
          // for what is this?
           {ReasonReact.string(data.name.lastName)} </span>
        <span className="d-none d-lg-block">
          <img
            className="img-fluid img-profile rounded-circle mx-auto mb-2"
            src="../profile.jpg"
            alt=""
          />
        </span>
      </a>
      <button
        className="navbar-toggler"
        type_="button"
        // dataToggle="collapse"
        // dataTarget="#navbarSupportedContent"
        ariaControls="navbarSupportedContent"
        // ariaExpanded="false"
        ariaLabel="Toggle navigation">
        <span className="navbar-toggler-icon" />
      </button>
      <div className="collapse navbar-collapse" id="navbarSupportedContent">
        <ul className="navbar-nav">
          <ListItem displayString="About" />
          <ListItem displayString="Experience" />
          <ListItem displayString="Education" />
          <ListItem displayString="Skills" />
          <ListItem displayString="Interests" />
          <ListItem displayString="Awards" />
        </ul>
      </div>
    </nav>;
  };
};

[@react.component]
let make = (~data: DataModel.resumeData, ~filterFunc: 'a => option('a)) => {
  ignore(
    filterFunc(data)
    ->Belt.Option.map(x => x.headline)
    ->Belt.Option.map(print_endline),
  );
  <div>
    <Navigation data />
    <section
      className="resume-section p-3 p-lg-5 d-flex align-items-center"
      id="about">
      <div className="w-100">
        <Banner
          name={data.name}
          headline={data.headline}
          location={data.location}
        />
        <Summary summary={data.summary} />
        <Socials socials={data.socials} />
      </div>
    </section>
    <hr className="m-0" />
    <section
      className="resume-section p-3 p-lg-5 d-flex align-items-center"
      id="experience">
      <div className="w-100"> <Work work={data.work} /> </div>
    </section>
    <hr className="m-0" />
    <section
      className="resume-section p-3 p-lg-5 d-flex align-items-center"
      id="education">
      <div className="w-100"> <Education educations={data.education} /> </div>
    </section>
  </div>;
};